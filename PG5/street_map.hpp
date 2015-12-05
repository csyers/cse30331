#ifndef STREET_MAP_HPP
#define STREET_MAP_HPP

#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <boost/functional/hash.hpp>

// struct path: stores the information about a path starting at the source node
// members: current_node - the node being looked at
//          total_distance = the accumulated distance of the whole path
//          previous_node = the node that is the previous step in the path
//          street_name - the street name of the segment from the previous_node to the current_node
// operators: < - needed for priority_queue<path> frontier, sorted by the total distance so it will be a minimum pq
//
// algorithms: used as the elements during Dijkstra's algorithm
struct path {
  // data members
  int current_node;
  float total_distance;
  int previous_node;
  std::string street_name;
  // constructor
  path(int current_node = 0, float total_distance = 0, int previous_node = 0, std::string street_name = "") : current_node(current_node), total_distance(total_distance), previous_node(previous_node), street_name(street_name) {}
  // overloaded operators
  bool operator<(const path& a) const {
    return(total_distance > a.total_distance);		// backwards to make the frontier work as a min priority queue
  }
};

// struct edge: stores destination, weight, and street name of an edge in the graph
// members: tonode - the node that the edge goes to
// 	    street_name - the name of the street along the edge
// 	    weight - length of the edge
// operators: == - needed for unordered_set of edges used in the edges data member of a street_map class
//
// algorithms: unordered_set of edge structs used for adjacency list
struct edge {
  // data members
  int tonode;
  std::string street_name;
  float weight;
  // constructor
  edge(int tonode = 0, const std::string &street_name = "", float weight = 0) : tonode(tonode), street_name(street_name), weight(weight) { }
  // overloaded operators
  bool operator==(const edge &other) const { return tonode == other.tonode && street_name == other.street_name && weight == other.weight; }
};

// TAKEN FROM PG4 SOLUTION PRoVIDED BY THE TAs
struct side {
  std::string name;
  int parity;
  bool operator==(const side &other) const { return name == other.name && parity == other.parity; }
  side(const std::string &name, int parity) : name(name), parity(parity) { }
};

// hash function for side object: needed for unordered_map<side,vector<...>> in data member "data"
// boost definition as the combination of all data members of a side struct
inline
std::size_t hash_value(side const& s){
  std::size_t h = boost::hash<std::string>()(s.name);
  boost::hash_combine(h,s.parity);
  return h;
}

// hash function for edge object: needed for unordered_set<edge> in adjacency list data member "edges"
// boost definition as the combination of all data members of an edge struct
inline
std::size_t hash_value(edge const& e){
  std::size_t h = boost::hash<std::string>()(e.street_name);
  boost::hash_combine(h,e.tonode);
  boost::hash_combine(h,e.weight);
  return h;
}

// TAKEN FROM PG4 SOLUTION PROVIDED BY THE TAs
struct segment {
  int fromhn, tohn;
  int fromnode,tonode;
  float length;
  std::string url;
  segment(int fromhn, int tohn, const std::string &url, int fromnode, int tonode, float length) : fromhn(fromhn), tohn(tohn), url(url), fromnode(fromnode), tonode(tonode), length(length) { }
  // Since we assume that segments never overlap,
  // there are lots of equivalent ways of comparing segments.
  bool operator<(const segment &other) const { return tohn < other.tohn; }
};


class street_map {
public:
  // Constructor.
  // `filename` is the pathname of a file with the format described in pg4.pdf.

  explicit street_map (const std::string &filename);

  // Geocodes an address.
  // Input argument:
  //   `address` is an address of the form "1417 E Wayne St"
  // Return value:
  //   `true` if address is found, `false` if address is not found
  // Output arguments:
  //   `u` is the starting node of the edge on which the location lies
  //   `v` is the ending node of the edge
  //   `pos` is how far along the edge the location lies

  bool geocode(const std::string &address, int &u, int &v, float &pos) const;

  // Three functions for finding the shortest route.

  // Input arguments:
  //   `source` is the source node
  //   `target` is the target node
  // Output argument:
  //   `distance` is the shortest distance between them

  bool route3(int source, int target, float &distance) const;

  // Input arguments:
  //   `su`, `sv` is the edge on which the source lies
  //   `spos`     is how far along the edge the source lies
  //   `tu`, `tv` is the edge on which the source lies
  //   `tpos`     is how far along the edge the source lies
  // Output argument:
  //   `distance` is the shortest distance between them

  bool route4(int su, int sv, float spos, int tu, int tv, float tpos, float &distance) const;

  // Input arguemnts: 
  // 	'su', 'sv' is the edge on which the source lies
  // 	'spos'     is how far along the edge the source lies
  // 	'tu', 'tv' is the edge on which the target lies
  // 	'tpos'	   is how far along the edge the target lies
  // Output arguments:
  // 	'marked'   is the set of marked nodes, which contains the information about the total distance of each step
  // 	'distnace' is the shortest distance between them

  bool route_helper(int su, int sv, float spos, int tu, int tv, float tpos, std::unordered_map<int,path>& marked, float& distance) const;
  
  // Input arguments:
  //   `su`, `sv` is the edge on which the source lies
  //   `spos`     is how far along the edge the source lies
  //   `tu`, `tv` is the edge on which the source lies
  //   `tpos`     is how far along the edge the source lies
  // Output argument:
  //   `steps`    is a sequence of driving directions;
  //              each member is a canonical street name and a distance.
  //              The original contents (if any) are cleared out.

  bool route(int su, int sv, float spos, int tu, int tv, float tpos, std::vector<std::pair<std::string, float>> &steps) const;

private:
  // contains all the segments on a given side of a street
  std::unordered_map<side, std::vector<segment>,boost::hash<side>> data;
  // contains all of the edges found in the map, unordered. 
  //   key: int - the source node
  //   value: unordered_set<edge> - a set of all of the edges coming out of the source node
  std::unordered_map<int,std::unordered_set<edge,boost::hash<edge>>> edges;
  std::unordered_map<int,path> marked;
  std::priority_queue<path> frontier;
};

#endif
