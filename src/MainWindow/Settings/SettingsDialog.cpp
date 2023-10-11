#include "SettingsDialog.hpp"
#include "UiSettings.hpp"

SettingsDialog::SettingsDialog(QWidget *parent) :
  ui_(std::make_unique<Ui::SettingsDialog>())
{
  ui_->setupUi(this);
  QObject::connect(ui_->applyBtn, &QPushButton::clicked, this, &SettingsDialog::apply);
}

QString SettingsDialog::username()
{
  return ui_->usernameLine->text();
}

void SettingsDialog::username(const QString &username)
{
  ui_->usernameLine->setText(username);
}

QString SettingsDialog::database()
{
  return ui_->databaseLine->text();
}

void SettingsDialog::database(const QString &database)
{
  ui_->databaseLine->setText(database);
}

QString SettingsDialog::password()
{
  return ui_->passwordLine->text();
}

void SettingsDialog::password(const QString &password)
{
  ui_->passwordLine->setText(password);
}

SettingsDialog::~SettingsDialog()
{
}
