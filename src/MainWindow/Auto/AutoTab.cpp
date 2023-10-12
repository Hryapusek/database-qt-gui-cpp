#include "AutoTab.hpp"

#include "Database/DbApi.hpp"

#include "AddAutoDialog.hpp"
#include "RemoveAutoDialog.hpp"

#include <odb/exceptions.hxx>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QGuiApplication>
#include <QClipboard>
#include <ranges>
#include <optional>
#include <QShortcut>

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
  table_->setContextMenuPolicy(Qt::CustomContextMenu);
  QObject::connect(table_, &QTableWidget::customContextMenuRequested, this, &AutoTab::menu);

  copy_ = new QAction("Copy", table_);
  copy_->setShortcut(Qt::Key_Copy);
  copy_->setEnabled(false);
  copy_->setShortcutVisibleInContextMenu(false);
  QObject::connect(copy_, &QAction::triggered, this, &AutoTab::copy);

  copyShortcut_ = new QShortcut(QKeySequence::Copy, table_, this, &AutoTab::copy);

  del_ = new QAction("Del", table_);
  del_->setShortcut(Qt::Key_Delete);
  del_->setEnabled(false);
  del_->setShortcutVisibleInContextMenu(false);
  QObject::connect(del_, &QAction::triggered, this, &AutoTab::del);

  delShortcut_ = new QShortcut(QKeySequence::Delete, table_, this, &AutoTab::del);

  cut_ = new QAction("Cut", table_);
  cut_->setShortcut(Qt::Key_Cut);
  cut_->setEnabled(false);
  cut_->setShortcutVisibleInContextMenu(false);
  QObject::connect(cut_, &QAction::triggered, this, &AutoTab::cut);

  cutShortcut_ = new QShortcut(QKeySequence::Cut, table_, this, &AutoTab::cut);

  delRows_ = new QAction("Del Rows", table_);
  delRows_->setEnabled(false);
  QObject::connect(delRows_, &QAction::triggered, this, &AutoTab::delRows);

  table_->addAction(copy_);
  table_->addAction(del_);
  table_->addAction(cut_);
  table_->addAction(delRows_);

  menu_ = std::make_unique< QMenu >(table_);
  menu_->addAction(copy_);
  menu_->addAction(del_);
  menu_->addAction(cut_);
  menu_->addAction(delRows_);
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

void AutoTab::menu(const QPoint &pos)
{
  checkCopyEnabled();
  checkDelEnabled();
  checkCutEnabled();
  checkDelRowsEnabled();
  menu_->exec(QCursor::pos());
}

void AutoTab::copy()
{
  if (!isCopyEnabled())
    return;
  QString str;
  auto item = table_->currentItem();
  if (item)
    str = item->text();
  QGuiApplication::clipboard()->setText(str);
}

void AutoTab::del()
{
  if (!isDelEnabled())
    return;
  auto selectedRanges = table_->selectedRanges();
  for (const auto &range : selectedRanges)
  {
    for (int col = range.leftColumn(); col <= range.rightColumn(); ++col)
    {
      if (col == Column::ID)
        continue;
      for (int row = range.topRow(); row <= range.bottomRow(); ++row)
      {
        if (!table_->item(row, col))
          continue;
        table_->item(row, col)->setText("");
      }
    }
  }
}

void AutoTab::cut()
{
  if (!isCutEnabled())
    return;
  copy();
  del();
}

void AutoTab::delRows()
{
  std::map< Row_t, Id_t > rowIdMap;
  auto selectedRanges = table_->selectedRanges();
  for (const auto &range : selectedRanges)
  {
    for (Row_t row = range.bottomRow(); row >= range.topRow(); --row)
    {
      bool ok = true;
      assert(("ID Column must be not null", table_->item(row, Column::ID)));
      Id_t id = table_->item(row, Column::ID)->text().toLong(&ok);
      assert(("ID Column must contain valid number", ok));
      rowIdMap.insert({ row, id });
    }
  }
  for (const auto [row, id] : rowIdMap | std::views::reverse)
  {
    try
    {
      DbApi::removeAuto(id);
      table_->removeRow(row);
      cachedItems_.erase(row);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::warning(table_, "Skipping person",
        QString::fromStdString("Can not delete person with id " + std::to_string(id)) + ". " + e.what(),
        QMessageBox::Close);
    }
  }
}

void AutoTab::checkCopyEnabled()
{
  copy_->setEnabled(isCopyEnabled());
}

bool AutoTab::isCopyEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  if (selectedRanges.size() != 1 || selectedRanges[0].columnCount() * selectedRanges[0].rowCount() != 1)
    return false;
  else
    return true;
}

void AutoTab::checkDelEnabled()
{
  del_->setEnabled(isDelEnabled() && !isDelRowsEnabled());
}

bool AutoTab::isDelEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  return !selectedRanges.empty();
}

void AutoTab::checkCutEnabled()
{
  cut_->setEnabled(isCutEnabled());
}

bool AutoTab::isCutEnabled()
{
  return isCopyEnabled() && isDelEnabled();
}

void AutoTab::checkDelRowsEnabled()
{
  delRows_->setEnabled(isDelRowsEnabled());
}

bool AutoTab::isDelRowsEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool allRows = true;
  for (const auto &range : selectedRanges)
  {
    allRows = allRows && range.leftColumn() == Column::ID && range.rightColumn() == Column::PERSON_ID;
  }
  return allRows;
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

AutoTab::~AutoTab()
{ }
