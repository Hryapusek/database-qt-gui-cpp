#ifndef ADD_ROUTE_DIALOG
#define ADD_ROUTE_DIALOG

#include <QDialog>

namespace Ui
{
  class AddRouteDialog;
}

class AddRouteDialog : public QDialog
{
  Q_OBJECT

public:
  AddRouteDialog(QWidget *parent = nullptr);
  ~AddRouteDialog();
  QString getName();

private:
  std::unique_ptr<Ui::AddRouteDialog> ui;
};

#endif
