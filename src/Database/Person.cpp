#include "Person.hpp"

Person::Person(Id_t id, std::string firstName, std::string secondName, std::string fatherName) :
  id_(id),
  firstName_(std::move(firstName)),
  secondName_(std::move(secondName)),
  fatherName_(std::move(fatherName))
{
}

Person::Id_t Person::id() const
{
  return id_;
}

const std::string &Person::firstName() const
{
  return *firstName_;
}

const std::string &Person::secondName() const
{
  return secondName_;
}

const std::string &Person::fatherName() const
{
  return fatherName_;
}
