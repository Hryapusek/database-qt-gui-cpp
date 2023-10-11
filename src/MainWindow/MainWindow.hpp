#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

namespace details_
{
  struct MainWindowPimpl;
}

class MainWindow: public QMainWindow
{
  Q_OBJECT

  using MainWindowPimpl = details_::MainWindowPimpl;

public:
  MainWindow();
  virtual ~MainWindow();

private slots:
  void resetConnectionClicked();
  void settings();
  void settingsApply();

private:
  static const std::string settingsFile;
  std::unique_ptr< MainWindowPimpl > pimpl_;
  void refreshTables();
  void clearTables();
  bool resetConnection();
};

#endif
