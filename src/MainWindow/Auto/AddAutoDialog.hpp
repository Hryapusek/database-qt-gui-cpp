#ifndef ADD_AUTO_DIALOG
#define ADD_AUTO_DIALOG

#include <QDialog>

namespace Ui
{
  class AddAutoDialog;
}

class AddAutoDialog : public QDialog
{
  Q_OBJECT

public:
  AddAutoDialog(QWidget *parent = nullptr);
  ~AddAutoDialog();
  QString getNum();
  QString getColor();
  QString getMark();
  QString getPersonId();

private:
  std::unique_ptr<Ui::AddAutoDialog> ui;

};

#endif
