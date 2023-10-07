#include "Auto.hpp"

Auto::Auto(long id, NullableStr_t num, NullableStr_t color, NullableStr_t mark, Sh_Ptr_t< Person > person) :
  id_(id),
  num_(std::move(num)),
  color_(std::move(color)),
  mark_(std::move(mark)),
  person_(std::move(person))
{ }

void Auto::id(long id)
{
  id_ = id;
}

void Auto::num(NullableStr_t num)
{
  num_ = std::move(num);
}

void Auto::color(NullableStr_t color)
{
  color_ = std::move(color);
}

void Auto::mark(NullableStr_t mark)
{
  mark_ = mark;
}

Auto::Sh_Ptr_t< Person > Auto::person() const
{
  return person_;
}

void Auto::person(Sh_Ptr_t< Person > person)
{
  person_ = std::move(person);
}

long Auto::id() const
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
