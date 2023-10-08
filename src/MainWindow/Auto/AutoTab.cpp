#include "AutoTab.hpp"
#include "Database/DbApi.hpp"

#include "AddAutoDialog.hpp"
#include "RemoveAutoDialog.hpp"

#include <iostream>

#include <QMessageBox>
#include <odb/exceptions.hxx>

AutoTab::AutoTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &AutoTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &AutoTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &AutoTab::removeBtnClicked);
}

void AutoTab::refreshTable()
{
  auto autos = DbApi::getAutos();
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
}

void AutoTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
}

AutoTab::~AutoTab()
{ }

void AutoTab::removeBtnClicked()
{
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
  addAutoDialog_ = std::make_unique< AddAutoDialog >(table_);
  auto result = addAutoDialog_->exec();
  if (result == QDialog::Accepted)
  {
    auto num = addAutoDialog_->getNum().toStdString();
    auto color = addAutoDialog_->getColor().toStdString();
    auto mark = addAutoDialog_->getMark().toStdString();
    bool ok = true;
    auto personId = addAutoDialog_->getPersonId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given person ID to number", QMessageBox::Close);
      return;
    }
    try
    {
      DbApi::addAuto(Auto(0, std::move(num), std::move(color), std::move(mark), DbApi::getPerson(personId)));
      QMessageBox::information(table_, "Success!", "Auto added", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
      return;
    }
    emit refreshTablesSig();
  }
  return;
}
