#include "AddPersonDialog.hpp"
#include "UiAddPersonDialog.hpp"

#include <QRegExpValidator>

AddPersonDialog::AddPersonDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::AddPersonDialog>())
{
  ui->setupUi(this);

  auto firstNameLineValidator = new QRegExpValidator(QRegExp("[a-zA-Zа-яА-Я]{20}"), ui->firstNameLine);
  ui->firstNameLine->setValidator(firstNameLineValidator);

  auto lastNameLineValidator = new QRegExpValidator(QRegExp("[a-zA-Zа-яА-Я]{20}"), ui->lastNameLine);
  ui->lastNameLine->setValidator(lastNameLineValidator);

  auto fatherNameLineValidator = new QRegExpValidator(QRegExp("[a-zA-Zа-яА-Я]{20}"), ui->fatherNameLine);
  ui->fatherNameLine->setValidator(fatherNameLineValidator);
}

AddPersonDialog::~AddPersonDialog()
{}

QString AddPersonDialog::getFirstName()
{
  return ui->firstNameLine->text();
}

QString AddPersonDialog::getLastName()
{
  return ui->lastNameLine->text();
}

QString AddPersonDialog::getFatherName()
{
  return ui->fatherNameLine->text();
}
