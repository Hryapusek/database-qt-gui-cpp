#include "MainWindow.hpp"
#include "UiMainWindow.hpp"

#include <QPushButton>
#include <iostream>

#include "Database/DbApi.hpp"
#include "Tabs/PersonTab.hpp"

namespace details_
{
  struct MainWindowPimpl
  {
    std::unique_ptr< Ui::MainWindow > ui;
    std::unique_ptr< PersonTab > personTab;
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
    pimpl_->ui->refreshPerson
    );
  QObject::connect(pimpl_->personTab.get(), &PersonTab::refreshTablesSig, this, &MainWindow::refreshTables);
  refreshTables();
}

MainWindow::~MainWindow()
{ }

void MainWindow::refreshTables()
{
  pimpl_->personTab->refreshTable();
}
