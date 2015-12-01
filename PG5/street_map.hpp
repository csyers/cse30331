#ifndef STREET_MAP_HPP
#define STREET_MAP_HPP

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
//#include <priority_queue>
/*
struct distance {
  int node;
  float total_distance;
  int previous_node;
  bool operator==(const distance &other) const { return node == other.node && total_distance == other.total_distance && previous_node == other.previous_node; }
  distance(int node, float total_distance, int previous_node) : node(node), total_distance(total_distance), previous_node(previous_node) { }
};

namespace std {
  template<>
  struct hash<distance> {
    hash<int> string_hasher;
    size_t operator()(const distance &d) const {
      return string_hasher(d.node) ^ d.previous_node ^ d.total_distance;
    }
  };
}
*/
struct edge {
  int tonode;
  std::string street_name;
  float weight;
  edge(int tonode, const std::string &street_name, int weight) : tonode(tonode), street_name(street_name), weight(weight) { }
};

struct side {
  std::string name;
  int parity;
  bool operator==(const side &other) const { return name == other.name && parity == other.parity; }
  side(const std::string &name, int parity) : name(name), parity(parity) { }
};

namespace std {
  template<>
  struct hash<side> {
    hash<string> string_hasher;
    size_t operator()(const side &s) const {
      return string_hasher(s.name) ^ s.parity;
    }
  };
}

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
  std::unordered_map<side, std::vector<segment>> data;
  std::unordered_map<int, std::vector<edge>> edges;
};

#endif
