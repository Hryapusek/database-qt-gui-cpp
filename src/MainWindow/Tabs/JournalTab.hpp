#ifndef JOURNAL_TAB_HPP
#define JOURNAL_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class JournalTab : public QObject
{
  Q_OBJECT
public:
  JournalTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
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
    TIME_OUT = 1,
    TIME_IN = 2,
    AUTO_ID = 3,
    ROUTE_ID = 4
  };
};

#endif
