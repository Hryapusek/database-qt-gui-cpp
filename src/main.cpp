#include <QApplication>
#include <QResource>
#include "MainWindow/MainWindow.hpp"
#include "Database/DatabaseConnection.hpp"

#include <iostream>


int main(int argc, char **argv)
{
  DatabaseConnection::resetConnection("database1", "hryapusek", "password");
  QApplication app(argc, argv);
  QResource::registerResource("res/resList.rcc");
  MainWindow window;
  window.show();
  return app.exec();
}
