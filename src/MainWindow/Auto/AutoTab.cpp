#include "AutoTab.hpp"
#include "Database/DbApi.hpp"

#include "AddAutoDialog.hpp"
#include "RemoveAutoDialog.hpp"

#include <QMessageBox>
#include <odb/exceptions.hxx>
#include <optional>

namespace
{
  Auto autoFromString(QString numStr, QString colorStr, QString markStr, QString personIdStr, std::optional< std::string > &err)
  {
    Auto autoObj;
    auto num = numStr.toStdString();
    auto color = colorStr.toStdString();
    auto mark = markStr.toStdString();
    bool ok = true;
    auto personId = personIdStr.toLong(&ok);
    if (!ok)
    {
      err = "Can not convert given person ID to number";
      return autoObj;
    }
    autoObj.num(std::move(num));
    autoObj.color(std::move(color));
    autoObj.mark(std::move(mark));
    try
    {
      autoObj.person(DbApi::getPerson(personId));
    } catch (const odb::exception &e)
    {
      err = e.what();
      return autoObj;
    }
    return autoObj;
  }
}

AutoTab::AutoTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &AutoTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &AutoTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &AutoTab::removeBtnClicked);
  QObject::connect(table_, &QTableWidget::itemChanged, this, &AutoTab::itemChanged);
}

void AutoTab::itemChanged(QTableWidgetItem *item)
{
  if (refreshing_)
    return;
  assert(("Item must be not null", item));
  auto &currentItemMeta = cachedItems_[item->row()][item->column()];
  if (currentItemMeta.text == item->text())
    return;
  auto restoreText =
    [&currentItemMeta, item]() {
      item->setText(currentItemMeta.text);
    };
  assert(("Item must be not null", table_->item(item->row(), Column::ID)));

  bool ok = true;
  auto id = table_->item(item->row(), Column::ID)->text().toLong(&ok);
  assert(("ID column must contain a valid long int", ok == true));

  QString num;
  if (table_->item(item->row(), Column::NUM))
    num = table_->item(item->row(), Column::NUM)->text();

  QString color;
  if (table_->item(item->row(), Column::COLOR))
    color = table_->item(item->row(), Column::COLOR)->text();

  QString mark;
  if (table_->item(item->row(), Column::MARK))
    mark = table_->item(item->row(), Column::MARK)->text();

  QString personId;
  if (table_->item(item->row(), Column::PERSON_ID))
    personId = table_->item(item->row(), Column::PERSON_ID)->text();

  std::optional< std::string > err;
  auto autoObj = autoFromString(std::move(num), std::move(color), std::move(mark), std::move(personId), err);
  autoObj.id(id);
  if (err)
  {
    QMessageBox::critical(table_, "Error", QString::fromStdString(*err), QMessageBox::Close);
    restoreText();
    return;
  }

  try
  {
    DbApi::updateAuto(std::move(autoObj));
    currentItemMeta.text = item->text();
  }
  catch (const odb::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    restoreText();
  }
}

void AutoTab::refreshTable()
{
  decltype(DbApi::getAutos()) autos;
  try
  {
    autos = DbApi::getAutos();
  }
  catch (const odb::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    return;
  }
  auto refreshRAII = startRefresh();
  clearTable();
  for (const auto &autoObj : autos)
  {
    auto curRow = table_->rowCount();
    table_->insertRow(table_->rowCount());
    table_->setVerticalHeaderItem(curRow, new QTableWidgetItem(""));
    auto idStr = QString::fromStdString(std::to_string(autoObj.id()));
    auto idItem = new QTableWidgetItem(idStr);
    idItem->setFlags(idItem->flags() &  ~Qt::ItemIsEditable);
    table_->setItem(curRow, Column::ID, idItem);
    if (autoObj.num())
    {
      auto num = QString::fromStdString(autoObj.num().get());
      table_->setItem(curRow, Column::NUM, new QTableWidgetItem(num));
    }
    if (autoObj.color())
    {
      auto color = QString::fromStdString(autoObj.color().get());
      table_->setItem(curRow, Column::COLOR, new QTableWidgetItem(color));
    }
    if (autoObj.mark())
    {
      auto mark = QString::fromStdString(autoObj.mark().get());
      table_->setItem(curRow, Column::MARK, new QTableWidgetItem(mark));
    }
    auto personIdStr = QString::fromStdString(std::to_string(autoObj.person()->id()));
    table_->setItem(curRow, Column::PERSON_ID, new QTableWidgetItem(personIdStr));
  }
  updateCache();
}

void AutoTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
  updateCache();
}

AutoTab::~AutoTab()
{ }

void AutoTab::removeBtnClicked()
{
  if (!removeAutoDialog_)
    removeAutoDialog_ = std::make_unique< RemoveAutoDialog >(table_);
  auto result = removeAutoDialog_->exec();
  if (result == QDialog::Accepted)
  {
    bool ok = true;
    Auto::Id_t id = removeAutoDialog_->getId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given ID to number", QMessageBox::Close);
      return;
    }
    try
    {
      DbApi::removeAuto(id);
      QMessageBox::information(table_, "Success!", "Auto removed", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    }
    emit refreshTablesSig();
  }
  return;
}

void AutoTab::addBtnClicked()
{
  if (!addAutoDialog_)
    addAutoDialog_ = std::make_unique< AddAutoDialog >(table_);
  auto result = addAutoDialog_->exec();
  if (result == QDialog::Accepted)
  {
    std::optional< std::string > err;
    Auto autoObj = autoFromString(addAutoDialog_->getNum(),
      addAutoDialog_->getColor(),
      addAutoDialog_->getMark(),
      addAutoDialog_->getPersonId(),
      err);
    if (err)
    {
      QMessageBox::critical(table_, "Error", QString::fromStdString(*err), QMessageBox::Close);
      return addBtnClicked();
    }
    try
    {
      DbApi::addAuto(autoObj);
      QMessageBox::information(table_, "Success!", "Auto added", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
      return addBtnClicked();
    }
    emit refreshTablesSig();
  }
  return;
}

void AutoTab::updateCache()
{
  cachedItems_.clear();
  for (int row = 0; row < table_->rowCount(); ++row)
    for (int col = 0; col < table_->columnCount(); ++col)
    {
      if (table_->item(row, col))
      {
        cachedItems_[row][col] = ItemMeta{ table_->item(row, col)->text() };
      }
    }
}

