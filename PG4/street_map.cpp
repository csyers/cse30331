#include <string>

#include "street_map.hpp"
#include <fstream>
#include <iostream>
using namespace std;


street_map::street_map (const string &filename) {
// precondition: filename is a file that contains formatted lines for the addresses in an area
// postcondition: street_hash contains records for all the sides in the file
	ifstream file;
	file.open(filename);
	string line;
	side odd, even;
	odd.parity = 1;
	even.parity = 0;
	vector<segment> odds;
	vector<segment> evens;
	int parity, max, min, start_node, end_node;
	double length;
	string url;
	if(!file.is_open()){
		cout << "Error: could not open file \"" << filename << "\"." << endl; 	
	} else {
		while(getline(file,line)){
			if(line[0] == 'N'){
				evens.clear();
				odds.clear();
				odd.name = line.substr(3,string::npos);
				even.name = line.substr(3,string::npos);
			} else {
				info = line.ssubstr(3,string::npos);
				isstream iss(info);
				iss >> parity >> max >> min >> start_node >> end_node >> length >> url;
				if(parity==0){
					evens.push_back(segment(max,min,url));
				} else {
					odds.push_back(segment(max,min,url));
				}
			}
		}
	}
	
	
}

bool street_map::geocode(const string &address, string &url) const {
  // Fill in your code here.
}

// You can add any other functions you want to add.

