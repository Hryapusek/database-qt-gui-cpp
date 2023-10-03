#ifndef REMOVE_JOURNAL_ROW_DIALOG
#define REMOVE_JOURNAL_ROW_DIALOG

#include <QDialog>

namespace Ui
{
  class RemoveJournalRowDialog;
}

class RemoveJournalRowDialog : public QDialog
{
  Q_OBJECT

public:
  RemoveJournalRowDialog(QWidget *parent = nullptr);
  ~RemoveJournalRowDialog();
  QString getId();

private:
  std::unique_ptr<Ui::RemoveJournalRowDialog> ui;

};

#endif
