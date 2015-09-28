// Christopher Syers	CSE30331	PG2
// October 1, 2015	distance4a.cpp
//
// program that sorts and prints the distance of locations from a given
// location using a std::list, and std::list::sort

#include "location.h"
#include <iostream>
#include <string>
#include <cstdlib>	// for exit()
#include <fstream>	// for reading file
#include <vector>
#include <list>
#include <algorithm>	// for sort

using namespace std;

// read_file
// function that takes in a file name to read, and stores the values into the templated data structure.
// precondition: file is readable and of proper format (double double string on each line)
// postcondition: file is closed and data_struct contains location objects corresponding to each line
template <typename T>
void read_file(string file, T &data_struct){
	ifstream ifile;				
	ifile.open(file);			// attempts to open the file
	if(!ifile){				// if the file could not be opened
		cout << "error: cannot open file " << file << endl;	// print error
		exit(1);						// exit
	}
	double lat_cor;				// holds value of x coordinate read in from ifile
	double lon_cor;				// holds value of y coordinate read in from ifile
	string loc_name;			// holds value of string read from ifile
	while(ifile.good() && ifile.peek()!=EOF){	// repeat until EOF is the next character
		ifile >> lat_cor;				// read a double
		ifile >> lon_cor;				// read another double
		getline(ifile,loc_name);		// take the rest of the line as the string
		loc_name = loc_name.substr(1);	// strips the leading space that comes with name
		data_struct.push_back(location(lat_cor,lon_cor,loc_name));	// push_back the location into the data_struct
	}
	ifile.close();				// close the file
}  

// print_usage_and_exit
// function that tells the user the usage of the program and exits with exit code 1
void print_usage_and_exit(){
	cout << "usage: ./distance1 filename.txt latitude longitude" << endl;	// prints error
	exit(1);						// exits with code 1
}


int main(int argc, char *argv[]){
	if(argc != 4){				// prints error if there is not exactly 1 arugment passed in with call
		print_usage_and_exit();
	}
	string my_name = "User Location";	// variable to store into the location
	double my_lat, my_lon;			// variables to hold latitude and longitude from command line
	sscanf(argv[2],"%lf",&my_lat);		// convert argv[2] to a double
	sscanf(argv[3],"%lf",&my_lon);		// convert argv[3] to a double
	location my_loc(my_lat,my_lon,my_name);	// create a location object for location passed in
	list<location> locs;			// vector to hold locations from file
	read_file(argv[1], locs);		// call to read_file to populate locs
	list<location>::iterator iterator; 	// iterator to iterate through list/vector
	for(iterator = locs.begin(); iterator != locs.end(); iterator++){
		iterator->calc_distance(my_loc);			// loop through and run calc_distance with each location
	}
	locs.sort();		// sort the locations by distance by using std::list::sort
	for(iterator = locs.begin(); iterator != locs.end(); iterator++){
		iterator->print_distance();	// loop through and print all of the distances
	}
}
