#include "RemovePersonDialog.hpp"
#include "UiRemovePersonDialog.hpp"

#include <QRegExpValidator>

RemovePersonDialog::RemovePersonDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::RemovePersonDialog>())
{
  ui->setupUi(this);
  auto idLineValidator = new QRegExpValidator(QRegExp("[-]?[1-9][0-9]{15}"), ui->idLine);
  ui->idLine->setValidator(idLineValidator);
}

RemovePersonDialog::~RemovePersonDialog()
{
}

QString RemovePersonDialog::getId()
{
  return ui->idLine->text();
}
