#include "DbApi.hpp"
#include "DatabaseConnection.hpp"

#include "Person-odb.hxx"
#include "Auto-odb.hxx"
#include "JournalRow-odb.hxx"
#include "Route-odb.hxx"

#include <odb/transaction.hxx>
#include <odb/database.hxx>
#include <odb/core.hxx>

namespace
{
  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::exception
  template < class T >
  void removeObject(typename T::Id_t id)
  {
    odb::transaction tr(DatabaseConnection::connection()->begin());
    DatabaseConnection::connection()->template erase< T >(id);
    tr.commit();
    return;
  }

  /// @throw odb::exception
  template < class T >
  std::vector< T > getObjects()
  {
    odb::transaction tr(DatabaseConnection::connection()->begin());
    auto result = DatabaseConnection::connection()->template query< T >();
    typename std::vector< T > objects;
    std::move(result.begin(), result.end(), std::back_inserter(objects));
    tr.commit();
    return objects;
  }

  /// @throw odb::object_not_persistent if person with given id not found
  /// @throw odb::database_exception if data is not valid
  /// @throw odb::exception
  template < class T >
  void updateObject(T &&obj)
  {
    odb::transaction tr(DatabaseConnection::connection()->begin());
    auto objToUpdate = DatabaseConnection::connection()->load< T >(obj.id());
    *objToUpdate = std::forward< std::decay_t< T > >(obj);
    DatabaseConnection::connection()->update(objToUpdate);
    tr.commit();
  }
}

std::vector< Person > DbApi::getPersons()
{
  return getObjects< Person >();
}

std::vector< Auto > DbApi::getAutos()
{
  return getObjects< Auto >();
}

std::vector< Route > DbApi::getRoutes()
{
  return getObjects< Route >();
}

std::vector< JournalRow > DbApi::getJournalRows()
{
  return getObjects< JournalRow >();
}

void DbApi::removePerson(Person::Id_t id)
{
  removeObject< Person >(id);
  return;
}

void DbApi::removeAuto(Auto::Id_t id)
{
  removeObject< Auto >(id);
  return;
}

void DbApi::removeRoute(Route::Id_t id)
{
  removeObject< Route >(id);
  return;
}

void DbApi::removeJournalRow(JournalRow::Id_t id)
{
  removeObject< JournalRow >(id);
  return;
}

void DbApi::updatePerson(Person person)
{
  updateObject< Person >(std::move(person));
  return;
}

void DbApi::updateAuto(Auto autoObj)
{
  updateObject< Auto >(std::move(autoObj));
  return;
}

void DbApi::updateRoute(Route route)
{
  updateObject< Route >(std::move(route));
  return;
}

void DbApi::updateJournalRow(JournalRow journalRow)
{
  updateObject< JournalRow >(std::move(journalRow));
  return;
}
