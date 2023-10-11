#ifndef SETTINGS_DIALOG_HPP
#define SETTINGS_DIALOG_HPP

#include <QDialog>

namespace Ui
{
  class SettingsDialog;
}

class SettingsDialog : public QDialog
{
  Q_OBJECT

public:
  SettingsDialog(QWidget *parent = nullptr);
  virtual ~SettingsDialog();
  QString username();
  void username(const QString &);
  QString database();
  void database(const QString &);
  QString password();
  void password(const QString &);

signals:
  void apply();

private:
  std::unique_ptr<Ui::SettingsDialog> ui_;

};

#endif
