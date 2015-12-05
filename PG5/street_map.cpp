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
      edges[fromnode].insert(edge(tonode,name,length));
      edges[tonode].insert(edge(fromnode,name,length));
    } else if (code == "E:") {
      int fromnode, tonode;
      float length;
      string url;
      iss >> fromnode >> tonode >> length >> url;
      edges[fromnode].insert(edge(tonode,name,length));
      edges[tonode].insert(edge(fromnode,name,length));
    } else {
      throw runtime_error("bad file format");
    }
  }
 //  The segments are supposed to be sorted, but just in case...
  for (auto side_segment : data)
    sort(side_segment.second.begin(), side_segment.second.end());
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
  u = seg_it->fromnode;
  v = seg_it->tonode;
  pos = seg_it->length * (((double)hn - seg_it->fromhn)/((double)seg_it->tohn - seg_it->fromhn + 2));
  return true;
}

bool street_map::route(int su, int sv, float spos, int tu, int tv, float tpos, std::vector<std::pair<std::string, float>> & steps) const {
  steps.clear();
  unordered_map<int,path> marked;
  float distance;
  float dis = 0.0;
  bool passed = route_helper(su,sv,spos,tu,tv,tpos,marked,distance);
  if(su == tu && sv == tv){
    steps.push_back(make_pair(get_street_name(su,sv,"",""),distance));
    return true;
  }
  if(!passed){
    return false;
  }
  path cursor(0,0,0,""), previous(0,0,0,"");
  cursor = marked.at(-1);
  while(cursor.previous_node != 0){
    previous = marked.at(cursor.previous_node);
    while(cursor.street_name == previous.street_name && previous.current_node != -2){
      previous = marked.at(previous.previous_node);
    }
    steps.push_back(make_pair(cursor.street_name,cursor.total_distance-previous.total_distance));
    cursor = previous;
  }
  reverse(steps.begin(),steps.end());
  return true;
}


bool street_map::route3(int source, int target, float &distance) const {

  unordered_map<int,path> marked;
  priority_queue<path> frontier;

  frontier.push(path(source,0,0,""));

  while(frontier.size()>0){
    path p = frontier.top();
    frontier.pop();
    if(p.current_node == target) {
      distance = p.total_distance;
      return true;
    }
    if(marked.count(p.current_node) == 0){
      marked.insert({p.current_node,p});
      if(edges.count(p.current_node) > 0){
        for(auto neighbor : edges.at(p.current_node)){
          frontier.push(path(neighbor.tonode,neighbor.weight + p.total_distance, p.current_node,""));
        }
      }
    }
  }
  return false;
}

bool street_map::route4(int su, int sv, float spos, int tu, int tv, float tpos, float &distance) const {
  unordered_map<int,path> marked;
  return route_helper(su, sv, spos, tu, tv, tpos, marked, distance);
}

bool street_map::route_helper(int su, int sv, float spos, int tu, int tv, float tpos, unordered_map<int,path>& marked, float& distance) const {
  if(su == tu && sv == tv){
    distance = abs(spos-tpos);
    return true;
  }
  priority_queue<path> frontier;
  float sl = 0, tl = 0;
  string start_street, end_street;
  for(auto neighbor : edges.at(su)){
    if(neighbor.tonode == sv){
      sl = neighbor.weight;
      start_street = neighbor.street_name;
      break;
    }
  }
  for(auto neighbor : edges.at(tu)){
    if(neighbor.tonode == tv){
      tl = neighbor.weight;
      end_street = neighbor.street_name;
      break;
    }
  }
  path source = path(-2,0,0,start_street);
  path target = path(-1,0,0,end_street);
  marked.insert({source.current_node,source});
  frontier.push(path(su,spos,-2,start_street));
  frontier.push(path(sv,sl-spos,-2,start_street));
  while(frontier.size()>0){
    path p = frontier.top();
    frontier.pop();
    if(p.current_node == tu) {
      target.total_distance = p.total_distance + tpos;
      target.previous_node = tu;
      frontier.push(target);
    }
    if(p.current_node == tv) {
      target.total_distance = p.total_distance + tl - tpos;
      target.previous_node = tv;
      frontier.push(target);
    }
    if(p.current_node == -1) {
      distance = p.total_distance;
      marked.insert({p.current_node,p});
      return true;
    }
    if(marked.count(p.current_node) == 0){
      marked.insert({p.current_node,p});
      if(edges.count(p.current_node) > 0){
        for(auto neighbor : edges.at(p.current_node)){
          frontier.push(path(neighbor.tonode,neighbor.weight + p.total_distance, p.current_node,neighbor.street_name));
        }
      }
    }
  }
  return false;
}

string street_map::get_street_name(int su, int sv, string start_street, string end_street) const {
  if(su == -1 || sv == -1){
    return end_street;
  }
  if(su == -2 || sv == -2){
    return start_street;
  }
  auto segments = edges.find(su);
  if(segments != edges.end()) {
    for(auto edge : segments->second){
      if(edge.tonode == sv){
        return edge.street_name;
      }
    }
  }
}

