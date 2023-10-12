#include "DatabaseConnection.hpp"
#include <utility>
#include <odb/database.hxx>
#include <odb/pgsql/database.hxx>

std::shared_ptr< odb::database > DatabaseConnection::database_ = nullptr;

std::shared_ptr<odb::database> DatabaseConnection::database()
{
  if (database_ == nullptr)
    throw odb::connection_lost{};
  return database_;
}

void DatabaseConnection::resetConnection(std::string database, std::string username, std::string password)
{
  database_ = std::make_shared< odb::pgsql::database >(username, password, database);
  database_->connection()->execute("");
  return;
}
