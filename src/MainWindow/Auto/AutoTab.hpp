#ifndef AUTO_TAB_HPP
#define AUTO_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class AddAutoDialog;
class RemoveAutoDialog;

class AutoTab: public QObject
{
  Q_OBJECT
public:
  AutoTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
  void refreshTable();
  void clearTable();
  ~AutoTab();

signals:
  void refreshTablesSig();

private slots:
  void addBtnClicked();
  void removeBtnClicked();
  void itemChanged(QTableWidgetItem *item);

private:
  struct ItemMeta
  {
    QString text;
  };

  using Row_t = int;
  using Column_t = int;
  using CachedItems_t = std::map< Row_t, std::map< Column_t, ItemMeta > >;

  QPushButton *addBtn_;
  QPushButton *removeBtn_;
  QPushButton *refreshBtn_;
  QTableWidget *table_;
  bool refreshing_ = false;
  std::unique_ptr< AddAutoDialog > addAutoDialog_;
  std::unique_ptr< RemoveAutoDialog > removeAutoDialog_;
  CachedItems_t cachedItems_;

  enum Column
  {
    ID = 0,
    NUM = 1,
    COLOR = 2,
    MARK = 3,
    PERSON_ID = 4
  };

  struct RefreshRAII
  {
    RefreshRAII(AutoTab *tab) :
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
    AutoTab *tab_;
  };

  [[nodiscard]] RefreshRAII startRefresh()
  {
    return RefreshRAII(this);
  }

  void updateCache();
};

#endif
