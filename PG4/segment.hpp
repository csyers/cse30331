#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <string>
using namespace std;

class segment {
	public:
		segment(int max = 0, int min = 0, string url = ""): max_house_number(max), min_house_number(min), url(url) {}		// default constructor with fallback values
		int max_house_number;		// stores the highest house number included in this segment
		int min_house_number;		// stores the lowest house number inlcded in this segment
		string url;			// stores the segment's URL

};


#endif
