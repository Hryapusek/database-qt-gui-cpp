#ifndef ROUTE_TAB_HPP
#define ROUTE_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class AddRouteDialog;
class RemoveRouteDialog;

class RouteTab: public QObject
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
  void itemChanged(QTableWidgetItem *item);
  void menu(const QPoint &pos);
  void copy();
  void del();
  void cut();
  void delRows();

private:
  struct itemMeta
  {
    QString text;
  };

  using Id_t = long;
  using Row_t = int;
  using Column_t = int;
  using CachedItems_t = std::map< Row_t, std::map< Column_t, itemMeta > >;

  QPushButton *addBtn_ = nullptr;
  QPushButton *removeBtn_ = nullptr;
  QPushButton *refreshBtn_ = nullptr;
  QTableWidget *table_ = nullptr;
  QAction *copy_ = nullptr;
  QAction *del_ = nullptr;
  QAction *cut_ = nullptr;
  QAction *delRows_ = nullptr;
  std::unique_ptr< QMenu > menu_;
  bool refreshing_ = false;
  std::unique_ptr< AddRouteDialog > addRouteDialog_;
  std::unique_ptr< RemoveRouteDialog > removeRouteDialog_;
  CachedItems_t cachedItems_;

  enum Column
  {
    ID = 0,
    NAME = 1,
  };

  struct RefreshRAII
  {
    RefreshRAII(RouteTab *tab) :
      tab_(tab)
    {
      tab_->refreshing_ = true;
    }
    RefreshRAII(const RefreshRAII &) = delete;
    RefreshRAII(RefreshRAII &&) = delete;
    RefreshRAII &operator=(const RefreshRAII &) = delete;
    RefreshRAII &operator=(RefreshRAII &&) = delete;
    ~RefreshRAII()
    {
      tab_->refreshing_ = false;
    }

  private:
    RouteTab *tab_;
  };

  [[nodiscard]] RefreshRAII startRefresh()
  {
    return RefreshRAII(this);
  }

  void updateCache();
  void checkCopyEnabled();
  void checkDelEnabled();
  void checkCutEnabled();
  /// @note Must be called only after checkDelEnabled();
  void checkDelRowsEnabled();
};

#endif
