#include "DatabaseConnection.hpp"
#include <utility>
#include <odb/database.hxx>
#include <odb/pgsql/database.hxx>

std::shared_ptr< odb::database > DatabaseConnection::database_ = nullptr;

std::shared_ptr<odb::database> DatabaseConnection::connection()
{
  assert(database_ != nullptr);
  return database_;
}

void DatabaseConnection::resetConnection(std::string database, std::string username, std::string password)
{
  database_ = std::make_shared< odb::pgsql::database >(username, password, database);
  return;
}
