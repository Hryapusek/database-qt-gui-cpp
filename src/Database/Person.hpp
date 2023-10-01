#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{
public:
  using Id_t = long;
  Person(Id_t id, std::string firstName, std::string secondName, std::string fatherName);

  Id_t getId() const;
  const std::string &getFirstName() const;
  const std::string &getSecondName() const;
  const std::string &getFatherName() const;

private:
  Id_t id_;
  std::string firstName_;
  std::string secondName_;
  std::string fatherName_;
};

#endif
