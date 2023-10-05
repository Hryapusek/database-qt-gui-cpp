#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>
#include <odb/core.hxx>
#include <optional>
#include <memory>
#include <odb/tr1/memory.hxx>

#pragma db object table("ROUTES") pointer(std::tr1::shared_ptr)
class Route
{
  using NullableStr_t = std::optional<std::string>;
public:
  using Id_t = long;
  Route() = default;
  Route(Id_t id, std::string name);

  Id_t id() const;
  void id(Id_t);
  const NullableStr_t &name() const;
  void name(NullableStr_t);

private:

  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  Id_t id_;

  #pragma db access(name) null column("NAME") type("VARCHAR(50)")
  NullableStr_t name_;
};

#endif
