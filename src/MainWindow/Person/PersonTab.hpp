#ifndef PERSON_TAB_HPP
#define PERSON_TAB_HPP

#include <QPushButton>
#include <QTableWidget>

class AddPersonDialog;
class RemovePersonDialog;
class QShortcut;

class PersonTab: public QObject
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
  void itemChanged(QTableWidgetItem *item);
  void menu(const QPoint &pos);
  void copy();
  void paste();
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
  QAction *paste_ = nullptr;
  QShortcut *pasteShortcut_ = nullptr;
  QAction *del_ = nullptr;
  QShortcut *delShortcut_ = nullptr;
  QAction *cut_ = nullptr;
  QShortcut *cutShortcut_ = nullptr;
  QAction *delRows_ = nullptr;
  std::unique_ptr< QMenu > menu_;
  bool refreshing_ = false;
  std::unique_ptr< AddPersonDialog > addPersonDialog_;
  std::unique_ptr< RemovePersonDialog > removePersonDialog_;
  CachedItems_t cachedItems_;

  enum Column
  {
    ID = 0,
    FIRST_NAME = 1,
    LAST_NAME = 2,
    FATHER_NAME = 3
  };

  struct RefreshRAII
  {
    RefreshRAII(PersonTab *tab) :
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
    PersonTab *tab_;
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
  void checkDelRowsEnabled();
  bool isDelRowsEnabled();
  void checkPasteEnabled();
  bool isPasteEnabled();
};

#endif
