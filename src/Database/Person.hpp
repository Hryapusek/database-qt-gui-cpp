#ifndef PERSON_HPP
#define PERSON_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>

#include <vector>
#include <memory>
#include <optional>
#include <string>

class Auto;

#pragma db object table("AUTO_PERSONNEL") pointer(std::tr1::shared_ptr)
class Person
{
  using NullableStr_t = std::optional<std::string>;
public:
  using Id_t = long;
  Person() = default;
  Person(Id_t id, std::string firstName, std::string secondName, std::string fatherName);

  Id_t id() const;
  void id(Id_t);
  const NullableStr_t &firstName() const;
  void firstName(const NullableStr_t &);
  const NullableStr_t &secondName() const;
  void secondName(const NullableStr_t &);
  const NullableStr_t &fatherName() const;
  void fatherName(const NullableStr_t &);

private:
  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  Id_t id_;

  #pragma db access(firstName) null column("FIRST_NAME") type("VARCHAR(20)")
  NullableStr_t firstName_;
  
  #pragma db access(secondName) null column("SECOND_NAME") type("VARCHAR(20)")
  NullableStr_t secondName_;

  #pragma db access(fatherName) null column("FATHER_NAME") type("VARCHAR(20)")
  NullableStr_t fatherName_;
  
};

#endif
