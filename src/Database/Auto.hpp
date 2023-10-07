#ifndef AUTO_HPP
#define AUTO_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>
#include <odb/nullable.hxx>

#include <string>

class Person;
#include "Person.hpp"

#pragma db object table("AUTO") pointer(std::tr1::shared_ptr)
class Auto
{
public:
  using Id_t = long;

  template < class T >
  using Sh_Ptr_t = std::tr1::shared_ptr< T >;

  using NullableStr_t = odb::nullable< std::string >;
  Auto() = default;
  Auto(long id, NullableStr_t num, NullableStr_t color, NullableStr_t mark, Sh_Ptr_t< Person > person);

  long id() const;
  void id(long);
  const NullableStr_t &num() const;
  void num(NullableStr_t);
  const NullableStr_t &color() const;
  void color(NullableStr_t);
  const NullableStr_t &mark() const;
  void mark(NullableStr_t);
  Sh_Ptr_t< Person > person() const;
  void person(Sh_Ptr_t< Person >);

private:
  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  long id_;

  #pragma db access(num) null column("NUM") type("VARCHAR(20)")
  NullableStr_t num_;

  #pragma db access(color) null column("COLOR") type("VARCHAR(20)")
  NullableStr_t color_;

  #pragma db access(mark) null column("MARK") type("VARCHAR(20)")
  NullableStr_t mark_;

  #pragma db column("PERSONNEL_ID") on_delete(cascade)
  Sh_Ptr_t< Person > person_;

};

#ifdef ODB_COMPILER
  #include "Person.hpp"
#endif

#endif
