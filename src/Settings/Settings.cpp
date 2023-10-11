#include "Settings.hpp"
#include <jsoncpp/json/json.h>
#include <fstream>

Settings::Settings_ Settings::settings = Settings_();

void Settings::read(std::string file)
{
  std::ifstream settingsFile(file);
  if (!settingsFile.is_open())
    return;
  Json::Value root;
  Json::CharReaderBuilder builder;
  if (!parseFromStream(builder, settingsFile, &root, nullptr))
    throw Json::Exception("Error while parsing settings.json");
  if (root.isMember("username"))
    settings.username = root["username"].asString();
  if (root.isMember("database"))
    settings.database = root["database"].asString();
  if (root.isMember("password"))
    settings.password = root["password"].asString();
}

void Settings::write(std::string file)
{
  std::ofstream out(file);
  if (!out)
    throw std::logic_error("Can not open the file to save config");

  Json::Value root;
  root["username"] = settings.username;
  root["database"] = settings.database;
  root["password"] = settings.password;

  Json::StreamWriterBuilder builder;
  const std::unique_ptr< Json::StreamWriter > writer(builder.newStreamWriter());
  writer->write(root, &out);
  if (!out)
    throw std::logic_error("Error writing config file");
}

const std::string &Settings::username()
{
  return settings.username;
}

void Settings::username(std::string username)
{
  settings.username = std::move(username);
}

const std::string &Settings::password()
{
  return settings.password;
}

void Settings::password(std::string password)
{
  settings.password = std::move(password);
}

const std::string &Settings::database()
{
  return settings.database;
}

void Settings::database(std::string database)
{
  settings.database = std::move(database);
}
