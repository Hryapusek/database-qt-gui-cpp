#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

namespace details_
{
  struct MainWindowPimpl;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

  using MainWindowPimpl = details_::MainWindowPimpl;

public:
  MainWindow();
  virtual ~MainWindow();

private:
  std::unique_ptr<MainWindowPimpl> pimpl_;
  void refreshTables();
};

#endif
