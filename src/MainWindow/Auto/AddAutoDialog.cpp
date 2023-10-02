#include "AddAutoDialog.hpp"
#include "UiAddAutoDialog.hpp"

#include <QRegExpValidator>

AddAutoDialog::AddAutoDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::AddAutoDialog>())
{
  ui->setupUi(this);
  auto idLineValidator = new QRegExpValidator(QRegExp("[-]?[1-9]{8}"), ui->idLine);
  ui->idLine->setValidator(idLineValidator);

  auto numLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z0-9]{20}"), ui->numLine);
  ui->numLine->setValidator(numLineValidator);

  auto colorLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z]{20}"), ui->colorLine);
  ui->colorLine->setValidator(colorLineValidator);

  auto markLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z]{20}"), ui->markLine);
  ui->markLine->setValidator(markLineValidator);

  auto personIdLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z]{20}"), ui->personIdLine);
  ui->personIdLine->setValidator(personIdLineValidator);
}

AddAutoDialog::~AddAutoDialog()
{}

QString AddAutoDialog::getId()
{
  return ui->idLine->text();
}

QString AddAutoDialog::getNum()
{
  return ui->numLine->text();
}
