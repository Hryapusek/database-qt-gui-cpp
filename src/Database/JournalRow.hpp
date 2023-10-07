#ifndef JOURNAL_ROW_HPP
#define JOURNAL_ROW_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>
#include <odb/nullable.hxx>

#include <string>

class Auto;
class Route;

#pragma db object table("JOURNAL") pointer(std::tr1::shared_ptr)
class JournalRow
{
public:
  using Id_t = long;

  template < class T >
  using Sh_Ptr_t = std::tr1::shared_ptr< T >;

  JournalRow() = default;
  JournalRow(long id, odb::nullable< time_t > timeOut, odb::nullable< time_t > timeIn, Sh_Ptr_t< Auto > autoObj, Sh_Ptr_t< Route > route);

  long id() const;
  void id(long);

  odb::nullable< time_t > timeOut() const;
  void timeOut(odb::nullable< time_t >);

  odb::nullable< time_t > timeIn() const;
  void timeIn(odb::nullable< time_t >);

  Sh_Ptr_t< Auto > autoObj();
  void autoObj(Sh_Ptr_t< Auto >);

  Sh_Ptr_t< Route > route();
  void route(Sh_Ptr_t< Route >);

private:

  friend class odb::access;

  #pragma db id auto column("ID") access(id)
  long id_;

  #pragma db access(timeOut) null column("TIME_OUT") type("TIMESTAMP")
  odb::nullable< time_t > timeOut_;

  #pragma db access(timeIn) null column("TIME_IN") type("TIMESTAMP")
  odb::nullable< time_t > timeIn_;

  #pragma db column("ROUTE_ID")
  Sh_Ptr_t< Route > route_;

  #pragma db column("AUTO_ID")
  Sh_Ptr_t< Auto > auto_;
};

#ifdef ODB_COMPILER
 #include "Route.hpp"
 #include "Auto.hpp"
#endif

#endif
