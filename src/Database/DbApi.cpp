#include "DbApi.hpp"
#include "DatabaseConnection.hpp"

#include "Person-odb.hxx"
#include "Auto-odb.hxx"
#include "JournalRow-odb.hxx"
#include "Route-odb.hxx"

#include <odb/transaction.hxx>
#include <odb/database.hxx>
#include <odb/core.hxx>

std::vector< Person > DbApi::getPersons()
{
  odb::transaction tr(DatabaseConnection::connection()->begin());
  auto result = DatabaseConnection::connection()->query< Person >();
  std::vector< Person > persons;
  std::move(result.begin(), result.end(), std::back_inserter(persons));
  tr.commit();
  return persons;
}

std::vector< Auto > DbApi::getAutos()
{
  odb::transaction tr(DatabaseConnection::connection()->begin());
  auto result = DatabaseConnection::connection()->query< Auto >();
  std::vector< Auto > autos;
  std::move(result.begin(), result.end(), std::back_inserter(autos));
  tr.commit();
  return autos;
}

std::vector< Route > DbApi::getRoutes()
{
  odb::transaction tr(DatabaseConnection::connection()->begin());
  auto result = DatabaseConnection::connection()->query< Route >();
  std::vector< Route > routes;
  std::move(result.begin(), result.end(), std::back_inserter(routes));
  tr.commit();
  return routes;
}

std::vector< JournalRow > DbApi::getJournalRows()
{
  odb::transaction tr(DatabaseConnection::connection()->begin());
  auto result = DatabaseConnection::connection()->query< JournalRow >();
  std::vector< JournalRow > journalRows;
  std::move(result.begin(), result.end(), std::back_inserter(journalRows));
  tr.commit();
  return journalRows;
}

void DbApi::removePerson(Person::Id_t id)
{
  odb::transaction tr(DatabaseConnection::connection()->begin());
  DatabaseConnection::connection()->erase<Person>(id);
  tr.commit();
  return;
}
