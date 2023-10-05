#ifndef JOURNAL_ROW_HPP
#define JOURNAL_ROW_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>

#include <string>
#include <optional>
#include <memory>

class Auto;
class Route;

#pragma db object table("JOURNAL") pointer(std::tr1::shared_ptr)
class JournalRow
{
public:
  using Id_t = long;
  JournalRow() = default;
  JournalRow(Id_t id, std::optional< time_t > timeOut, std::optional< time_t > timeIn, Id_t autoId, Id_t routeId);

  Id_t id() const;
  void id(Id_t);

  std::optional< time_t > timeOut() const;
  void timeOut(std::optional< time_t >);

  std::optional< time_t > timeIn() const;
  void timeIn(std::optional< time_t >);

  std::shared_ptr< Auto > autoObj();
  std::shared_ptr< Route > route();

  void setIds();

private:

  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  Id_t id_;

  #pragma db access(timeOut) null column("TIME_OUT") type("TIMESTAMP")
  std::optional< time_t > timeOut_;

  #pragma db access(timeIn) null column("TIME_IN") type("TIMESTAMP")
  std::optional< time_t > timeIn_;

  #pragma db column("ROUTE_ID")
  std::shared_ptr< Route > route_;

  #pragma db column("AUTO_ID")
  std::shared_ptr< Auto > auto_;
};

#ifdef ODB_COMPILER
 #include "Route.hpp"
 #include "Auto.hpp"
#endif

#endif
