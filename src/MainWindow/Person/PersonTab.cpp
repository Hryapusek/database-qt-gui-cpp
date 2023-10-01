#include "PersonTab.hpp"
#include "Database/DbApi.hpp"

PersonTab::PersonTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn) :
  table_(table),
  addBtn_(addBtn),
  removeBtn_(removeBtn),
  refreshBtn_(refreshBtn)
{ 
  QObject::connect(refreshBtn_, &QPushButton::clicked, this, &PersonTab::refreshTablesSig);
}

void PersonTab::refreshTable()
{
  auto persons = DbApi::getPersons();
  clearTable();
  for (const auto &person : persons)
  {
    auto curRow = table_->rowCount();
    table_->insertRow(table_->rowCount());
    auto idStr = QString::fromStdString(std::to_string(person.getId()));
    auto firstName = QString::fromStdString(person.getFirstName());
    auto secondName = QString::fromStdString(person.getSecondName());
    auto fatherName = QString::fromStdString(person.getFatherName());
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
