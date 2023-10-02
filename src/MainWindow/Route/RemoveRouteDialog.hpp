#ifndef REMOVE_ROUTE_DIALOG
#define REMOVE_ROUTE_DIALOG

#include <QDialog>

namespace Ui
{
  class RemoveRouteDialog;
}

class RemoveRouteDialog : public QDialog
{
  Q_OBJECT

public:
  RemoveRouteDialog(QWidget *parent = nullptr);
  virtual ~RemoveRouteDialog();
  QString getId();

private:
  std::unique_ptr<Ui::RemoveRouteDialog> ui;

};

#endif
