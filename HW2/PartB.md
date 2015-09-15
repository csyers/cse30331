Homework 2 - Part B
===================
Due 9/17 at the beginning of the class

3. Please give the worst-case time complexity for each of the sorting algorithms below:

-  Selection sort: O(n^2)
-  Insertion sort: O(n^2)
-  Heap sort: O(n log(n))



4. Insertion sort is faster than selection sort when the input array is already in sorted order.
A. True
B. False
C. It depends

The answer is (A), true. Insertion sort, when the input array is already sorted, is O(n), because 
each insertion of a new element will only examine a single element from the array. So that results 
in about n operation, as opposed to O(n^2) in average and worst case complexity of the insertion 
sort. On the other hand, selection sort is always O(n^2). The selection sort has a best, worst, and 
average complexity of O(n^2). It performs the same number of operations no matter what the values 
are in the array that it sorts.
