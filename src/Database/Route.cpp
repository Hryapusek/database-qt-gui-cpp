#include "Route.hpp"

Route::Route(Id_t id, std::string name) :
  id_(id),
  name_(std::move(name))
{}

Route::Id_t Route::getId() const
{
  return id_;
}

const std::string &Route::getName() const
{
  return name_;
}
