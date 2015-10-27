// Note: compile with -std=c++11

#include <string>
#include <unordered_set>

class person {
  std::string firstname, lastname;
  int birthyear, birthmonth, birthday;
};

std::unordered_set<person> me;
