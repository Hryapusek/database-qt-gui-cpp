#include "AutoTab.hpp"
#include "Database/DbApi.hpp"

#include "AddAutoDialog.hpp"
#include "RemoveAutoDialog.hpp"

#include <iostream>

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
    auto idStr = QString::fromStdString(std::to_string(autoObj.getId()));
    auto num = QString::fromStdString(autoObj.getNum());
    auto color = QString::fromStdString(autoObj.getColor());
    auto mark = QString::fromStdString(autoObj.getMark());
    auto personIdStr = QString::fromStdString(std::to_string(autoObj.getPersonId()));
    table_->setItem(curRow, Column::ID, new QTableWidgetItem(idStr));
    table_->setItem(curRow, Column::NUM, new QTableWidgetItem(num));
    table_->setItem(curRow, Column::COLOR, new QTableWidgetItem(color));
    table_->setItem(curRow, Column::MARK, new QTableWidgetItem(mark));
    table_->setItem(curRow, Column::PERSON_ID, new QTableWidgetItem(personIdStr));
  }
}

void AutoTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
  {
    table_->removeRow(row);
  }
}

AutoTab::~AutoTab()
{
}

void AutoTab::removeBtnClicked()
{
  removeAutoDialog = std::make_unique<RemoveAutoDialog>(table_);
  auto result = removeAutoDialog->exec();
  // TODO remove person from database
  // Try-Catch if person does not exist?
  if (result == QDialog::Accepted)
    std::cout << "Id " << removeAutoDialog->getId().toStdString() << '\n';
  else
    std::cout << "Result is rejected\n";
}

void AutoTab::addBtnClicked()
{
  addAutoDialog = std::make_unique<AddAutoDialog>(table_);
  auto result = addAutoDialog->exec();
  // TODO add person to database
  // Try-Catch if person with id already exist?
  if (result == QDialog::Accepted)
  {
    std::cout << "Id " << addAutoDialog->getId().toStdString() << '\n';
    std::cout << "Num " << addAutoDialog->getNum().toStdString() << '\n';
  }
  else
    std::cout << "Result is rejected\n";
}
