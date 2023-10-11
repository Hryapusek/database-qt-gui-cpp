#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>

class Settings
{
public:
  Settings() = delete;
  static void read(std::string file);
  static void write(std::string file);
  static const std::string &username();
  static void username(std::string);
  static const std::string &database();
  static void database(std::string);
  static const std::string &password();
  static void password(std::string);

private:
  struct Settings_
  {
    std::string username;
    std::string database;
    std::string password;
  };

  static Settings_ settings;
};

#endif
