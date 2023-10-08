#ifndef PERSON_TAB_HPP
#define PERSON_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class AddPersonDialog;
class RemovePersonDialog;

class PersonTab : public QObject
{
  Q_OBJECT
public:
  PersonTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
  void refreshTable();
  void clearTable();
  ~PersonTab();

signals:
  void refreshTablesSig();

private slots:
  void addBtnClicked();
  void removeBtnClicked();

private:
  QPushButton *addBtn_;
  QPushButton *removeBtn_;
  QPushButton *refreshBtn_;
  QTableWidget *table_;
  std::unique_ptr<AddPersonDialog> addPersonDialog_;
  std::unique_ptr<RemovePersonDialog> removePersonDialog_;

  enum Column
  {
    ID = 0,
    FIRST_NAME = 1,
    LAST_NAME = 2,
    FATHER_NAME = 3
  };
};

#endif
