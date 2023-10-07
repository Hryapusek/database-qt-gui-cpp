#include "Route.hpp"

Route::Route(long id, std::string name) :
  id_(id),
  name_(std::move(name))
{ }

long Route::id() const
{
  return id_;
}

void Route::id(long id)
{
  id_ = id;
}

const Route::NullableStr_t &Route::name() const
{
  return name_;
}

void Route::name(NullableStr_t name)
{
  name_ = std::move(name);
}
