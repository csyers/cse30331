// Christopher Syers	CSE30331	PG2
// October 1, 2015	location.h
//
// Interface and implementation for location class, which stores the latitude and longitude 
// and name of a location. Defines a constructor and a non-default constructor.


#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class location{
 	public:
    		location();
		location(double, double, std::string);	
		void print();
		void print_distance();
		double get_latitude();
		double get_longitude();
		void calc_distance(location);
		double get_distance();
		std::string get_name();
		friend bool operator< (location &x, location &y);	// overloaded < operator
	private:
		double latitude;
		double longitude;
		std::string name;	// name of POI
		double distance;	// distance from another location: set by calc_distance
};


// function definitions


// definition of default constructor
// precondition: none
// postcondition: location object is created with 0 or 
// empty data members
location::location(){
	// set members to 0 or empty string
	latitude = 0;
	longitude - 0;
	distance = 0;
	name = "";
} 

// definition of non-default constructor
// precondition: none
// postcondition: location object has latitude, longitude,
// and name stored in it
location::location(double latitude_cor, double longitude_cor, std::string loc_name) : 	latitude{latitude_cor},
								  	longitude{longitude_cor},
								  	name{loc_name},
									distance{0}
{}					
					
// definition of function print()
// precondition: none
// postcondition: values of data members are printed out
void location::print(){
	std::cout <<  latitude << " " << longitude << " " << name << std::endl;	// prints out all information
}

// definition of function print()
// precondition: none
// postcondition: values of data members are printed out
void location::print_distance(){
	std::cout << distance << " " << name << std::endl;	// prints distance member variable
}

// definition of get_latitude()
// precondition: none
// postcondition: value of latitude is returned
double location::get_latitude(){
	return latitude;
}

// definition of get_longitude()
// precondition: none
// postcondition: value of longitude is returned
double location::get_longitude(){
	return longitude;
}

// definition of calc_distance(const location)
// precondition: l is a location with an latitude and longitude coordinate
// postcondition: distance data member is set to the distance between the object and the arugment
void location::calc_distance(location l){
	distance = (24901./(2*M_PI))*acos(sin((M_PI/180)*l.get_latitude())*sin((M_PI/180)*latitude)+cos((M_PI/180)*l.get_latitude())*cos((M_PI/180)*latitude)*cos((M_PI/180)*(l.get_longitude()-longitude)));
}

// definition of get_distance()
// precondition: none
// postcondition: value of distance is returned
double location::get_distance(){
	return distance;
}

// definition of get_name()
// precondition: none
// postcondition: value of name is returned
std::string location::get_name(){
	return name;
}

// definition of overloaded < operation
// precondition: none
// postcondition: returns true if x is less than or equal to y, and false otherwise
bool operator< (location &x, location &y){
	if(x.get_distance() < y.get_distance()){
		return true;
	} else if (x.get_distance() == y.get_distance()){	// if the distances are the same, sort by name
		if(x.get_name() < y.get_name()){		// if x has a smaller name lexiographically, put it first
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
#endif
