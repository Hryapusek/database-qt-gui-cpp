#ifndef AUTO_HPP
#define AUTO_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>

#include <optional>
#include <memory>
#include <string>

class Person;

#pragma db object table("AUTO") pointer(std::tr1::shared_ptr)
class Auto
{
  using NullableStr_t = std::optional<std::string>;

public:
  using Id_t = long;
  Auto() = default;
  Auto(Id_t id, NullableStr_t num, NullableStr_t color, NullableStr_t mark, Id_t personId);

  Id_t id() const;
  void id(Id_t);
  const NullableStr_t &num() const;
  void num(NullableStr_t);
  const NullableStr_t &color() const;
  void color(NullableStr_t);
  const NullableStr_t &mark() const;
  void mark(NullableStr_t);
  std::shared_ptr<Person> person() const;

private:
  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  Id_t id_;

  #pragma db access(num) null column("NUM") type("VARCHAR(20)")
  NullableStr_t num_;

  #pragma db access(color) null column("COLOR") type("VARCHAR(20)")
  NullableStr_t color_;

  #pragma db access(mark) null column("MARK") type("VARCHAR(20)")
  NullableStr_t mark_;

  #pragma db column("PERSONNEL_ID")
  std::shared_ptr<Person> person_;

};

#ifdef ODB_COMPILER
  #include "Person.hpp"
#endif

#endif
