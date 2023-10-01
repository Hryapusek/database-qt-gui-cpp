#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>

class Route
{
public:
  using Id_t = long;
  Route(Id_t id, std::string name);

  Id_t getId() const;
  const std::string &getName() const;

private:
  Id_t id_;
  std::string name_;
};

#endif
