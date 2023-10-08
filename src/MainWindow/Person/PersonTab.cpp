#include "PersonTab.hpp"

#include "Database/DbApi.hpp"
#include <odb/exceptions.hxx>

#include "AddPersonDialog.hpp"
#include "RemovePersonDialog.hpp"

#include <QMessageBox>

#include <iostream>

PersonTab::PersonTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &PersonTab::refreshTablesSig);
  QObject::connect(addBtn_, &QPushButton::clicked, this, &PersonTab::addBtnClicked);
  QObject::connect(removeBtn_, &QPushButton::clicked, this, &PersonTab::removeBtnClicked);
}

void PersonTab::refreshTable()
{
  auto persons = DbApi::getPersons();
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
}

void PersonTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
    table_->removeRow(row);
}

PersonTab::~PersonTab()
{ }

void PersonTab::removeBtnClicked()
{
  removePersonDialog_ = std::make_unique< RemovePersonDialog >(table_);
  auto result = removePersonDialog_->exec();
  if (result == QDialog::Accepted)
  {
    bool ok = true;
    Person::Id_t id = removePersonDialog_->getId().toLong(&ok);
    if (!ok)
    {
      QMessageBox::critical(table_, "Bad ID", "Can not convert given ID to number", QMessageBox::Close);
      return;
    }
    try
    {
      DbApi::removePerson(id);
      QMessageBox::information(table_, "Success!", "Person removed", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    }
    emit refreshTablesSig();
  }
  return;
}

void PersonTab::addBtnClicked()
{
  addPersonDialog_ = std::make_unique< AddPersonDialog >(table_);
  auto result = addPersonDialog_->exec();
  if (result == QDialog::Accepted)
  {
    auto firstName = addPersonDialog_->getFirstName().toStdString();
    auto lastName = addPersonDialog_->getLastName().toStdString();
    auto fatherName = addPersonDialog_->getFatherName().toStdString();
    try
    {
      DbApi::addPerson(Person(0, std::move(firstName), std::move(lastName), std::move(fatherName)));
      QMessageBox::information(table_, "Success!", "Person added", QMessageBox::Ok);
    }
    catch (const odb::exception &e)
    {
      QMessageBox::critical(table_, "Error", e.what(), QMessageBox::Close);
    }
    emit refreshTablesSig();
  }
  return;
}
