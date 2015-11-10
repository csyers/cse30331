#include <string>

#include "street_map.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


street_map::street_map (const string &filename) {
// precondition: filename is a file that contains formatted lines for the addresses in an area
// postcondition: street_hash contains records for all the sides in the file
	ifstream file;			// input file stream
	file.open(filename);		// opens the file
	string line;			// variable to hold the line read from the file
	side odd, even;			// temporary side variables with parity set to 0 and 1
	odd.parity = 1;
	even.parity = 0;
	vector<segment> odds;		// temporary vectors for odd and even sides
	vector<segment> evens;
	// variables for parsing the input lines of the file
	int parity, max, min, start_node, end_node;
	double length;
	string url;

	if(!file.is_open()){		// if the file was not opened, print error message and return
		cout << "Error: could not open file \"" << filename << "\"." << endl; 	
	} else {			// if the file was opened
		while(getline(file,line)){		// gets a line until there are no more lines
			if(line[0] == 'N'){		// if the line is a street name
				if(!evens.empty())	data.insert({even,evens});		// if the temp vectors are not empty, insert a pair into the data unordered_set
				if(!odds.empty())	data.insert({odd,odds});		
				// clear temp vectors
				evens.clear();
				odds.clear();
				// sets the street name for both temporary sides to the name found in the substring 3 to the end of line
				odd.street_name = line.substr(3,string::npos);
				even.street_name = line.substr(3,string::npos);
			} else {						// if the line contains information about a segment...
				istringstream iss(line.substr(3,string::npos));	// turn the substring with the information into a stringstream
				iss >> parity >> min >> max >> start_node >> end_node >> length >> url;	// extracts necessary information from stringstream
				if(parity==0){					// if the parity extracted is 0, add info to the evens vector
					evens.push_back(segment(max,min,url));
				} else {					// if the parity was 1, add info to the odds vector
					odds.push_back(segment(max,min,url));
				}
			}
		}
	}
}

bool street_map::geocode(const string &address, string &url) const {
	istringstream iss(address);	// make an istringstream out of argument
	int street_number;		// variable for the street number
	string street_name;		// varaible for street name
	iss >> street_number;		// get the street number
        iss >> std::ws;			// remove the space from istringstream
	getline(iss,street_name);	// get the rest of the string 

	side target(street_number%2,street_name);		// creates an object to search for in the unordered_set that has 0 or 1 for parity and the street name
	auto result = data.find(target);			// set result equal to the iterator returned by finding the target
	if(result ==  data.end()){				// if the target was not found, return false
		return false;
	} else {						// if the target was found
		for(auto street_segment : result->second){	// loop through all segments in the results value field
			if(street_number <= street_segment.max_house_number && street_number >= street_segment.min_house_number){	// if the street number is inbetween the min and max of the segment, set the url to the correct url and return true
				url = street_segment.url;
				return true;
			} 
		} 
		return false;		// if the house number was not in the range of any of the segments, return false
	}
}


