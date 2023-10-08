#include "JournalTab.hpp"
#include "Database/DbApi.hpp"

#include "MainWindow/Utils.hpp"

#include "AddJournalRowDialog.hpp"
#include "RemoveJournalRowDialog.hpp"

#include <iostream>
#include <QMessageBox>
#include <odb/exceptions.hxx>

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
{ }

void JournalTab::refreshTable()
{
  auto journalRows = DbApi::getJournalRows();
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
}

void JournalTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
}

void JournalTab::removeBtnClicked()
{
  removeJournalRowDialog_ = std::make_unique< RemoveJournalRowDialog >(table_);
  auto result = removeJournalRowDialog_->exec();
  // TODO remove person from database
  // Try-Catch if person does not exist?
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
  addJournalRowDialog_ = std::make_unique< AddJournalRowDialog >(table_);
  auto result = addJournalRowDialog_->exec();
  bool ok = false;
  if (result == QDialog::Accepted)
  {
    auto timeOutStr = addJournalRowDialog_->getTimeOut().toStdString();
    odb::nullable< time_t > timeOut;
    if (timeOutStr.size())
    {
      timeOut = StringUtils::stringToMicrosecFrom2000(timeOutStr, &ok);
      if (!ok)
      {
        QMessageBox::critical(table_, "Error", "Bad Time Out value. Time must be in D.M.Y H:M:S", QMessageBox::Close);
        return;
      }
    }
    auto timeInStr = addJournalRowDialog_->getTimeIn().toStdString();
    odb::nullable< time_t > timeIn;
    if (timeInStr.size())
    {
      timeIn = StringUtils::stringToMicrosecFrom2000(timeInStr, &ok);
      if (!ok)
      {
        QMessageBox::critical(table_, "Error", "Bad Time In value. Time must be in D.M.Y H:M:S", QMessageBox::Close);
        return;
      }
    }
    auto autoId = addJournalRowDialog_->getAutoId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given auto ID to number", QMessageBox::Close);
      return;
    }
    auto routeId = addJournalRowDialog_->getRouteId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given auto ID to number", QMessageBox::Close);
      return;
    }
    try
    {
      DbApi::addJournalRow(JournalRow(0, timeOut, timeIn, DbApi::getAuto(autoId), DbApi::getRoute(routeId)));
      QMessageBox::information(table_, "Success!", "Journal row added", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    }
    emit refreshTablesSig();
  }
  return;
}
