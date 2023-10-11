#include <QApplication>
#include <QResource>
#include "MainWindow/MainWindow.hpp"
#include "Database/DatabaseConnection.hpp"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  QResource::registerResource("res/resList.rcc");
  MainWindow window;
  window.show();
  return app.exec();
}
