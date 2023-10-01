#ifndef DB_API_HPP
#define DB_API_HPP

#include <vector>
#include "Person.hpp"
#include "Auto.hpp"

class DbApi
{
public:
  static std::vector< Person > getPersons();
  static std::vector< Auto > getAutos();
};

#endif
