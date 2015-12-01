#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "street_map.hpp"

using namespace std;

street_map::street_map (const string &filename) {
  string line;
  fstream infile(filename);
  string name;
  data.clear();
  while (getline(infile, line)) {
    istringstream iss(line);
    string code;
    iss >> code >> ws;
    if (code == "N:") {
      getline(iss, name);
    } else if (code == "R:") {
      int parity, fromhn, tohn, fromnode, tonode;
      float length;
      string url;
      iss >> parity >> fromhn >> tohn >> fromnode >> tonode >> length >> url;
      side s(name, parity);
      if (data.find(s) == data.end())
	data[s] = vector<segment>();
      data[s].push_back(segment(fromhn, tohn, url, fromnode, tonode, length));
      
           
      edges[fromnode].push_back(edge(tonode,name,length));
      edges[tonode].push_back(edge(fromnode,name,length));
    } else if (code == "E:") {
      int fromnode, tonode;
      float length;
      string url;
      iss >> fromnode >> tonode >> length >> url;
      edges[fromnode].push_back(edge(tonode,name,length));
      edges[tonode].push_back(edge(fromnode,name,length));      
    } else {
      throw runtime_error("bad file format");
    }
  }
  // The segments are supposed to be sorted, but just in case...
  for (auto side_segment : data)
    sort(side_segment.second.begin(), side_segment.second.end());
  auto it = edges[11397633];
  for (auto edge_part : it)
	cout << edge_part.tonode << endl;
}

bool street_map::geocode(const string &address, int &u, int &v, float &pos) const {
  istringstream iss(address);
  int hn;
  string name;
  iss >> hn >> ws;
  getline(iss, name);
  auto pair_it = data.find(side(name, hn % 2));
  if (pair_it == data.end())
    return false;
  auto segs = pair_it->second;
  auto seg_it = lower_bound(segs.begin(), segs.end(), segment(hn, hn, "dummy",0,0,0));
  if (seg_it == segs.end())
    return false;
  assert (seg_it->tohn >= hn);
  if (seg_it->fromhn > hn)
    return false;
//  url = seg_it->url;
  u = seg_it->fromnode;
  v = seg_it->tonode;
  pos = seg_it->length * (((double)hn - seg_it->fromhn)/((double)seg_it->tohn - seg_it->fromhn + 2));
  return true;
}

bool street_map::route(int su, int sv, float spos, int tu, int tv, float tpos, std::vector<std::pair<std::string, float>> & steps) const {
  return true;
}

bool street_map::route3(int source, int target, float &distance) const {
/*
  unordered_set<distance> marked;
  priority_queue<distance> frontier;

  start_distance = distance(start,0,0);
  frontier.push(start_distance);
*/
}

bool street_map::route4(int su, int sv, float spos, int tu, int tv, float tpos, float &distance) const {
}

//bool street_map::route(int su, int sv, float spos, int tu, int tv, float tpos, vector<pair<string, float>> &steps) const {
//  steps.clear();
//}
