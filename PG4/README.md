Programming Assignment 4
========================

_Your description here_

To implement geocoding, I used an unordered_map (hash table) as the underlying data structure in the street_map class. The key value for this is a side object, 
which contains a street name and a parity flag, which is 0 for even house numbers and 1 for odd house numbers. Each side object mapped to a vector of segments, 
which each contain information about a segment with a particular url, and max and min house numbers. I chose this configuration because each street name could 
map to up to two vectors of segments, one with even nubmer and one with odd numbers. Then, a house number could be searched for within the ranges of house numbers 
in those vector.

For example, the first street, Bercliff Dr, the program maps two things: one is a side object with street_name "Bercliff Dr" and parity of 0, and the other is a side 
object with street_name "Bercliff Dr" and parity of 1. The vector that the first (even) side maps to would contain all the segments of the even house numbers. One 
would be 300-314 with the given url, another with 316-332 with its given url, and the last with 334-398 with its given url. The consutrctor of the street_map object 
reads in a file so that the appropriate sides and segment vectors are placed into the hash table. 

In order for the elements to be hashed, the side class must have the == operator overloaded and a hash function defined for it. This was done in the file side.hpp. 
The == operator simply compares the two data members of the side objects. The hash function makes use of the boost library. It hashes both the street name and the 
parity of the side using hash_combine. After inserting all of the correct records into the hash table by parsing the map file, all that needed to be implemented was 
the geocode function needed to be written. 

geocode words by first parsing the input string into a house number and a street name. Then, the program makes use of the find function of an unordered_set, which 
returns an iterator to the record if it is found. With that iterator, you know that if it is the end of the map, then the side was not placed in the map. If there is 
an iterator, then the house number must fall within the range of one of the segments in the vector of segments returned. If it is, the program sets url to the url 
data member of that segment, and if it is not, the function returns false.

I learned a few things doing this lab. I used the keyword auto a few times, which I never knew existed in c++. I also got more practice writing hash functions 
(leveraging existing hash functions in boost), and inserting into unordered_sets. It was also helpful to have to think about how the data structures would be organized 
in order to get the functionality of a geocoding program. 

_Grader comments here_
