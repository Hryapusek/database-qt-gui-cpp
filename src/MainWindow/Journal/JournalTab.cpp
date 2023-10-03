#include "JournalTab.hpp"
#include "Database/DbApi.hpp"

#include "MainWindow/Utils.hpp"

#include "AddJournalRowDialog.hpp"
#include "RemoveJournalRowDialog.hpp"

#include <iostream>

JournalTab::JournalTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{ 
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &JournalTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &JournalTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &JournalTab::removeBtnClicked);
}

JournalTab::~JournalTab()
{
}

void JournalTab::refreshTable()
{
  auto journalRows = DbApi::getJournalRows();
  clearTable();
  for (const auto &journalRow : journalRows)
  {
    auto curRow = table_->rowCount();
    table_->insertRow(table_->rowCount());
    auto idStr = QString::fromStdString(std::to_string(journalRow.getId()));
    auto autoIdStr = QString::fromStdString(std::to_string(journalRow.getAutoId()));
    auto routeIdStr = QString::fromStdString(std::to_string(journalRow.getRouteId()));
    table_->setItem(curRow, Column::ID, new QTableWidgetItem(idStr));
    if (journalRow.getTimeOut())
    {
      auto timeOut = QString::fromStdString(StringUtils::to_string(*journalRow.getTimeOut()));
      table_->setItem(curRow, Column::TIME_OUT, new QTableWidgetItem(timeOut));
    }
    if (journalRow.getTimeIn())
    {
      auto timeIn = QString::fromStdString(StringUtils::to_string(*journalRow.getTimeIn()));
      table_->setItem(curRow, Column::TIME_IN, new QTableWidgetItem(timeIn));
    }
    table_->setItem(curRow, Column::AUTO_ID, new QTableWidgetItem(autoIdStr));
    table_->setItem(curRow, Column::ROUTE_ID, new QTableWidgetItem(routeIdStr));
  }
}

void JournalTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
  {
    table_->removeRow(row);
  }
}

void JournalTab::removeBtnClicked()
{
  removeJournalRowDialog_ = std::make_unique<RemoveJournalRowDialog>(table_);
  auto result = removeJournalRowDialog_->exec();
  // TODO remove person from database
  // Try-Catch if person does not exist?
  if (result == QDialog::Accepted)
    std::cout << "Id " << removeJournalRowDialog_->getId().toStdString() << '\n';
  else
    std::cout << "Result is rejected\n";
}

void JournalTab::addBtnClicked()
{
  addJournalRowDialog_ = std::make_unique<AddJournalRowDialog>(table_);
  auto result = addJournalRowDialog_->exec();
  // TODO add person to database
  // Try-Catch if person with id already exist?
  if (result == QDialog::Accepted)
    std::cout << "Id " << addJournalRowDialog_->getId().toStdString() << '\n';
  else
    std::cout << "Result is rejected\n";
}
