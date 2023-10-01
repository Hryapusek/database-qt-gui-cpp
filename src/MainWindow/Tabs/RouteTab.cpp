#include "RouteTab.hpp"
#include "Database/DbApi.hpp"

RouteTab::RouteTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{ 
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &RouteTab::refreshTablesSig);
}

void RouteTab::refreshTable()
{
  auto routes = DbApi::getRoutes();
  clearTable();
  for (const auto &route : routes)
  {
    auto curRow = table_->rowCount();
    table_->insertRow(table_->rowCount());
    auto idStr = QString::fromStdString(std::to_string(route.getId()));
    auto name = QString::fromStdString(route.getName());
    table_->setItem(curRow, Column::ID, new QTableWidgetItem(idStr));
    table_->setItem(curRow, Column::NAME, new QTableWidgetItem(name));
  }
}

void RouteTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
  {
    table_->removeRow(row);
  }
}
