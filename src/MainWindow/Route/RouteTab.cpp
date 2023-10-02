#include "RouteTab.hpp"
#include "Database/DbApi.hpp"

#include "AddRouteDialog.hpp"
#include "RemoveRouteDialog.hpp"

#include <iostream>

RouteTab::RouteTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{ 
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &RouteTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &RouteTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &RouteTab::removeBtnClicked);
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

RouteTab::~RouteTab()
{
}

void RouteTab::removeBtnClicked()
{
  removeRouteDialog = std::make_unique<RemoveRouteDialog>(table_);
  auto result = removeRouteDialog->exec();
  // TODO remove person from database
  // Try-Catch if person does not exist?
  if (result == QDialog::Accepted)
    std::cout << "Id " << removeRouteDialog->getId().toStdString() << '\n';
  else
    std::cout << "Result is rejected\n";
}

void RouteTab::addBtnClicked()
{
  addRouteDialog = std::make_unique<AddRouteDialog>(table_);
  auto result = addRouteDialog->exec();
  // TODO add person to database
  // Try-Catch if person with id already exist?
  if (result == QDialog::Accepted)
  {
    std::cout << "Id " << addRouteDialog->getId().toStdString() << '\n';
    std::cout << "Num " << addRouteDialog->getName().toStdString() << '\n';
  }
  else
    std::cout << "Result is rejected\n";
}
