#include "Person.hpp"

Person::Person(Id_t id, std::string firstName, std::string secondName, std::string fatherName) :
  id_(id),
  firstName_(std::move(firstName)),
  secondName_(std::move(secondName)),
  fatherName_(std::move(fatherName))
{
}

Person::Id_t Person::getId() const
{
  return id_;
}

const std::string &Person::getFirstName() const
{
  return firstName_;
}

const std::string &Person::getSecondName() const
{
  return secondName_;
}

const std::string &Person::getFatherName() const
{
  return fatherName_;
}
