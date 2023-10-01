#ifndef ROUTE_TAB_HPP
#define ROUTE_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class RouteTab : public QObject
{
  Q_OBJECT
public:
  RouteTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
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
    NAME = 1,
  };
};

#endif
