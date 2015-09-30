// Christopher Syers	CSE30331	PG2
// October 1, 2015	distance5.cpp
//
// program that sorts and prints distances from a given location
// using a vector, and q_sort, which is a simple implementation of 
// a quicksort algorithm

#include "location.h"
#include <iostream>
#include <string>
#include <cstdlib>	// for exit()
#include <fstream>	// for reading file
#include <vector>
#include <list>
#include <algorithm>	// for sort

using namespace std;

// quicksort function
template <typename T>
void q_sort(vector<T>&,int,int);
// parition function used in q_sort
template <typename T>
int partition(vector<location>&,int,int);

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
	vector<location> locs;			// vector to hold locations from file
	read_file(argv[1], locs);		// call to read_file to populate locs
	vector<location>::iterator iterator; 	// iterator to iterate through list/vector
	for(iterator = locs.begin(); iterator != locs.end(); iterator++){
		iterator->calc_distance(my_loc);			// loop through and run calc_distance with each location
	}
	q_sort(locs,0,locs.size());		// sort the locations by distance using q_sort
	for(iterator = locs.begin(); iterator != locs.end(); iterator++){
		iterator->print_distance();	// loop through and print all of the distances
	}
}

// function: q_sort
// simple implementation of the quicksort algorithm, using a Lomuto parititon
// parameters: vector<location> v contains the elements to be sorted. begin is the element
// to begin at, and end is one index after the last element to be sorted
// preconidtion: < operator overlaoded for type T
// postconidtion: vector is now in sorted order
template <typename T>
void q_sort(vector<T> &v, int begin, int end){
	int pivot;
	if (begin < end){			// repeat until the begin is equal to end (1 element)
		pivot = partition(v,begin,end);	// partition the vector and get the pivot posiition
		q_sort(v,begin,pivot);		// quick sorts the first part
		q_sort(v,pivot+1,end);		// quick sorts the second part
	}
}

// function: partition
// partition portion of the quicksort algorithm - implemented using Lomuto parition
// precondition: < operator overloaded fro type T
// postcondition: returned value is the position of the pivot position after partition
template <typename T>
int partition(vector<T> &v, int begin, int end){
	int mid = (begin + end) / 2;	// calculate middle of the arrray
	T p = v[mid];			// sets pivot to first element: naive approach but it works fine
	int i = begin;			// sets index i to the first element to sort
	int j;			
	T temp;				// temp variable for switching
	temp = v[mid];			// switch pivot element to beginning of the array
	v[mid] = v[begin];
	v[begin] = temp;
	for(j=i+1; j < end; j++){	// j is set to element after i, containue until the end
		if(v[j] < p){		// if j points to a value smaller than pivot,
			i++;		// move i
			temp = v[j];	// swap the variables
			v[j] = v[i];	
			v[i] = temp;
		}
	}
	temp = v[i];		// swap the pivot with the current position of i
	v[i] = v[begin];
	v[begin] = temp;
	return i;		// return i, which is now the pivot value
}
