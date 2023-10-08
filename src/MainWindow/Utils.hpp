#ifndef TABS_UTILS_HPP
#define TABS_UTILS_HPP

#include <string>

class StringUtils
{
public:
  static std::string timeMicrosecFrom2000ToString(time_t time);
  
  /// @brief Tries to read time from string in format d.m.Y H:M:S and returns time_t.
  static time_t stringToMicrosecFrom2000(std::string timeStr, bool *ok = nullptr);
};

#endif
