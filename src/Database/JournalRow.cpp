#include "JournalRow.hpp"

JournalRow::JournalRow(Id_t id, std::optional< time_t > timeOut, std::optional< time_t > timeIn, Id_t autoId, Id_t routeId) :
  id_(id),
  timeOut_(timeOut),
  timeIn_(timeIn),
  autoId_(autoId),
  routeId_(routeId)
{

}

JournalRow::Id_t JournalRow::getId() const
{
  return id_;
}

std::optional<time_t> JournalRow::getTimeOut() const
{
  return timeOut_;
}

std::optional<time_t> JournalRow::getTimeIn() const
{
  return timeIn_;
}

JournalRow::Id_t JournalRow::getAutoId() const
{
  return autoId_;
}

JournalRow::Id_t JournalRow::getRouteId() const
{
  return routeId_;
}
