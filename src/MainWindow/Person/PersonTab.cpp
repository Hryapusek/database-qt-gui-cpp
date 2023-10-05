#include "PersonTab.hpp"

#include "Database/DbApi.hpp"

#include "AddPersonDialog.hpp"
#include "RemovePersonDialog.hpp"

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
    auto idStr = QString::fromStdString(std::to_string(person.id()));
    auto firstName = QString::fromStdString(person.getFirstName());
    auto secondName = QString::fromStdString(person.secondName());
    auto fatherName = QString::fromStdString(person.fatherName());
    table_->setItem(curRow, Column::ID, new QTableWidgetItem(idStr));
    table_->setItem(curRow, Column::FIRST_NAME, new QTableWidgetItem(firstName));
    table_->setItem(curRow, Column::SECOND_NAME, new QTableWidgetItem(secondName));
    table_->setItem(curRow, Column::FATHER_NAME, new QTableWidgetItem(fatherName));
  }
}

void PersonTab::clearTable()
{
  table_->clearContents();
  for (auto row = table_->rowCount() - 1; row >= 0; --row)
  {
    table_->removeRow(row);
  }
}

PersonTab::~PersonTab()
{
}

void PersonTab::removeBtnClicked()
{
  removePersonDialog = std::make_unique<RemovePersonDialog>(table_);
  auto result = removePersonDialog->exec();
  // TODO remove person from database
  // Try-Catch if person does not exist?
  if (result == QDialog::Accepted)
    std::cout << "Id " << removePersonDialog->getId().toStdString() << '\n';
  else
    std::cout << "Result is rejected\n";
}

void PersonTab::addBtnClicked()
{
  addPersonDialog = std::make_unique<AddPersonDialog>(table_);
  auto result = addPersonDialog->exec();
  // TODO add person to database
  // Try-Catch if person with id already exist?
  if (result == QDialog::Accepted)
  {
    std::cout << "First name " << addPersonDialog->getFirstName().toStdString() << '\n';
    std::cout << "Second name " << addPersonDialog->getSecondName().toStdString() << '\n';
    std::cout << "Father name " << addPersonDialog->getFatherName().toStdString() << '\n';
  }
  else
    std::cout << "Result is rejected\n";
}
