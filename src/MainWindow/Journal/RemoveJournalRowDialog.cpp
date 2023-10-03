#include "RemoveJournalRowDialog.hpp"
#include "UiRemoveJournalRowDialog.hpp"

#include <QRegExpValidator>

RemoveJournalRowDialog::RemoveJournalRowDialog(QWidget *parent) :
  QDialog(parent),
  ui(std::make_unique<Ui::RemoveJournalRowDialog>())
{
  ui->setupUi(this);
  auto idLineValidator = new QRegExpValidator(QRegExp("[-]?[1-9]{8}"), ui->idLine);
  ui->idLine->setValidator(idLineValidator);
}

RemoveJournalRowDialog::~RemoveJournalRowDialog()
{
}

QString RemoveJournalRowDialog::getId()
{
  return ui->idLine->text();
}
