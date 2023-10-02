#ifndef REMOVE_PERSON_DIALOG
#define REMOVE_PERSON_DIALOG

#include <QDialog>

namespace Ui
{
  class RemovePersonDialog;
}

class RemovePersonDialog : public QDialog
{
  Q_OBJECT

public:
  RemovePersonDialog(QWidget *parent = nullptr);
  virtual ~RemovePersonDialog();
  QString getId();

private:
  std::unique_ptr<Ui::RemovePersonDialog> ui;

};

#endif
