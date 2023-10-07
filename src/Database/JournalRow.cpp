#include "JournalRow.hpp"

JournalRow::JournalRow(long id, odb::nullable< time_t > timeOut, odb::nullable< time_t > timeIn, Sh_Ptr_t< Auto > autoObj, Sh_Ptr_t< Route > route) :
  id_(id),
  timeOut_(timeOut),
  timeIn_(timeIn),
  auto_(std::move(autoObj)),
  route_(std::move(route))
{}

long JournalRow::id() const
{
  return id_;
}

odb::nullable<time_t> JournalRow::timeOut() const
{
  return timeOut_;
}

odb::nullable<time_t> JournalRow::timeIn() const
{
  return timeIn_;
}

JournalRow::Sh_Ptr_t< Auto > JournalRow::autoObj() const
{
  return auto_;
}

void JournalRow::autoObj(Sh_Ptr_t< Auto > autoObj)
{
  auto_ = std::move(autoObj);
}

JournalRow::Sh_Ptr_t< Route > JournalRow::route() const
{
  return route_;
}

void JournalRow::route(Sh_Ptr_t< Route > route)
{
  route_ = std::move(route);
}

void JournalRow::id(long id)
{
  id_ = id;
}

void JournalRow::timeOut(odb::nullable<time_t> timeOut)
{
  timeOut_ = timeOut;
}

void JournalRow::timeIn(odb::nullable<time_t> timeIn)
{
  timeIn_ = timeIn;
}
