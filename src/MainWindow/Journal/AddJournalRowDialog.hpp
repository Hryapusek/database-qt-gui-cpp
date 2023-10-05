#ifndef ADD_JOURNAL_ROW_DIALOG
#define ADD_JOURNAL_ROW_DIALOG

#include <QDialog>

namespace Ui
{
  class AddJournalRowDialog;
}

class AddJournalRowDialog : public QDialog
{
  Q_OBJECT

public:
  AddJournalRowDialog(QWidget *parent = nullptr);
  ~AddJournalRowDialog();
  QString getTimeOut();
  QString getTimeIn();
  QString getAutoId();
  QString getRouteId();

private:
  std::unique_ptr<Ui::AddJournalRowDialog> ui;

};

#endif
