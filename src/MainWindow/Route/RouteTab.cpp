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
#include <QShortcut>

#ifndef _NDEBUG
  #include <iostream>
#endif

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
  copy_->setEnabled(false);
  QObject::connect(copy_, &QAction::triggered, this, &RouteTab::copy);

  copyShortcut_ = new QShortcut(QKeySequence::Copy, table_, this, &RouteTab::copy);

  paste_ = new QAction("Paste", table_);
  paste_->setEnabled(false);
  QObject::connect(paste_, &QAction::triggered, this, &RouteTab::paste);

  pasteShortcut_ = new QShortcut(QKeySequence::Paste, table_, this, &RouteTab::paste);

  del_ = new QAction("Del", table_);
  del_->setEnabled(false);
  QObject::connect(del_, &QAction::triggered, this, &RouteTab::del);

  delShortcut_ = new QShortcut(QKeySequence::Delete, table_, this, &RouteTab::del);

  cut_ = new QAction("Cut", table_);
  cut_->setEnabled(false);
  QObject::connect(cut_, &QAction::triggered, this, &RouteTab::cut);

  cutShortcut_ = new QShortcut(QKeySequence::Cut, table_, this, &RouteTab::cut);

  delRows_ = new QAction("Del Rows", table_);
  delRows_->setEnabled(false);
  QObject::connect(delRows_, &QAction::triggered, this, &RouteTab::delRows);

  info_ = new QAction("Info", table_);
  info_->setEnabled(false);
  QObject::connect(info_, &QAction::triggered, this, &RouteTab::info);

  infoShortcut_ = new QShortcut(QKeySequence::fromString("CTRL+I"), table_, this, &RouteTab::info);

  menu_ = std::make_unique< QMenu >(table_);
  menu_->addAction(cut_);
  menu_->addAction(copy_);
  menu_->addAction(paste_);
  menu_->addAction(del_);
  menu_->addSeparator();
  menu_->addAction(delRows_);
  menu_->addSeparator();
  menu_->addAction(info_);
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
  checkCutEnabled();
  checkCopyEnabled();
  checkPasteEnabled();
  checkDelEnabled();
  checkDelRowsEnabled();
  checkInfoEnabled();
  menu_->exec(QCursor::pos());
}

void RouteTab::copy()
{
  if (!isCopyEnabled())
    return;
  QString str;
  auto item = table_->currentItem();
  if (item)
    str = item->text();
  QGuiApplication::clipboard()->setText(str);
}

void RouteTab::paste()
{
  if (!isPasteEnabled())
    return;
  auto item = table_->currentItem();
  if (item)
    table_->setItem(item->row(), item->column(), new QTableWidgetItem(QGuiApplication::clipboard()->text()));
}

void RouteTab::del()
{
  if (!isDelEnabled())
    return;
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
  if (!isCutEnabled())
    return;
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

void RouteTab::info()
{
  if (!isInfoEnabled())
    return;
  auto item = table_->item(table_->currentItem()->row(), Column::ID);
  assert(("ID must be not null", item != nullptr));
  bool ok = true;
  auto routeId = item->text().toLong(&ok);
  assert(("ID must be a valid number", ok));
  std::optional< time_t > record;
  Id_t recordAutoId = 0;
  long nAutoInRoute = 0;
  decltype(DbApi::getJournalRows()) journalRows;
  try
  {
    journalRows = DbApi::getJournalRows();
  }
  catch (const std::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    return;
  }
  for (const auto &journalRow : DbApi::getJournalRows())
  {
    if (journalRow.route()->id() != routeId)
      continue;
    if (journalRow.timeOut() && !journalRow.timeIn())
    {
      ++nAutoInRoute;
    }
    else if (journalRow.timeOut() && journalRow.timeIn())
    {
      auto timeDiff = *journalRow.timeIn() - *journalRow.timeOut();
      if (!record || timeDiff < *record)
      {
        record = *journalRow.timeIn() - *journalRow.timeOut();
        recordAutoId = journalRow.autoObj()->id();
      }
    }
  }
  std::string idStr = "Id: " + std::to_string(routeId);
  std::string recordStr = "Record: ";
  if (record)
  {
    auto recordInSeconds = *record / 1000000l;
    auto days = recordInSeconds / 60 / 60 / 24;
    auto hours = recordInSeconds / 60 / 60 % 24;
    auto minutes = recordInSeconds / 60 % 60;
    auto seconds = recordInSeconds % 60;
    if (days)
      recordStr += std::to_string(days) + " days, ";
    if (hours)
      recordStr += std::to_string(hours) + " hours, ";
    if (minutes)
      recordStr += std::to_string(minutes) + " minutes, ";
    if (seconds)
      recordStr += std::to_string(seconds) + " seconds, ";
    recordStr.pop_back();
    recordStr.pop_back();
  }
  else
    recordStr += "None";
  auto autoInRouteStr = "Auto in route: " + std::to_string(nAutoInRoute);
  QString info = QString::fromStdString(idStr + "\n" + recordStr + "\n" + autoInRouteStr);
  QMessageBox::information(table_, "Route Info", info, QMessageBox::Close);
}

void RouteTab::checkCopyEnabled()
{
  copy_->setEnabled(isCopyEnabled());
}

bool RouteTab::isCopyEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  if (selectedRanges.size() != 1 || selectedRanges[0].columnCount() * selectedRanges[0].rowCount() != 1)
    return false;
  else
    return true;
}

void RouteTab::checkPasteEnabled()
{
  paste_->setEnabled(isPasteEnabled());
}

bool RouteTab::isPasteEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool enabled = selectedRanges.size() == 1 &&
                 selectedRanges[0].columnCount() * selectedRanges[0].rowCount() == 1 &&
                 selectedRanges[0].leftColumn() != Column::ID;
  return enabled;
}

void RouteTab::checkDelEnabled()
{
  del_->setEnabled(isDelEnabled() && !isDelRowsEnabled());
}

bool RouteTab::isDelEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  return !selectedRanges.empty();
}

void RouteTab::checkCutEnabled()
{
  cut_->setEnabled(isCutEnabled());
}

bool RouteTab::isCutEnabled()
{
  return isCopyEnabled() && isDelEnabled();
}

void RouteTab::checkDelRowsEnabled()
{
  delRows_->setEnabled(isDelRowsEnabled());
}

bool RouteTab::isDelRowsEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool allRows = true;
  for (const auto &range : selectedRanges)
  {
    allRows = allRows && range.leftColumn() == Column::ID && range.rightColumn() == Column::NAME;
  }
  return allRows;
}

void RouteTab::checkInfoEnabled()
{
  info_->setEnabled(isInfoEnabled());
}

bool RouteTab::isInfoEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool isSelectionFromOneRow = selectedRanges.size() == 1 and selectedRanges[0].rowCount() == 1;
  return isSelectionFromOneRow;
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
