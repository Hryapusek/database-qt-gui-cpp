#include "AutoTab.hpp"
#include "Database/DbApi.hpp"

AutoTab::AutoTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{ 
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &AutoTab::refreshTablesSig);
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
