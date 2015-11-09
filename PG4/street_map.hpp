#ifndef STREET_MAP_HPP
#define STREET_MAP_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include "side.hpp"
#include "segment.hpp"

class street_map {

public:

  // You need to write implementations of these functions in street_map.cpp.

  // Constructor.
  // `filename` is the pathname of a file with the format described in pg4.pdf.

  explicit street_map (const std::string &filename);

  // Geocodes an address.
  // Input argument:
  //   `address` is an address of the form "1417 E Wayne St"
  // Return value:
  //   `true` if address is found, `false` if address is not found
  // Output argument:
  //   `url` is the URL of an image displaying the street segment
  //   containing the address.

  bool geocode(const std::string &address, std::string &url) const;

private:

  // Add any other member variables and functions you want.

  // The main data structure must have a type of the form:
  //   std::unordered_map<side, ...> 
	std::unordered_map<side,std::vector<segment>,boost::hash<side>> data;
};


#endif
