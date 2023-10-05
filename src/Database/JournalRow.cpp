#include "JournalRow.hpp"

JournalRow::JournalRow(Id_t id, std::optional< time_t > timeOut, std::optional< time_t > timeIn, Id_t autoId, Id_t routeId) :
  id_(id),
  timeOut_(timeOut),
  timeIn_(timeIn),
  autoId_(autoId),
  routeId_(routeId)
{

}

JournalRow::Id_t JournalRow::id() const
{
  return id_;
}

std::optional<time_t> JournalRow::timeOut() const
{
  return timeOut_;
}

std::optional<time_t> JournalRow::timeIn() const
{
  return timeIn_;
}

JournalRow::Id_t JournalRow::autoId() const
{
  return autoId_;
}

JournalRow::Id_t JournalRow::routeId() const
{
  return routeId_;
}
