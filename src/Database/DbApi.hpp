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
  /// @throw odb::exception
  static std::vector< Person > getPersons();

  /// @throw odb::exception
  static std::vector< Auto > getAutos();

  /// @throw odb::exception
  static std::vector< Route > getRoutes();

  /// @throw odb::exception
  static std::vector< JournalRow > getJournalRows();

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::exception
  static void removePerson(Person::Id_t id);

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::exception
  static void removeAuto(Auto::Id_t id);

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::exception
  static void removeRoute(Route::Id_t id);

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::exception
  static void removeJournalRow(JournalRow::Id_t id);

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::database_exception if data is not valid
  /// @throw odb::exception
  static void updatePerson(Person person);

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::database_exception if data is not valid
  /// @throw odb::exception
  static void updateAuto(Auto autoObj);

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::database_exception if data is not valid
  /// @throw odb::exception
  static void updateRoute(Route route);

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::database_exception if data is not valid
  /// @throw odb::exception
  static void updateJournalRow(JournalRow journalRow);
};

#endif
