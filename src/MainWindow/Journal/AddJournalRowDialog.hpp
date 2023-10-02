#ifndef ADD_PERSON_DIALOG
#define ADD_PERSON_DIALOG

#include <QDialog>

namespace Ui
{
  class AddPersonDialog;
}

class AddPersonDialog : public QDialog
{
  Q_OBJECT

public:
  AddPersonDialog(QWidget *parent = nullptr);
  ~AddPersonDialog();
  QString getId();
  QString getFirstName();
  QString getSecondName();
  QString getFatherName();

private:
  std::unique_ptr<Ui::AddPersonDialog> ui;

};

#endif
