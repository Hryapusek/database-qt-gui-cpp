#include "Utils.hpp"
#include <memory>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string StringUtils::timeMicrosecFrom2000ToString(time_t time)
{
  static auto microsecFrom2000ToUnix = [](time_t time) -> time_t
  {
    static const time_t SECONDS_YEAR2000 = 946684800;
    static const time_t toSeconds = 1e6;
    time_t resTime = time / toSeconds;
    resTime += SECONDS_YEAR2000;
    return resTime;
  };
  auto unixTime = microsecFrom2000ToUnix(time);
  std::ostringstream ss;
  ss << std::put_time(std::gmtime(&unixTime), "%d.%m.%Y %H:%M:%S");
  return ss.str();
}

time_t StringUtils::stringToMicrosecFrom2000(std::string timeStr, bool *ok)
{
  auto setGood = 
  [ok](bool val)
  { 
    if (ok)
      *ok = val;
  };
  static auto unixToMicrosecFrom2000 = 
  [](time_t time) -> time_t
  {
    static const time_t SECONDS_YEAR2000 = 946684800;
    static const time_t toMicroSeconds = 1e6;
    time_t resTime = time - SECONDS_YEAR2000;
    resTime *= toMicroSeconds;
    return resTime;
  };
  std::tm tm;
  std::istringstream ss(std::move(timeStr));
  ss >> std::get_time(&tm, "%d.%m.%Y %H:%M:%S");
  if (!ss)
  {
    setGood(false);
    return 0;
  }
  setGood(true);
  return unixToMicrosecFrom2000(mktime(&tm));
}
