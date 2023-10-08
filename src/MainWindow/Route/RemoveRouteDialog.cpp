#include "RemoveRouteDialog.hpp"
#include "UiRemoveRouteDialog.hpp"

#include <QRegExpValidator>

RemoveRouteDialog::RemoveRouteDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::RemoveRouteDialog>())
{
  ui->setupUi(this);
  auto idLineValidator = new QRegExpValidator(QRegExp("[-]?[1-9][0-9]{15}"), ui->idLine);
  ui->idLine->setValidator(idLineValidator);
}

RemoveRouteDialog::~RemoveRouteDialog()
{
}

QString RemoveRouteDialog::getId()
{
  return ui->idLine->text();
}
