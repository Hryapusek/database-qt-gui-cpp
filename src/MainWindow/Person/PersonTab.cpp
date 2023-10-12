#include "PersonTab.hpp"

#include "Database/DbApi.hpp"

#include "AddPersonDialog.hpp"
#include "RemovePersonDialog.hpp"

#include <odb/exceptions.hxx>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QGuiApplication>
#include <QClipboard>
#include <ranges>
#include <optional>

namespace
{
  Person personFromString(QString firstName, QString lastName, QString fatherName, std::optional< std::string > &err)
  {
    Person person;
    person.firstName(firstName.toStdString());
    person.lastName(lastName.toStdString());
    person.fatherName(fatherName.toStdString());
    err = std::nullopt;
    return person;
  }
}

PersonTab::PersonTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &PersonTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &PersonTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &PersonTab::removeBtnClicked);
  QObject::connect(table_, &QTableWidget::itemChanged, this, &PersonTab::itemChanged);
  table_->setContextMenuPolicy(Qt::CustomContextMenu);
  QObject::connect(table_, &QTableWidget::customContextMenuRequested, this, &PersonTab::menu);

  copy_ = new QAction("Copy", table_);
  copy_->setShortcut(Qt::Key_Copy);
  copy_->setEnabled(false);
  copy_->setShortcutVisibleInContextMenu(false);
  QObject::connect(copy_, &QAction::triggered, this, &PersonTab::copy);

  del_ = new QAction("Del", table_);
  del_->setShortcut(Qt::Key_Delete);
  del_->setEnabled(false);
  del_->setShortcutVisibleInContextMenu(false);
  QObject::connect(del_, &QAction::triggered, this, &PersonTab::del);

  cut_ = new QAction("Cut", table_);
  cut_->setShortcut(Qt::Key_Cut);
  cut_->setEnabled(false);
  cut_->setShortcutVisibleInContextMenu(false);
  QObject::connect(cut_, &QAction::triggered, this, &PersonTab::cut);

  delRows_ = new QAction("Del Rows", table_);
  delRows_->setEnabled(false);
  QObject::connect(delRows_, &QAction::triggered, this, &PersonTab::delRows);

  table_->addAction(copy_);
  table_->addAction(del_);
  table_->addAction(cut_);
  table_->addAction(delRows_);

  menu_ = std::make_unique< QMenu >(table_);
  menu_->addAction(copy_);
  menu_->addAction(del_);
  menu_->addAction(cut_);
  menu_->addAction(delRows_);
}

void PersonTab::refreshTable()
{
  decltype(DbApi::getPersons()) persons;
  try
  {
    persons = DbApi::getPersons();
  }
  catch (const odb::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    return;
  }
  auto refreshRAII = startRefresh();
  clearTable();
  for (const auto &person : persons)
  {
    auto curRow = table_->rowCount();
    table_->insertRow(table_->rowCount());
    table_->setVerticalHeaderItem(curRow, new QTableWidgetItem(""));

    auto idStr = QString::fromStdString(std::to_string(person.id()));
    auto idItem = new QTableWidgetItem(idStr);
    idItem->setFlags(idItem->flags() &  ~Qt::ItemIsEditable);
    table_->setItem(curRow, Column::ID, idItem);
    if (person.firstName())
    {
      auto firstName = QString::fromStdString(person.firstName().get());
      table_->setItem(curRow, Column::FIRST_NAME, new QTableWidgetItem(firstName));
    }
    if (person.lastName())
    {
      auto lastName = QString::fromStdString(person.lastName().get());
      table_->setItem(curRow, Column::LAST_NAME, new QTableWidgetItem(lastName));
    }
    if (person.fatherName())
    {
      auto fatherName = QString::fromStdString(person.fatherName().get());
      table_->setItem(curRow, Column::FATHER_NAME, new QTableWidgetItem(fatherName));
    }
  }
  updateCache();
}

void PersonTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
  updateCache();
}

void PersonTab::removeBtnClicked()
{
  if (!removePersonDialog_)
    removePersonDialog_ = std::make_unique< RemovePersonDialog >(table_);
  auto result = removePersonDialog_->exec();
  if (result == QDialog::Accepted)
  {
    bool ok = true;
    Person::Id_t id = removePersonDialog_->getId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given ID to number", QMessageBox::Close);
      return removeBtnClicked();
    }
    try
    {
      DbApi::removePerson(id);
      QMessageBox::information(table_, "Success!", "Person removed", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
      return removeBtnClicked();
    }
    emit refreshTablesSig();
  }
  return;
}

void PersonTab::addBtnClicked()
{
  if (!addPersonDialog_)
    addPersonDialog_ = std::make_unique< AddPersonDialog >(table_);
  auto result = addPersonDialog_->exec();
  if (result == QDialog::Accepted)
  {
    std::optional< std::string > err;
    Person person = personFromString(
      addPersonDialog_->getFirstName(),
      addPersonDialog_->getLastName(),
      addPersonDialog_->getFatherName(),
      err);
    if (err)
    {
      QMessageBox::critical(table_, "Error", QString::fromStdString(*err), QMessageBox::Close);
      return addBtnClicked();
    }
    try
    {
      DbApi::addPerson(person);
      QMessageBox::information(table_, "Success!", "Person added", QMessageBox::Ok);
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

void PersonTab::itemChanged(QTableWidgetItem *item)
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
  QString firstName;
  if (table_->item(item->row(), Column::FIRST_NAME))
    firstName = table_->item(item->row(), Column::FIRST_NAME)->text();

  QString lastName;
  if (table_->item(item->row(), Column::LAST_NAME))
    lastName = table_->item(item->row(), Column::LAST_NAME)->text();

  QString fatherName;
  if (table_->item(item->row(), Column::FATHER_NAME))
    fatherName = table_->item(item->row(), Column::FATHER_NAME)->text();
  std::optional< std::string > err;
  Person person = personFromString(std::move(firstName), std::move(lastName), std::move(fatherName), err);
  person.id(id);
  if (err)
  {
    QMessageBox::critical(table_, "Error", QString::fromStdString(*err), QMessageBox::Close);
    restoreText();
    return;
  }
  try
  {
    DbApi::updatePerson(std::move(person));
    currentItemMeta.text = item->text();
  }
  catch (const odb::exception &e)
  {
    QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    restoreText();
    return;
  }
}

void PersonTab::menu(const QPoint &pos)
{
  checkCopyEnabled();
  checkDelEnabled();
  checkCutEnabled();
  checkDelRowsEnabled();
  menu_->exec(QCursor::pos());
}

void PersonTab::copy()
{
  QString str;
  auto item = table_->currentItem();
  if (item)
    str = item->text();
  QGuiApplication::clipboard()->setText(str);
}

void PersonTab::del()
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

void PersonTab::cut()
{
  copy();
  del();
}

void PersonTab::delRows()
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
      DbApi::removePerson(id);
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

void PersonTab::checkCopyEnabled()
{
  copy_->setEnabled(isCopyEnabled());
}

bool PersonTab::isCopyEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  if (selectedRanges.size() != 1 || selectedRanges[0].columnCount() * selectedRanges[0].rowCount() != 1)
    return false;
  else
    return true;
}

void PersonTab::checkDelEnabled()
{
  del_->setEnabled(isDelEnabled() && !isDelRowsEnabled());
}

bool PersonTab::isDelEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  return !selectedRanges.empty();
}

void PersonTab::checkCutEnabled()
{
  cut_->setEnabled(isCutEnabled());
}

bool PersonTab::isCutEnabled()
{
  return isCopyEnabled() && isDelEnabled();
}

void PersonTab::checkDelRowsEnabled()
{
  delRows_->setEnabled(isDelRowsEnabled());
}

bool PersonTab::isDelRowsEnabled()
{
  auto selectedRanges = table_->selectedRanges();
  bool allRows = true;
  for (const auto &range : selectedRanges)
  {
    allRows = allRows && range.leftColumn() == Column::ID && range.rightColumn() == Column::FATHER_NAME;
  }
  return allRows;
}

void PersonTab::updateCache()
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

PersonTab::~PersonTab()
{ }
