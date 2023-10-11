#include "MainWindow.hpp"
#include "UiMainWindow.hpp"

#include "Database/DatabaseConnection.hpp"

#include "Person/PersonTab.hpp"
#include "Auto/AutoTab.hpp"
#include "Route/RouteTab.hpp"
#include "Journal/JournalTab.hpp"
#include "Settings/SettingsDialog.hpp"
#include "Settings/Settings.hpp"

#include <odb/exception.hxx>
#include <QPushButton>
#include <QMessageBox>

namespace details_
{
  struct MainWindowPimpl
  {
    std::unique_ptr< Ui::MainWindow > ui;
    std::unique_ptr< PersonTab > personTab;
    std::unique_ptr< AutoTab > autoTab;
    std::unique_ptr< RouteTab > routeTab;
    std::unique_ptr< JournalTab > journalTab;
    std::unique_ptr< SettingsDialog > settingsDialog;
  };
}

const std::string MainWindow::settingsFile = "settings.json";

MainWindow::MainWindow() :
  pimpl_(std::make_unique< MainWindowPimpl >())
{
  pimpl_->ui = std::make_unique< Ui::MainWindow >();
  pimpl_->ui->setupUi(this);
  pimpl_->personTab = std::make_unique< PersonTab >(
    pimpl_->ui->personnelTable,
    pimpl_->ui->addPersonBtn,
    pimpl_->ui->removePersonBtn,
    pimpl_->ui->refreshPersonBtn
    );

  pimpl_->autoTab = std::make_unique< AutoTab >(
    pimpl_->ui->autoTable,
    pimpl_->ui->addAutoBtn,
    pimpl_->ui->removeAutoBtn,
    pimpl_->ui->refreshAutoBtn
    );

  pimpl_->routeTab = std::make_unique< RouteTab >(
    pimpl_->ui->routeTable,
    pimpl_->ui->addRouteBtn,
    pimpl_->ui->removeRouteBtn,
    pimpl_->ui->refreshRouteBtn
    );

  pimpl_->journalTab = std::make_unique< JournalTab >(
    pimpl_->ui->journalTable,
    pimpl_->ui->addJournalRowBtn,
    pimpl_->ui->removeJournalRowBtn,
    pimpl_->ui->refreshJournalBtn
    );

  QObject::connect(pimpl_->personTab.get(), &PersonTab::refreshTablesSig, this, &MainWindow::refreshTables);
  QObject::connect(pimpl_->autoTab.get(), &AutoTab::refreshTablesSig, this, &MainWindow::refreshTables);
  QObject::connect(pimpl_->routeTab.get(), &RouteTab::refreshTablesSig, this, &MainWindow::refreshTables);
  QObject::connect(pimpl_->journalTab.get(), &JournalTab::refreshTablesSig, this, &MainWindow::refreshTables);
  QObject::connect(pimpl_->ui->resetBtn, &QPushButton::clicked, this, &MainWindow::resetConnectionClicked);
  QObject::connect(pimpl_->ui->settingsBtn, &QPushButton::clicked, this, &MainWindow::settings);
  try
  {
    Settings::read(settingsFile);
  }
  catch (const std::exception &e)
  {
    QMessageBox::critical(this, "Fatal", "Bad settings file found. Application will be closed now", QMessageBox::Close);
    QApplication::quit();
  }
  if (resetConnection())
    refreshTables();
  else
    QMessageBox::warning(this, "Connection error", "Can not establish connection to database. Please check settings", QMessageBox::Close);
}

void MainWindow::refreshTables()
{
  pimpl_->personTab->refreshTable();
  pimpl_->autoTab->refreshTable();
  pimpl_->routeTab->refreshTable();
  pimpl_->journalTab->refreshTable();
}

void MainWindow::clearTables()
{
  pimpl_->personTab->clearTable();
  pimpl_->autoTab->clearTable();
  pimpl_->routeTab->clearTable();
  pimpl_->journalTab->clearTable();
}

void MainWindow::resetConnectionClicked()
{
  if (resetConnection())
  {
    QMessageBox::information(this, "Success!", "Connection established", QMessageBox::Ok);
    refreshTables();
  }
  else
  {
    QMessageBox::critical(this, "Fail",
      "Could not establish conneciton with database. Please check settings",
      QMessageBox::Close);
    clearTables();
  }
}

bool MainWindow::resetConnection()
{
  try
  {
    DatabaseConnection::resetConnection(
      Settings::database(),
      Settings::username(),
      Settings::password()
      );
    return true;
  }
  catch (const odb::exception &e)
  {
    return false;
  }
}

void MainWindow::settings()
{
  auto &settingsDialog = pimpl_->settingsDialog;
  if (!settingsDialog)
  {
    settingsDialog = std::make_unique< SettingsDialog >(this);
    QObject::connect(settingsDialog.get(), &SettingsDialog::apply, this, &MainWindow::settingsApply);
  }
  settingsDialog->username(QString::fromStdString(Settings::username()));
  settingsDialog->database(QString::fromStdString(Settings::database()));
  settingsDialog->password(QString::fromStdString(Settings::password()));
  if (settingsDialog->exec() == QDialog::Accepted)
    settingsApply();
}

void MainWindow::settingsApply()
{
  Settings::username(pimpl_->settingsDialog->username().toStdString());
  Settings::database(pimpl_->settingsDialog->database().toStdString());
  Settings::password(pimpl_->settingsDialog->password().toStdString());
  Settings::write(settingsFile);
  resetConnectionClicked();
}

MainWindow::~MainWindow()
{ }
