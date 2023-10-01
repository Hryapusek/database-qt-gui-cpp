#include "Utils.hpp"
#include <memory>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string StringUtils::to_string(time_t time)
{
  std::tm *tmPtr = std::localtime(&time);
  char buffer[32];
  std::strftime(buffer, 32, "%d.%m.%Y %H:%M:%S", tmPtr);
  return std::string(buffer);
}

time_t StringUtils::timeFromString(std::string timeStr)
{
  std::tm tm;
  std::istringstream ss(std::move(timeStr));
  ss >> std::get_time(&tm, "%d.%m.%Y %H:%M:%S");
  if (!ss)
    throw std::logic_error("Bad time format");
  return mktime(&tm);
}
