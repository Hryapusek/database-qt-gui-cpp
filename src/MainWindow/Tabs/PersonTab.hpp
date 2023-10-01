#ifndef PERSON_TAB_HPP
#define PERSON_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class PersonTab : public QObject
{
  Q_OBJECT
public:
  PersonTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
  void refreshTable();
  void clearTable();

signals:
  void refreshTablesSig();

private:
  QPushButton *addBtn_;
  QPushButton *removeBtn_;
  QPushButton *refreshBtn_;
  QTableWidget *table_;
  enum Column
  {
    ID = 0,
    FIRST_NAME = 1,
    SECOND_NAME = 2,
    FATHER_NAME = 3
  };
};

#endif
