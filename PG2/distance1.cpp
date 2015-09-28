// Christopher Syers	CSE30331	PG2
// October 1, 2015	distance1.cpp
//
// program that takes in one argument, which is a file containing 
// latitude and longitude coordinates of vairous points of interest

#include "location.h"
#include <iostream>
#include <string>
#include <cstdlib>	// for exit()
#include <fstream>	// for reading file
#include <vector>
#include <list>

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
	double x_cor;				// holds value of x coordinate read in from ifile
	double y_cor;				// holds value of y coordinate read in from ifile
	string loc_name;			// holds value of string read from ifile
	while(ifile.good() && ifile.peek()!=EOF){	// repeat until EOF is the next character
		ifile >> x_cor;				// read a double
		ifile >> y_cor;				// read another double
		getline(ifile,loc_name);		// take the rest of the line as the string
		loc_name = loc_name.substr(1);	// strip leading space
		data_struct.push_back(location(x_cor,y_cor,loc_name));		// push_back the location into the data_struct
	}
	ifile.close();				// close the file
}  

// print_usage_and_exit
// function that tells the user the usage of the program and exits with exit code 1
void print_usage_and_exit(){
	cout << "usage: ./distance1 filename.txt" << endl;	// prints error
	exit(1);						// exits with code 1
}


int main(int argc, char *argv[]){
	if(argc != 2){				// prints error if there is not exactly 1 arugment passed in with call
		print_usage_and_exit();
	}
	vector<location> locs;			// vector to hold elements
	read_file(argv[1], locs);		// call to read_file
}
