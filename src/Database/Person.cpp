#include "Person.hpp"

Person::Person(Id_t id, std::string firstName, std::string secondName, std::string fatherName) :
  id_(id),
  firstName_(std::move(firstName)),
  secondName_(std::move(secondName)),
  fatherName_(std::move(fatherName))
{ }

Person::Id_t Person::id() const
{
  return id_;
}

void Person::id(Id_t id)
{
  id_ = id;
}

const Person::NullableStr_t &Person::firstName() const
{
  return firstName_;
}

void Person::firstName(NullableStr_t firstName)
{
  firstName_ = std::move(firstName);
}

const Person::NullableStr_t &Person::secondName() const
{
  return secondName_;
}

void Person::secondName(NullableStr_t secondName)
{
  secondName_ = std::move(secondName);
}

const Person::NullableStr_t &Person::fatherName() const
{
  return fatherName_;
}

void Person::fatherName(NullableStr_t fatherName)
{
  fatherName_ = std::move(fatherName);
}
