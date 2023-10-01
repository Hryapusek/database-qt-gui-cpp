#ifndef JOURNAL_ROW_HPP
#define JOURNAL_ROW_HPP

#include <string>
#include <optional>

class JournalRow
{
public:
  using Id_t = long;
  JournalRow(Id_t id, std::optional< time_t > timeOut, std::optional< time_t > timeIn, Id_t autoId, Id_t routeId);

  Id_t getId() const;
  std::optional< time_t > getTimeOut() const;
  std::optional< time_t > getTimeIn() const;
  Id_t getAutoId() const;
  Id_t getRouteId() const;

private:
  Id_t id_;
  std::optional< time_t > timeOut_;
  std::optional< time_t > timeIn_;
  Id_t autoId_;
  Id_t routeId_;
};

#endif
