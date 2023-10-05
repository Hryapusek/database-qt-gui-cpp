#include "AddJournalRowDialog.hpp"
#include "UiAddJournalRowDialog.hpp"

#include <QRegExpValidator>

AddJournalRowDialog::AddJournalRowDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::AddJournalRowDialog>())
{
  ui->setupUi(this);

  auto timeOutLineValidator = new QRegExpValidator(QRegExp(".{30}"), ui->timeOutLine);
  ui->timeOutLine->setValidator(timeOutLineValidator);

  auto timeInLineValidator = new QRegExpValidator(QRegExp("[a-zA-Z]{20}"), ui->timeInLine);
  ui->timeInLine->setValidator(timeInLineValidator);

  auto autoIdLineValidator = new QRegExpValidator(QRegExp("[-]?[1-9]{8}"), ui->autoIdLine);
  ui->autoIdLine->setValidator(autoIdLineValidator);

  auto routeIdLineValidator = new QRegExpValidator(QRegExp("[-]?[1-9]{8}"), ui->routeIdLine);
  ui->routeIdLine->setValidator(routeIdLineValidator);
}

AddJournalRowDialog::~AddJournalRowDialog()
{}

QString AddJournalRowDialog::getTimeOut()
{
  return ui->timeOutLine->text();
}

QString AddJournalRowDialog::getTimeIn()
{
  return ui->timeInLine->text();
}

QString AddJournalRowDialog::getAutoId()
{
  return ui->autoIdLine->text();
}

QString AddJournalRowDialog::getRouteId()
{
  return ui->routeIdLine->text();
}
