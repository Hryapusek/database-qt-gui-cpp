#ifndef PERSON_HPP
#define PERSON_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>
#include <odb/nullable.hxx>

#include <string>

class Auto;

#pragma db object table("AUTO_PERSONNEL") pointer(std::tr1::shared_ptr)
class Person
{
public:
  using Id_t = long;
  using NullableStr_t = odb::nullable< std::string >;
  Person() = default;
  Person(Id_t id, std::string firstName, std::string lastName, std::string fatherName);

  Id_t id() const;
  void id(Id_t);
  const NullableStr_t &firstName() const;
  void firstName(NullableStr_t firstName);
  const NullableStr_t &lastName() const;
  void lastName(NullableStr_t lastName);
  const NullableStr_t &fatherName() const;
  void fatherName(NullableStr_t fatherName);

private:
  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  long id_;

  #pragma db access(firstName) null column("FIRST_NAME") type("VARCHAR(20)")
  NullableStr_t firstName_;

  #pragma db access(lastName) null column("LAST_NAME") type("VARCHAR(20)")
  NullableStr_t lastName_;

  #pragma db access(fatherName) null column("PATHER_NAME") type("VARCHAR(20)")
  NullableStr_t fatherName_;

};

#endif
