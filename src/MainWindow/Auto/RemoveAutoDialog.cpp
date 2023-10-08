#include "RemoveAutoDialog.hpp"
#include "UiRemoveAutoDialog.hpp"

#include <QRegExpValidator>

RemoveAutoDialog::RemoveAutoDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::RemoveAutoDialog>())
{
  ui->setupUi(this);
  auto idLineValidator = new QRegExpValidator(QRegExp("[-]?[1-9][0-9]{15}"), ui->idLine);
  ui->idLine->setValidator(idLineValidator);
}

RemoveAutoDialog::~RemoveAutoDialog()
{
}

QString RemoveAutoDialog::getId()
{
  return ui->idLine->text();
}
