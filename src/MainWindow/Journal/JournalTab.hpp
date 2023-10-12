#ifndef JOURNAL_TAB_HPP
#define JOURNAL_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class AddJournalRowDialog;
class RemoveJournalRowDialog;
class QShortcut;

class JournalTab: public QObject
{
  Q_OBJECT
public:
  JournalTab(QTableWidget *table, QPushButton *addBtn, QPushButton *removeBtn, QPushButton *refreshBtn);
  ~JournalTab();
  void refreshTable();
  void clearTable();

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
  struct ItemMeta
  {
    QString text;
  };

  using Id_t = long;
  using Row_t = int;
  using Column_t = int;
  using CachedItems_t = std::map< Row_t, std::map< Column_t, ItemMeta > >;

  QPushButton *addBtn_ = nullptr;
  QPushButton *removeBtn_ = nullptr;
  QPushButton *refreshBtn_ = nullptr;
  QTableWidget *table_ = nullptr;
  QAction *copy_ = nullptr;
  QShortcut *copyShortcut_ = nullptr;
  QAction *del_ = nullptr;
  QShortcut *delShortcut_ = nullptr;
  QAction *cut_ = nullptr;
  QShortcut *cutShortcut_ = nullptr;
  QAction *delRows_ = nullptr;
  std::unique_ptr< QMenu > menu_;
  bool refreshing_ = false;
  std::unique_ptr< AddJournalRowDialog > addJournalRowDialog_;
  std::unique_ptr< RemoveJournalRowDialog > removeJournalRowDialog_;
  CachedItems_t cachedItems_;

  enum Column
  {
    ID = 0,
    TIME_OUT = 1,
    TIME_IN = 2,
    AUTO_ID = 3,
    ROUTE_ID = 4
  };

  struct RefreshRAII
  {
    RefreshRAII(JournalTab *tab) :
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
    JournalTab *tab_;
  };

  [[nodiscard]] RefreshRAII startRefresh()
  {
    return RefreshRAII(this);
  }

  void updateCache();
  void checkCopyEnabled();
  bool isCopyEnabled();
  void checkDelEnabled();
  bool isDelEnabled();
  void checkCutEnabled();
  bool isCutEnabled();
  /// @note Must be called only after checkDelEnabled();
  void checkDelRowsEnabled();
  bool isDelRowsEnabled();
};

#endif
