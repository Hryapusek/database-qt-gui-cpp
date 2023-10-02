#ifndef REMOVE_AUTO_DIALOG
#define REMOVE_AUTO_DIALOG

#include <QDialog>

namespace Ui
{
  class RemoveAutoDialog;
}

class RemoveAutoDialog : public QDialog
{
  Q_OBJECT

public:
  RemoveAutoDialog(QWidget *parent = nullptr);
  virtual ~RemoveAutoDialog();
  QString getId();

private:
  std::unique_ptr<Ui::RemoveAutoDialog> ui;

};

#endif
