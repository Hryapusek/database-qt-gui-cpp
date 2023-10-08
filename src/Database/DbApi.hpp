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

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static std::tr1::shared_ptr< Person > getPerson(Person::Id_t);

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static std::tr1::shared_ptr< Auto > getAuto(Auto::Id_t);

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static std::tr1::shared_ptr< Route > getRoute(Route::Id_t);

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static std::tr1::shared_ptr< JournalRow > getJournalRow(JournalRow::Id_t);

  /// @throw odb::exception
  static std::vector< Person > getPersons();

  /// @throw odb::exception
  static std::vector< Auto > getAutos();

  /// @throw odb::exception
  static std::vector< Route > getRoutes();

  /// @throw odb::exception
  static std::vector< JournalRow > getJournalRows();

  /// @throw odb::object_already_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static Person::Id_t addPerson(const Person &person);

  /// @throw odb::object_already_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static Auto::Id_t addAuto(const Auto &autoObj);

  /// @throw odb::object_already_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static Route::Id_t addRoute(const Route &route);

  /// @throw odb::object_already_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static JournalRow::Id_t addJournalRow(const JournalRow &journalRow);

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static void removePerson(Person::Id_t id);

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static void removeAuto(Auto::Id_t id);

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static void removeRoute(Route::Id_t id);

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  static void removeJournalRow(JournalRow::Id_t id);

  /// @throw odb::object_not_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static void updatePerson(Person person);

  /// @throw odb::object_not_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static void updateAuto(Auto autoObj);

  /// @throw odb::object_not_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static void updateRoute(Route route);

  /// @throw odb::object_not_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  static void updateJournalRow(JournalRow journalRow);
};

#endif
