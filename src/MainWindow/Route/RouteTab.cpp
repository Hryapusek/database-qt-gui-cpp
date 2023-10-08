#include "RouteTab.hpp"
#include "Database/DbApi.hpp"

#include "AddRouteDialog.hpp"
#include "RemoveRouteDialog.hpp"


#include <optional>
#include <odb/exceptions.hxx>
#include <QMessageBox>

namespace
{
  Route routeFromString(QString name, std::optional< std::string > &err)
  {
    Route route;
    route.name(name.toStdString());
    err = std::nullopt;
    return route;
  }
}

RouteTab::RouteTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &RouteTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &RouteTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &RouteTab::removeBtnClicked);
  QObject::connect(table_, &QTableWidget::itemChanged, this, &RouteTab::itemChanged);
}

void RouteTab::itemChanged(QTableWidgetItem *item)
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
  assert(("ID value should be a correct num", ok == true));
  QString nameStr;
  if (table_->item(item->row(), Column::NAME))
    nameStr = table_->item(item->row(), Column::NAME)->text();
  std::optional< std::string > err;
  Route route = routeFromString(std::move(nameStr), err);
  route.id(id);
  if (err)
  {
    QMessageBox::critical(table_, "Error", QString::fromStdString(*err), QMessageBox::Close);
    restoreText();
  }
  try
  {
    DbApi::updateRoute(std::move(route));
    updateCache();
  }
  catch (const odb::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    restoreText();
  }
}

void RouteTab::updateCache()
{
  cachedItems_.clear();
  for (int row = 0; row < table_->rowCount(); ++row)
    for (int col = 0; col < table_->columnCount(); ++col)
    {
      if (table_->item(row, col))
      {
        cachedItems_[row][col] = { table_->item(row, col)->text() };
      }
    }
}

void RouteTab::refreshTable()
{
  decltype(DbApi::getRoutes()) routes;
  try
  {
    routes = DbApi::getRoutes();
  }
  catch (const odb::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    return;
  }
  auto refreshRAII = startRefresh();
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
  updateCache();
}

void RouteTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
  updateCache();
}

RouteTab::~RouteTab()
{ }

void RouteTab::removeBtnClicked()
{
  if (!removeRouteDialog_)
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
  if (!addRouteDialog_)
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
      return addBtnClicked();
    }
    emit refreshTablesSig();
  }
  return;
}
