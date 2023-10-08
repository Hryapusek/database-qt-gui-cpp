#include "AddRouteDialog.hpp"
#include "UiAddRouteDialog.hpp"

#include <QRegExpValidator>

AddRouteDialog::AddRouteDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::AddRouteDialog>())
{
  ui->setupUi(this);
  auto nameLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z0-9 ]{20}"), ui->nameLine);
  ui->nameLine->setValidator(nameLineValidator);
}

AddRouteDialog::~AddRouteDialog()
{}

QString AddRouteDialog::getName()
{
  return ui->nameLine->text();
}
