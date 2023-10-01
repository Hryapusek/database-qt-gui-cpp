#include "MainWindow.hpp"
#include "UiMainWindow.hpp"

#include <QPushButton>
#include <iostream>

#include "Database/DbApi.hpp"
#include "Tabs/PersonTab.hpp"
#include "Tabs/AutoTab.hpp"
#include "Tabs/RouteTab.hpp"
#include "Tabs/JournalTab.hpp"

namespace details_
{
  struct MainWindowPimpl
  {
    std::unique_ptr< Ui::MainWindow > ui;
    std::unique_ptr< PersonTab > personTab;
    std::unique_ptr< AutoTab > autoTab;
    std::unique_ptr< RouteTab > routeTab;
    std::unique_ptr< JournalTab > journalTab;
  };
}

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
  refreshTables();
}

MainWindow::~MainWindow()
{ }

void MainWindow::refreshTables()
{
  pimpl_->personTab->refreshTable();
  pimpl_->autoTab->refreshTable();
  pimpl_->routeTab->refreshTable();
  pimpl_->journalTab->refreshTable();
}
