#ifndef AUTO_TAB_HPP
#define AUTO_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class AutoTab : public QObject
{
  Q_OBJECT
public:
  AutoTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
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
    NUM = 1,
    COLOR = 2,
    MARK = 3,
    PERSON_ID = 4 
  };
};

#endif
