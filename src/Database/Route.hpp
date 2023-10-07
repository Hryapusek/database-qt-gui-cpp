#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>
#include <odb/nullable.hxx>

#include <string>


#pragma db object table("ROUTES") pointer(std::tr1::shared_ptr)
class Route
{
public:
  using Id_t = long;
  using NullableStr_t = odb::nullable< std::string >;
  Route() = default;
  Route(long id, std::string name);

  long id() const;
  void id(long);
  const NullableStr_t &name() const;
  void name(NullableStr_t);

private:

  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  long id_;

  #pragma db access(name) null column("NAME") type("VARCHAR(50)")
  NullableStr_t name_;
};

#endif
