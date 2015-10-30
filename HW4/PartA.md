Homework 4 - Part A
===================
Due 2015/10/27 at the beginning of class.

Q1. What are the average cost for lookup, insertion and deletion in a hash table? Express your answer using big O notation in terms of n, the number of elements in the table. Assume that the hash function is uniform and the load factor (alpha) is small.

Lookup: O(1)
Insertion: O(1)
Deletion: O(1)


Q2. Suppose I have a hash table with ten buckets (0-9) using separate chaining. The hash function is h(x) = x % 10. I insert the following integers into the hash table: 55, 39, 10, 25. What will the hash table look like?

h(55) = 5, so data[5] will contain a pointer to the record with key 55. 
h(39) = 9, so data[9] will contain a pointer to the record with key 39. 
h(10) = 0, so data[0] will contain a pointer to the record with key 10. 
h(25) = 5, so data[5] will contain a head pointer to the record with key 55, which is linked to the record with key 25.

The final hash table will look like this:

data[0] --> record(10) --> null

data[1] --> null

data[2] --> null
	
data[3] --> null

data[4] --> null

data[5] --> record(55) --> record(25) --> null

data[6] --> null

data[7] --> null

data[8] --> null

data[9] --> record(39) --> null




**GRADER: **
**GRADER: 2/2**