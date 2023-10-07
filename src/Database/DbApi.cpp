#include "DbApi.hpp"
#include "DatabaseConnection.hpp"

#include "Person-odb.hxx"

#include <odb/transaction.hxx>
#include <odb/database.hxx>

std::vector< Person > DbApi::getPersons()
{
  odb::transaction tr(DatabaseConnection::connection()->begin());
  auto result = DatabaseConnection::connection()->query<Person>();
  std::vector< Person > persons;
  std::move(result.begin(), result.end(), std::back_inserter(persons));
  return persons;
  // static std::vector< Person > persons {
  //   Person(1, "sas", "sas", "damn"),
  // };
  // static int id = 2;
  // persons.emplace_back(id++, "sas", "sas", "damn");
  // return (id%2 == 0 ? persons : std::vector< Person >());
}

std::vector<Auto> DbApi::getAutos()
{
  return std::vector<Auto>();
}

std::vector<Route> DbApi::getRoutes()
{
  return std::vector<Route>();
}

std::vector<JournalRow> DbApi::getJournalRows()
{
  static std::vector<JournalRow> journalRows {{
    //JournalRow(1, 10000000, 20000000, 1, 2)
  }};
  return journalRows;
}
