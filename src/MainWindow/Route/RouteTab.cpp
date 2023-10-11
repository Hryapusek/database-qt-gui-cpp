#include "RouteTab.hpp"
#include "Database/DbApi.hpp"

#include "AddRouteDialog.hpp"
#include "RemoveRouteDialog.hpp"

#include <odb/exceptions.hxx>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QGuiApplication>
#include <QClipboard>
#include <ranges>

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
  table_->setContextMenuPolicy(Qt::CustomContextMenu);
  QObject::connect(table_, &QTableWidget::customContextMenuRequested, this, &RouteTab::menu);

  copy_ = new QAction("Copy", table_);
  copy_->setShortcut(Qt::Key_Copy);
  copy_->setEnabled(false);
  copy_->setShortcutVisibleInContextMenu(false);
  QObject::connect(copy_, &QAction::triggered, this, &RouteTab::copy);

  del_ = new QAction("Del", table_);
  del_->setShortcut(Qt::Key_Delete);
  del_->setEnabled(false);
  del_->setShortcutVisibleInContextMenu(false);
  QObject::connect(del_, &QAction::triggered, this, &RouteTab::del);

  cut_ = new QAction("Cut", table_);
  cut_->setShortcut(Qt::Key_Cut);
  cut_->setEnabled(false);
  cut_->setShortcutVisibleInContextMenu(false);
  QObject::connect(cut_, &QAction::triggered, this, &RouteTab::cut);

  delRows_ = new QAction("Del Rows", table_);
  delRows_->setEnabled(false);
  QObject::connect(delRows_, &QAction::triggered, this, &RouteTab::delRows);

  menu_ = std::make_unique< QMenu >(table_);
  menu_->addAction(copy_);
  menu_->addAction(del_);
  menu_->addAction(cut_);
  menu_->addAction(delRows_);

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

void RouteTab::menu(const QPoint &pos)
{
  checkCopyEnabled();
  checkDelEnabled();
  checkCutEnabled();
  checkDelRowsEnabled();
  menu_->exec(QCursor::pos());
}

void RouteTab::copy()
{
  QString str;
  auto item = table_->currentItem();
  if (item)
    str = item->text();
  QGuiApplication::clipboard()->setText(str);
}

void RouteTab::del()
{
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

void RouteTab::cut()
{
  copy();
  del();
}

void RouteTab::delRows()
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
      DbApi::removeRoute(id);
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

void RouteTab::checkCopyEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  if (selectedRanges.size() != 1 || selectedRanges[0].columnCount() * selectedRanges[0].rowCount() != 1)
    copy_->setEnabled(false);
  else
    copy_->setEnabled(true);
}

void RouteTab::checkDelEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  del_->setEnabled(!selectedRanges.empty());
}

void RouteTab::checkCutEnabled()
{
  cut_->setEnabled(copy_->isEnabled());
}

void RouteTab::checkDelRowsEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool allRows = true;
  for (const auto &range : selectedRanges)
  {
    allRows = allRows && range.leftColumn() == Column::ID && range.rightColumn() == Column::NAME;
  }
  delRows_->setEnabled(allRows);
  del_->setEnabled(!delRows_->isEnabled());
}

void RouteTab::updateCache()
{
  cachedItems_.clear();
  for (int row = 0; row < table_->rowCount(); ++row)
  {
    for (int col = 0; col < table_->columnCount(); ++col)
    {
      if (table_->item(row, col))
        cachedItems_[row][col] = { table_->item(row, col)->text() }
      ;
    }
  }
}

RouteTab::~RouteTab()
{ }
