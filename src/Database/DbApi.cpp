#include "DbApi.hpp"
#include "Person.hpp"

std::vector< Person > DbApi::getPersons()
{
  static std::vector< Person > persons {
    Person(1, "sas", "sas", "damn"),
  };
  static int id = 2;
  persons.emplace_back(id++, "sas", "sas", "damn");
  return (id%2 == 0 ? persons : std::vector< Person >());
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
    JournalRow(1, 10000000, 20000000, 1, 2)
  }};
  return journalRows;
}
