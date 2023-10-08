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
  /// @throw odb::object_not_persistent
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

  /// @throw odb::object_not_persistent
  /// @throw odb::exception
  template < class T >
  std::tr1::shared_ptr< T > getObject(typename T::Id_t id)
  {
    odb::transaction tr(DatabaseConnection::connection()->begin());
    auto objPtr = DatabaseConnection::connection()->load< T >(id);
    tr.commit();
    return objPtr;
  }

  /// @throw odb::object_not_persistent
  /// @throw odb::database_exception
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

  /// @throw odb::object_already_persistent
  /// @throw odb::database_exception
  /// @throw odb::exception
  template < class T >
  typename T::Id_t addObject(T obj)
  {
    odb::transaction tr(DatabaseConnection::connection()->begin());
    auto id = DatabaseConnection::connection()->persist(obj);
    tr.commit();
    return id;
  }
}

std::tr1::shared_ptr< Person > DbApi::getPerson(Person::Id_t id)
{
  return getObject<Person>(id);
}

std::tr1::shared_ptr<Auto> DbApi::getAuto(Auto::Id_t id)
{
  return getObject<Auto>(id);
}

std::tr1::shared_ptr<Route> DbApi::getRoute(Route::Id_t id)
{
  return getObject<Route>(id);
}

std::tr1::shared_ptr<JournalRow> DbApi::getJournalRow(JournalRow::Id_t id)
{
  return getObject<JournalRow>(id);
}

std::vector<Person> DbApi::getPersons()
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

Person::Id_t DbApi::addPerson(const Person &person)
{
  return addObject< Person >(person);
}

Auto::Id_t DbApi::addAuto(const Auto &autoObj)
{
  return addObject< Auto >(autoObj);
}

Route::Id_t DbApi::addRoute(const Route &route)
{
  return addObject< Route >(route);
}

JournalRow::Id_t DbApi::addJournalRow(const JournalRow &journalRow)
{
  return addObject< JournalRow >(journalRow);
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
