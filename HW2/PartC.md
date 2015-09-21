Homework 2 - Part C
===================
DUE 9/22 at the beginning of the class

5. What are the three main steps in the quicksort method? 

Quicksort can be broken down into three steps: 

1. The first steps would be to select a pivot point (sometimes the first element). 
This is the initialization step. 

2. The second step is to continue switching elements that are in the wrong part of 
the array until all of the elements larger than the pivot are to the right of all 
of the elements smaller than the pivot point. 

3. The third step is to move the pivot to the correct spot. This completes the 
division of the array. Then the alogirthm can be called recursively with the 
two unsorted portions of the array, until the base case is reached, and the array is sorted.

Three more general steps to the quicksort method are dividing the elements to be 
sorted into two groups, sorting the two groups with two recursive calls, and 
then combining the two sorted groups into a single sorted array. These are the 
overall steps for all divide and conquer algorithms, like quicksort and mergesort. 
The more specific steps are listed above.


6. Which of these statements is NOT true of mergesort and its variations?
A. Merge sort is only used as an external sorting algorithm. 
B. Merge sort is usually implemented recursively. 
C. The worst-case performance for merge sort is O(n log n).
D. Binary merge sort is used on subfiles that have a size that is a power of 2.

(A) is false. The statement should say that it is usually used as an external sorting 
algorithm. It requires the use of a temporary array, which would have to be allocated 
and freed, so it is not ideal for sorting arrays. It does lend well to sorting large 
programs, so it is usually used as an external sorting algorithm. This does not mean 
that is cannot be used as an internal sorting algorithm, however. So (A) is false 
because it is not only used as an external sorting algorithm.

(B) is true. Mergesort is a recursive sorting algorithm.

(C) is true. Mergesort is always O(n log n)

(D) is true. Although binary merge sort is not(A) is false. The statement should say 
that it is usually used as an external sorting algorithm. It requires the use of a 
temporary array, which would have to be allocated and freed, so it is not ideal for 
sorting arrays. It does lend well to sorting large programs, so it is usually used 
as an external sorting algorithm. This does not mean that is cannot be used as an 
internal sorting algorithm, however. So (A) is false because it is not only used 
as an external sorting algorithm.

