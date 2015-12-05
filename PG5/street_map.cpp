#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "street_map.hpp"

using namespace std;

// constructor of street_map
// TAKEN FROM THE PG4 SOLUTION PROVIDED BY THE TAs - MODIFICATIONS ARE COMMENTED
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
      // ADDITION: also add information to the adjacency list
      edges[fromnode].insert(edge(tonode,name,length));		// insert edge into the adjacency list
      edges[tonode].insert(edge(fromnode,name,length));		// insert the reverse into the adjaceny list
    // ADDITION: deals with E: lines, where the infromation is a fromnode, tonode, length, and url
    } else if (code == "E:") {
      int fromnode, tonode;
      float length;
      string url;
      iss >> fromnode >> tonode >> length >> url;		// extract all of the information into appropriate variables
      // ADDITION: add information to the adjacency list
      edges[fromnode].insert(edge(tonode,name,length));		// insert into the adjacency list
      edges[tonode].insert(edge(fromnode,name,length));		// insert the reverse into the adjacency list
    } else {
      throw runtime_error("bad file format");
    }
  }
 //  The segments are supposed to be sorted, but just in case...
  for (auto side_segment : data)
    sort(side_segment.second.begin(), side_segment.second.end());
}

// TAKEN FROM THE PG4 SOLUTION PROVIDED BY THE TAs - MODIFICATIONS ARE COMMENTED
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
  // ADDITION: changed from setting a url to setting u, v, and pos
  u = seg_it->fromnode;		// u is equal to the segment's source node
  v = seg_it->tonode;		// v is equal to the segment's destination node
  pos = seg_it->length * (((double)hn - seg_it->fromhn)/((double)seg_it->tohn - seg_it->fromhn + 2));	// pos calculated with formula given in pg5.pdf
  return true;
}

// route: populates steps with the steps of the shortest path from spos to tpos
bool street_map::route(int su, int sv, float spos, int tu, int tv, float tpos, std::vector<std::pair<std::string, float>> & steps) const {
  steps.clear();			// clears whatever is in steps
  // variables to be populated in route_helper
  unordered_map<int,path> marked;	
  float distance;		 
  // call route_helper to populate the distance of the shortest path and the marked unordered_set 
  bool passed = route_helper(su,sv,spos,tu,tv,tpos,marked,distance);
  // if the source and target are on the same segment
  if(su == tu && sv == tv){
    auto segments = edges.find(su);	
    if(segments != edges.end()) {
      for(auto edge : segments->second){
        if(edge.tonode == sv){
          steps.push_back(make_pair(edge.street_name,distance));	// push back the street_name of the edge between su and sv into steps
	  return true;							// exit the function
        }
      }
    }
  }
  // if route_helper returned false (no path between the two nodes), return false
  if(!passed){
    return false;
  }

  // begin algorithm of populating the steps vector
  path cursor(0,0,0,""), previous(0,0,0,"");		// temporary paths structs
  cursor = marked.at(-1);				// finds the last element in marked
  while(cursor.previous_node != 0){			// while there are more nodes before it in the path
    previous = marked.at(cursor.previous_node);		// previous becomes the path object before the cursor
    while(cursor.street_name == previous.street_name && previous.current_node != -2){	// while they have the same street name:
      previous = marked.at(previous.previous_node);						// continue moving previous along the path
    }
    steps.push_back(make_pair(cursor.street_name,cursor.total_distance-previous.total_distance));	// when they have different street names, add that path to the steps vector
    cursor = previous;		// advance the cursor to the previous path
  }
  reverse(steps.begin(),steps.end());		// because elements were added along the path backwards, reverse the whole vector
  return true;					// algorithm complete
}

// route3: calculates the minimum distance between two nodes in the map of South Bend using Dijkstra's Algorithm
bool street_map::route3(int source, int target, float &distance) const {

  // containers used - marked contains all the visited paths, frontier is the possible nodes to visit next
  unordered_map<int,path> marked;
  priority_queue<path> frontier;

  // starrt with the source node in the frontier
  frontier.push(path(source,0,0,""));

  while(frontier.size()>0){		// continue until the frontier is empty
    path p = frontier.top();		// get the path with the shortest distance from the frontier
    frontier.pop();			// remove that element
    if(p.current_node == target) {	// if the path just popped is the target node, set distance and end the algorithm
      distance = p.total_distance;
      return true;
    }
    if(marked.count(p.current_node) == 0){	// if the node is node already in marked
      marked.insert({p.current_node,p});	// add that node to marked
      if(edges.count(p.current_node) > 0){	// if the current node has neighbors
        for(auto neighbor : edges.at(p.current_node)){	// for each edge for that node:
          frontier.push(path(neighbor.tonode,neighbor.weight + p.total_distance, p.current_node,""));	// add to frontier
        }
      }
    }
  }
  return false;
}

// route4: calls the helper function which runs Dijkstra's algorithm from a phantom node in the graph done in route_helper
bool street_map::route4(int su, int sv, float spos, int tu, int tv, float tpos, float &distance) const {
  unordered_map<int,path> marked;	// holder for the marked paths
  return route_helper(su, sv, spos, tu, tv, tpos, marked, distance);	// calls route_helper
}

// helper function used in route4 and route to perform Dijkstra's with a phantom start and end node
bool street_map::route_helper(int su, int sv, float spos, int tu, int tv, float tpos, unordered_map<int,path>& marked, float& distance) const {
  priority_queue<path> frontier;	
  // CASE: the source and target are on the same segment
  if(su == tu && sv == tv){
    distance = abs(spos-tpos);	// total distance is the difference between their positions on that segment
    return true;		// end algorithm
  }
  float sl = 0, tl = 0;		// sl: total length of the source's segment ======= tl: total length of the destination's segment
  string start_street, end_street;	// start_street: street name of the source's segment ====== end_street: street name of the target's segment
  // loop through the neighbors of su to find sv
  for(auto neighbor : edges.at(su)){	
    if(neighbor.tonode == sv){
      sl = neighbor.weight;			// set the total length = to the weight of su-sv
      start_street = neighbor.street_name;	// get the street_name of that segment
      break;
    }
  }
  // same algorithm, but for tu and tv
  for(auto neighbor : edges.at(tu)){
    if(neighbor.tonode == tv){
      tl = neighbor.weight;
      end_street = neighbor.street_name;
      break;
    }
  }
 
  path source = path(-2,0,0,start_street);	// create a phantom path to the phantom start node
  path target = path(-1,0,0,end_street);	// create a phantom path to the phantom end node
  marked.insert({source.current_node,source});	// insert the phantom start node into marked
  frontier.push(path(su,spos,-2,start_street));		// insert a path from the phantom start node to su to frontier
  frontier.push(path(sv,sl-spos,-2,start_street));	// insert a path from the phantom start node to sv to frontier

  while(frontier.size()>0){		// while the frontier is not empty
    // get the top element and remove it from the frontier
    path p = frontier.top();
    frontier.pop();
    // CASE: you are looking at a node with tu as its current_node
    if(p.current_node == tu) {
      target.total_distance = p.total_distance + tpos;		// the total distance is p's total distance plus the position of the phantom target along the total distance
      target.previous_node = tu;				
      frontier.push(target);					// add that path to the frontier
    }
    // CASE: you are looking at a node with tv as its current_node
    if(p.current_node == tv) {				
      target.total_distance = p.total_distance + tl - tpos;	// the total distance is p's total distance plus the distance from tv to tpos
      target.previous_node = tv;
      frontier.push(target);					// add that path to the frontier
    }
    // CASE: you are looking at the last node
    if(p.current_node == -1) {
      distance = p.total_distance;
      marked.insert({p.current_node,p});			// insert the last object into marked
      return true;						// end algorithm
    }
    // if the current node is not already in marked
    if(marked.count(p.current_node) == 0){
      marked.insert({p.current_node,p});			// insert the current path into marked
      if(edges.count(p.current_node) > 0){			// loop through the neighbors of the current node...
        for(auto neighbor : edges.at(p.current_node)){
          frontier.push(path(neighbor.tonode,neighbor.weight + p.total_distance, p.current_node,neighbor.street_name));	// add them to the frontier
        }
      }
    }
  }
  return false;
}
