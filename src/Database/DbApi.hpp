#ifndef DB_API_HPP
#define DB_API_HPP

#include <vector>
#include "Person.hpp"
#include "Auto.hpp"
#include "Route.hpp"
#include "JournalRow.hpp"

class DbApi
{
public:
  /// @throw odb::exception if something goes wrong
  static std::vector< Person > getPersons();

  /// @throw odb::exception if something goes wrong
  static std::vector< Auto > getAutos();

  /// @throw odb::exception if something goes wrong
  static std::vector< Route > getRoutes();

  /// @throw odb::exception if something goes wrong
  static std::vector< JournalRow > getJournalRows();

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::exception if something goes wrong
  static void removePerson(Person::Id_t id);
};

#endif
