#ifndef DB_CONNECTION_HPP
#define DB_CONNECTION_HPP

#include <memory>
#include <odb/core.hxx>

class DatabaseConnection
{
public:
  static std::shared_ptr<odb::database> connection();
  static void resetConnection(std::string database, std::string username, std::string password);

private:
  static std::shared_ptr<odb::database> database_;
};

#endif
