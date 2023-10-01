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