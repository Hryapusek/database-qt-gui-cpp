#ifndef AUTO_HPP
#define AUTO_HPP

#include <string>

class Auto
{
public:
  using Id_t = long;
  Auto(Id_t id, std::string num, std::string color, std::string mark, Id_t personId);

  Id_t getId() const;
  const std::string &getNum() const;
  const std::string &getColor() const;
  const std::string &getMark() const;
  Id_t getPersonId() const;

private:
  Id_t id_;
  std::string num_;
  std::string color_;
  std::string mark_;
  Id_t personId_;
};

#endif
