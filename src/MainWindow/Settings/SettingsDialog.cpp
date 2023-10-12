#include "SettingsDialog.hpp"
#include "UiSettings.hpp"

#include <QMessageBox>

SettingsDialog::SettingsDialog(QWidget *parent) :
  ui_(std::make_unique< Ui::SettingsDialog >())
{
  ui_->setupUi(this);
  ui_->applyBtn->setEnabled(false);
  QObject::connect(ui_->applyBtn, &QPushButton::clicked, this, &SettingsDialog::applyClicked);
  QObject::connect(ui_->usernameLine, &QLineEdit::textChanged, this, &SettingsDialog::somethingChanged);
  QObject::connect(ui_->databaseLine, &QLineEdit::textChanged, this, &SettingsDialog::somethingChanged);
  QObject::connect(ui_->passwordLine, &QLineEdit::textChanged, this, &SettingsDialog::somethingChanged);
}

void SettingsDialog::somethingChanged([[maybe_unused]] const QString &unused)
{
  setSomethingChanged(true);
}

void SettingsDialog::applyClicked()
{
  setSomethingChanged(false);
  emit apply();
}

void SettingsDialog::accept()
{
  if (!somethingChanged_)
    return QDialog::accept();

  auto result = QMessageBox::question(this, "Unsaved changes",
    "There are unsaved changes. Would you like to save?",
    QMessageBox::Yes,
    QMessageBox::No,
    QMessageBox::Cancel);
  switch (result)
  {
    case QMessageBox::Cancel:
      return;

    case QMessageBox::Yes:
    {
      setSomethingChanged(false);
      emit apply();
      return QDialog::accept();
    }

    case QMessageBox::No:
    {
      setSomethingChanged(false);
      return QDialog::accept();
    }

    default:
      break;
  }
}

void SettingsDialog::setSomethingChanged(bool val)
{
  somethingChanged_ = val;
  ui_->applyBtn->setEnabled(val);
}

bool SettingsDialog::isSomethingChanged()
{
  return somethingChanged_;
}

QString SettingsDialog::username()
{
  return ui_->usernameLine->text();
}

void SettingsDialog::username(const QString &username)
{
  bool somethingChanged = this->isSomethingChanged();
  ui_->usernameLine->setText(username);
  setSomethingChanged(somethingChanged);
}

QString SettingsDialog::database()
{
  return ui_->databaseLine->text();
}

void SettingsDialog::database(const QString &database)
{
  bool somethingChanged = this->isSomethingChanged();
  ui_->databaseLine->setText(database);
  setSomethingChanged(somethingChanged);
}

QString SettingsDialog::password()
{
  return ui_->passwordLine->text();
}

void SettingsDialog::password(const QString &password)
{
  bool somethingChanged = this->isSomethingChanged();
  ui_->passwordLine->setText(password);
  setSomethingChanged(somethingChanged);
}

SettingsDialog::~SettingsDialog()
{ }
