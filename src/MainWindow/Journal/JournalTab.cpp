#include "JournalTab.hpp"

#include "Database/DbApi.hpp"

#include "MainWindow/Utils.hpp"

#include "AddJournalRowDialog.hpp"
#include "RemoveJournalRowDialog.hpp"

#include <odb/exceptions.hxx>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QGuiApplication>
#include <QClipboard>
#include <ranges>
#include <optional>
#include <QShortcut>

#ifndef _NDEBUG
  #include <iostream>
#endif

namespace
{
  JournalRow journalRowFromString(QString timeOutStr, QString timeInStr, QString autoIdStr, QString routeIdStr, std::optional< std::string > &err)
  {
    timeOutStr = std::move(timeOutStr).simplified();
    timeInStr = std::move(timeInStr).simplified();
    autoIdStr = std::move(autoIdStr).simplified();
    routeIdStr = std::move(routeIdStr).simplified();
    JournalRow journalRow;
    bool ok = true;
    odb::nullable< time_t > timeOut;
    if (timeOutStr.size())
    {
      timeOut = StringUtils::stringToMicrosecFrom2000(timeOutStr.toStdString(), &ok);
      if (!ok)
      {
        err = "Bad Time Out value. Time must be in D.M.Y H:M:S";
        return journalRow;
      }
    }
    odb::nullable< time_t > timeIn;
    if (timeInStr.size())
    {
      timeIn = StringUtils::stringToMicrosecFrom2000(timeInStr.toStdString(), &ok);
      if (!ok)
      {
        err = "Bad Time In value. Time must be in D.M.Y H:M:S";
        return journalRow;
      }
    }
    auto autoId = autoIdStr.toLong(&ok);
    if (!ok)
    {
      err = "Can not convert given auto ID to number";
      return journalRow;
    }
    auto routeId = routeIdStr.toLong(&ok);
    if (!ok)
    {
      err = "Can not convert given route ID to number";
      return journalRow;
    }
    journalRow.timeIn(timeIn);
    journalRow.timeOut(timeOut);
    try
    { journalRow.route(DbApi::getRoute(routeId)); }
    catch (const odb::object_not_persistent &e)
    {
      err = "Route was not found";
      return journalRow;
    }
    catch (const odb::exception &e)
    {
      err = e.what();
      return journalRow;
    }
    try
    { journalRow.autoObj(DbApi::getAuto(autoId)); }
    catch (const odb::object_not_persistent &e)
    {
      err = "Auto was not found";
      return journalRow;
    }
    catch (const odb::exception &e)
    {
      err = e.what();
      return journalRow;
    }

    err = std::nullopt;
    return journalRow;
  }
}

JournalTab::JournalTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &JournalTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &JournalTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &JournalTab::removeBtnClicked);
  QObject::connect(table_, &QTableWidget::itemChanged, this, &JournalTab::itemChanged);
  table_->setContextMenuPolicy(Qt::CustomContextMenu);
  QObject::connect(table_, &QTableWidget::customContextMenuRequested, this, &JournalTab::menu);

  copy_ = new QAction("Copy", table_);
  copy_->setEnabled(false);
  QObject::connect(copy_, &QAction::triggered, this, &JournalTab::copy);

  copyShortcut_ = new QShortcut(QKeySequence::Copy, table_, this, &JournalTab::copy);

  paste_ = new QAction("Paste", table_);
  paste_->setEnabled(false);
  QObject::connect(paste_, &QAction::triggered, this, &JournalTab::paste);

  pasteShortcut_ = new QShortcut(QKeySequence::Paste, table_, this, &JournalTab::paste);

  del_ = new QAction("Del", table_);
  del_->setEnabled(false);
  QObject::connect(del_, &QAction::triggered, this, &JournalTab::del);

  delShortcut_ = new QShortcut(QKeySequence::Delete, table_, this, &JournalTab::del);

  cut_ = new QAction("Cut", table_);
  cut_->setEnabled(false);
  QObject::connect(cut_, &QAction::triggered, this, &JournalTab::cut);

  cutShortcut_ = new QShortcut(QKeySequence::Cut, table_, this, &JournalTab::cut);

  delRows_ = new QAction("Del Rows", table_);
  delRows_->setEnabled(false);
  QObject::connect(delRows_, &QAction::triggered, this, &JournalTab::delRows);

  menu_ = std::make_unique< QMenu >(table_);
  menu_->addAction(cut_);
  menu_->addAction(copy_);
  menu_->addAction(paste_);
  menu_->addAction(del_);
  menu_->addSeparator();
  menu_->addAction(delRows_);
}

void JournalTab::refreshTable()
{
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
  auto refreshRAII = startRefresh();
  clearTable();
  for (const auto &journalRow : journalRows)
  {
    auto curRow = table_->rowCount();
    table_->insertRow(table_->rowCount());
    table_->setVerticalHeaderItem(curRow, new QTableWidgetItem(""));

    auto idStr = QString::fromStdString(std::to_string(journalRow.id()));
    auto idItem = new QTableWidgetItem(idStr);
    idItem->setFlags(idItem->flags() &  ~Qt::ItemIsEditable);
    table_->setItem(curRow, Column::ID, idItem);

    auto autoIdStr = QString::fromStdString(std::to_string(journalRow.autoObj()->id()));
    table_->setItem(curRow, Column::AUTO_ID, new QTableWidgetItem(autoIdStr));

    auto routeIdStr = QString::fromStdString(std::to_string(journalRow.route()->id()));
    table_->setItem(curRow, Column::ROUTE_ID, new QTableWidgetItem(routeIdStr));

    if (journalRow.timeOut())
    {
      auto timeOut = QString::fromStdString(StringUtils::timeMicrosecFrom2000ToString(*journalRow.timeOut()));
      table_->setItem(curRow, Column::TIME_OUT, new QTableWidgetItem(timeOut));
    }
    if (journalRow.timeIn())
    {
      auto timeIn = QString::fromStdString(StringUtils::timeMicrosecFrom2000ToString(*journalRow.timeIn()));
      table_->setItem(curRow, Column::TIME_IN, new QTableWidgetItem(timeIn));
    }
  }
  updateCache();
}

void JournalTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
  updateCache();
}

void JournalTab::removeBtnClicked()
{
  if (!removeJournalRowDialog_)
    removeJournalRowDialog_ = std::make_unique< RemoveJournalRowDialog >(table_);
  auto result = removeJournalRowDialog_->exec();
  if (result == QDialog::Accepted)
  {
    bool ok = true;
    JournalRow::Id_t id = removeJournalRowDialog_->getId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given ID to number", QMessageBox::Close);
      return;
    }
    try
    {
      DbApi::removeJournalRow(id);
      QMessageBox::information(table_, "Success!", "Journal Row removed", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    }
    emit refreshTablesSig();
  }
  return;
}

void JournalTab::addBtnClicked()
{
  if (!addJournalRowDialog_)
    addJournalRowDialog_ = std::make_unique< AddJournalRowDialog >(table_);
  auto result = addJournalRowDialog_->exec();
  bool ok = false;
  if (result == QDialog::Accepted)
  {
    std::optional< std::string > err;
    auto journalRow = journalRowFromString(
      addJournalRowDialog_->getTimeOut(),
      addJournalRowDialog_->getTimeIn(),
      addJournalRowDialog_->getAutoId(),
      addJournalRowDialog_->getRouteId(),
      err);
    if (err)
    {
      QMessageBox::critical(table_, "Error", QString::fromStdString(*err), QMessageBox::Close);
      return addBtnClicked();
    }
    try
    {
      DbApi::addJournalRow(journalRow);
      QMessageBox::information(table_, "Success!", "Journal row added", QMessageBox::Ok);
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

void JournalTab::itemChanged(QTableWidgetItem *item)
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
  assert(("ID column must contain a valid long int", ok == true));

  std::optional< std::string > err;
  QString timeOutStr;
  if (table_->item(item->row(), Column::TIME_OUT))
    timeOutStr = table_->item(item->row(), Column::TIME_OUT)->text();
  QString timeInStr;
  if (table_->item(item->row(), Column::TIME_IN))
    timeInStr = table_->item(item->row(), Column::TIME_IN)->text();
  QString autoIdStr;
  if (table_->item(item->row(), Column::AUTO_ID))
    autoIdStr = table_->item(item->row(), Column::AUTO_ID)->text();
  QString routeIdStr;
  if (table_->item(item->row(), Column::ROUTE_ID))
    routeIdStr = table_->item(item->row(), Column::ROUTE_ID)->text();
  auto journalRow = journalRowFromString(timeOutStr, timeInStr, autoIdStr, routeIdStr, err);
  journalRow.id(id);
  if (err)
  {
    QMessageBox::critical(table_, "Error", QString::fromStdString(*err), QMessageBox::Close);
    restoreText();
    return;
  }
  try
  {
    DbApi::updateJournalRow(std::move(journalRow));
    currentItemMeta.text = item->text();
  }
  catch (const odb::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    restoreText();
  }
}

void JournalTab::menu(const QPoint &pos)
{
  checkCutEnabled();
  checkCopyEnabled();
  checkPasteEnabled();
  checkDelEnabled();
  checkDelRowsEnabled();
  menu_->exec(QCursor::pos());
}

void JournalTab::copy()
{
  if (!isCopyEnabled())
    return;
  QString str;
  auto item = table_->currentItem();
  if (item)
    str = item->text();
  QGuiApplication::clipboard()->setText(str);
}

void JournalTab::paste()
{
  if (!isPasteEnabled())
    return;
  table_->setItem(table_->currentRow(), table_->currentColumn(), new QTableWidgetItem(QGuiApplication::clipboard()->text()));
}

void JournalTab::del()
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

void JournalTab::cut()
{
  if (!isCutEnabled())
    return;
  copy();
  del();
}

void JournalTab::delRows()
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
      DbApi::removeJournalRow(id);
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

void JournalTab::checkCopyEnabled()
{
  copy_->setEnabled(isCopyEnabled());
}

bool JournalTab::isCopyEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  if (selectedRanges.size() != 1 || selectedRanges[0].columnCount() * selectedRanges[0].rowCount() != 1)
    return false;
  else
    return true;
}

void JournalTab::checkDelEnabled()
{
  del_->setEnabled(isDelEnabled() && !isDelRowsEnabled());
}

bool JournalTab::isDelEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  return !selectedRanges.empty();
}

void JournalTab::checkCutEnabled()
{
  cut_->setEnabled(isCutEnabled());
}

bool JournalTab::isCutEnabled()
{
  return isCopyEnabled() && isDelEnabled();
}

void JournalTab::checkDelRowsEnabled()
{
  delRows_->setEnabled(isDelRowsEnabled());
}

bool JournalTab::isDelRowsEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool allRows = true;
  for (const auto &range : selectedRanges)
  {
    allRows = allRows && range.leftColumn() == Column::ID && range.rightColumn() == Column::ROUTE_ID;
  }
  return allRows;
}

void JournalTab::checkPasteEnabled()
{
  paste_->setEnabled(isPasteEnabled());
}

bool JournalTab::isPasteEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool enabled = selectedRanges.size() == 1 &&
                 selectedRanges[0].columnCount() * selectedRanges[0].rowCount() == 1 &&
                 selectedRanges[0].leftColumn() != Column::ID;
  return enabled;
}

void JournalTab::updateCache()
{
  cachedItems_.clear();
  for (int row = 0; row < table_->rowCount(); ++row)
    for (int col = 0; col < table_->columnCount(); ++col)
    {
      if (table_->item(row, col))
      {
        cachedItems_[row][col] = ItemMeta{ table_->item(row, col)->text() };
      }
    }
}

JournalTab::~JournalTab()
{ }
