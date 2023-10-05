#include "Auto.hpp"

Auto::Auto(Id_t id, NullableStr_t num, NullableStr_t color, NullableStr_t mark, Id_t personId) :
  id_(id),
  num_(std::move(num)),
  color_(std::move(color)),
  mark_(std::move(mark)),
  personId_(std::move(personId))
{}

Auto::Id_t Auto::id() const
{
  return id_;
}

const Auto::NullableStr_t &Auto::num() const
{
  return num_;
}

const Auto::NullableStr_t &Auto::color() const
{
  return color_;
}

const Auto::NullableStr_t &Auto::mark() const
{
  return mark_;
}

Auto::Id_t Auto::personId() const
{
  return personId_;
}
