// Note: compile with -std=c++11

#include <string>
#include <unordered_set>
#include <boost/functional/hash.hpp>
#include <iostream>
class person {
public:
  std::string firstname, lastname;
  int birthyear, birthmonth, birthday;
  person(std::string f, std::string l, int by, int bm, int bd) : firstname(f), lastname(l), birthyear(by), birthmonth(bm), birthday(bd) {}
  bool operator==(person const& other) const {return firstname == other.firstname && lastname == other.lastname && birthyear == other.birthyear && birthmonth == other.birthmonth && birthday == other.birthday;};
};

std::size_t hash_value (person const&p){
  std::size_t h = boost::hash<std::string>()(p.firstname);
  boost::hash_combine(h,p.lastname);
  boost::hash_combine(h,p.birthyear);
  boost::hash_combine(h,p.birthmonth);
  boost::hash_combine(h,p.birthday);
  return h;
}

int main (int argc, char *argv[]) {
  std::unordered_set<person, boost::hash<person>> me;
  me.insert(person(std::string("hello"),std::string("hello"),1,2,3));
  std::cout << me.count(person(std::string("hello"),std::string("hello"),1,2,3)) << std::endl;
  std::cout << me.count(person(std::string("hi"),std::string("hello"),1,2,3)) << std::endl;
}
