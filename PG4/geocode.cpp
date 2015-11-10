#include "street_map.hpp"
#include "segment.hpp"
#include "side.hpp"
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
  street_map m("southbend.map");

  string addr, url;
  ostringstream oss;
  for (int i=1; i<argc; i++) {
    if (i>1)
      oss << " ";
    oss << argv[i];
  }
  addr = oss.str();
  if (m.geocode(addr, url))
    cout << url << endl;
  else
    cout << "Address not found.\n";
}
