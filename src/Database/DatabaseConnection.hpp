#ifndef DB_CONNECTION_HPP
#define DB_CONNECTION_HPP

#include <memory>
#include <odb/core.hxx>

class DatabaseConnection
{
public:
  /// @brief Make sure @ref resetConnection was called at least once before usage
  static std::shared_ptr<odb::database> database();
  
  /// @brief Tries to establish connection with given parameters
  /// @throw odb::exception
  static void resetConnection(std::string database, std::string username, std::string password);

private:
  static std::shared_ptr<odb::database> database_;
};

#endif
