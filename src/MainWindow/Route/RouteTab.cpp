#include "RouteTab.hpp"
#include "Database/DbApi.hpp"

#include "AddRouteDialog.hpp"
#include "RemoveRouteDialog.hpp"

#include <iostream>

#include <QMessageBox>
#include <odb/exceptions.hxx>

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
    table_->setVerticalHeaderItem(curRow, new QTableWidgetItem(""));
    auto idStr = QString::fromStdString(std::to_string(route.id()));
    auto idItem = new QTableWidgetItem(idStr);
    idItem->setFlags(idItem->flags() &  ~Qt::ItemIsEditable);
    table_->setItem(curRow, Column::ID, idItem);
    if (route.name())
    {
      auto name = QString::fromStdString(route.name().get());
      table_->setItem(curRow, Column::NAME, new QTableWidgetItem(name));
    }
  }
}

void RouteTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
}

RouteTab::~RouteTab()
{ }

void RouteTab::removeBtnClicked()
{
  removeRouteDialog_ = std::make_unique< RemoveRouteDialog >(table_);
  auto result = removeRouteDialog_->exec();
  if (result == QDialog::Accepted)
  {
    bool ok = true;
    Person::Id_t id = removeRouteDialog_->getId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given ID to number", QMessageBox::Close);
      return;
    }
    try
    {
      DbApi::removeRoute(id);
      QMessageBox::information(table_, "Success!", "Route removed", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    }
    emit refreshTablesSig();
  }
  return;
}

void RouteTab::addBtnClicked()
{
  addRouteDialog_ = std::make_unique< AddRouteDialog >(table_);
  auto result = addRouteDialog_->exec();
  if (result == QDialog::Accepted)
  {
    auto routeName = addRouteDialog_->getName().toStdString();
    try
    {
      DbApi::addRoute(Route(0, std::move(routeName)));
      QMessageBox::information(table_, "Success!", "Route added", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    }
    emit refreshTablesSig();
  }
  return;
}
