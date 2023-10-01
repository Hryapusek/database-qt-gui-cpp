#include "JournalTab.hpp"
#include "Database/DbApi.hpp"

#include "Utils.hpp"

JournalTab::JournalTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{ 
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &JournalTab::refreshTablesSig);
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
