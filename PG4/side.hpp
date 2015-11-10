#ifndef SIDE_HPP
#define SIDE_HPP

#include <string>
#include <boost/functional/hash.hpp>

using namespace std;

class side {
	public:
		side(int parity = 0, string street_name = ""): parity(parity), street_name(street_name) {}	// default constructor with fallback values
		int parity;		// 0 for even, 1 for odd
		string street_name;	// name of the street
		bool operator==(const side &other) const {	// overload the equality operator to allow for hashing of the side class
			return(parity == other.parity && street_name == other.street_name);
		}
		

};

// write the hash function for the side calss
// combines the hash value of the integer and the string
// using the boost hash functionality
inline size_t hash_value (side const &s){
	size_t h = boost::hash<int>()(s.parity);
	boost::hash_combine(h,s.street_name);
	return h;
}

#endif
