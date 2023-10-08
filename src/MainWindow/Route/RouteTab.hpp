#ifndef ROUTE_TAB_HPP
#define ROUTE_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class AddRouteDialog;
class RemoveRouteDialog;

class RouteTab : public QObject
{
  Q_OBJECT
public:
  RouteTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
  void refreshTable();
  void clearTable();
  ~RouteTab();

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
  std::unique_ptr<AddRouteDialog> addRouteDialog_;
  std::unique_ptr<RemoveRouteDialog> removeRouteDialog_;
  enum Column
  {
    ID = 0,
    NAME = 1,
  };
};

#endif
