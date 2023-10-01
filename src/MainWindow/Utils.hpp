#ifndef TABS_UTILS_HPP
#define TABS_UTILS_HPP

#include <string>

class StringUtils
{
public:
  static std::string to_string(time_t time);
  
  /// @brief Tries to read time from string in format d.m.Y H:M:S and returns time_t
  /// @throw std::logic_error if bad time format
  static time_t timeFromString(std::string timeStr);
};

#endif
