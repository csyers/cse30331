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


6. Which of these statements is/are NOT true of mergesort and its variations? More than one statement may be false.
A. Merge sort is normally only used for external sorting. 
B. Merge sort is usually implemented recursively. 
C. The worst-case performance for merge sort is O(n log n).
D. Merge sort is especially useful on files that have a size that is a power of 2.

(A) is false. There are other uses for the mergesort alogrithm. For one, it is a stable 
sort, meaning that elements with the same index are going to stay in the order they came 
in. Quicksort, on the other hand, is not stable. So this could be an important use of 
the mergesort that is not necessarily external. Another advantage that mergesort can 
provide is that it is always log(n log n), whereas quicksort can degrade to log(n^2). 
This happens when the pivots are poorly picked. So if space is not a consideration, mergesort 
could advantageous to use as a non-external sort. A third reason is that the mergesort does 
not need the extra space for sorting linked lists. So it is usually used to sort linked lists. 
This is because mergesort gets data sequentially, whereas quicksort needs random access. 

(B) is true. Mergesort is a recursive sorting algorithm.

(C) is true. Mergesort is always O(n log n)

(D) is true. Although binary merge sort is not mentioned in the book, it seems like it 
would lend itself well to work with thing of powers of 2, because binary is in the name.
