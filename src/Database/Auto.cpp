#include "Auto.hpp"

Auto::Auto(Id_t id, std::string num, std::string color, std::string mark, Id_t personId) :
  id_(id),
  num_(std::move(num)),
  color_(std::move(color)),
  mark_(std::move(mark)),
  personId_(std::move(personId))
{

}

Auto::Id_t Auto::getId() const
{
  return id_;
}

const std::string & Auto::getNum() const
{
  return num_;
}

const std::string & Auto::getColor() const
{
  return color_;
}

const std::string & Auto::getMark() const
{
  return mark_;
}

Auto::Id_t Auto::getPersonId() const
{
  return personId_;
}
