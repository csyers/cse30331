#include <string>
#include <vector>

#include "street_map.hpp"

using namespace std;

street_map::street_map (const string &filename) {
}

bool street_map::geocode(const string &address, int &u, int &v, float &pos) const {
}

bool street_map::route3(int source, int target, float &distance) const {
}

bool street_map::route4(int su, int sv, float spos, int tu, int tv, float tpos, float &distance) const {
}

bool street_map::route(int su, int sv, float spos, int tu, int tv, float tpos, vector<pair<string, float>> &steps) const {
  steps.clear();
}
