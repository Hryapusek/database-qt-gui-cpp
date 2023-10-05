#include "Route.hpp"

Route::Route(Id_t id, std::string name) :
  id_(id),
  name_(std::move(name))
{}

Route::Id_t Route::id() const
{
  return id_;
}

const Route::NullableStr_t &Route::name() const
{
  return name_;
}
