#include "AddPersonDialog.hpp"
#include "UiAddPersonDialog.hpp"

#include <QRegExpValidator>

AddPersonDialog::AddPersonDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::AddPersonDialog>())
{
  ui->setupUi(this);

  auto firstNameLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z]{20}"), ui->firstNameLine);
  ui->firstNameLine->setValidator(firstNameLineValidator);

  auto secondNameLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z]{20}"), ui->secondNameLine);
  ui->secondNameLine->setValidator(secondNameLineValidator);

  auto fatherNameLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z]{20}"), ui->fatherNameLine);
  ui->fatherNameLine->setValidator(fatherNameLineValidator);
}

AddPersonDialog::~AddPersonDialog()
{}

QString AddPersonDialog::getFirstName()
{
  return ui->firstNameLine->text();
}

QString AddPersonDialog::getSecondName()
{
  return ui->secondNameLine->text();
}

QString AddPersonDialog::getFatherName()
{
  return ui->fatherNameLine->text();
}
