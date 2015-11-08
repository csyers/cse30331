Homework 4 - Part C
===================
Due 2015/11/03 at the beginning of class.

Q5. [Note: clarified 2015/10/31] If I'm trying to sort a bunch of values between 0 and 999,999,999 inclusive, using bucket sort with 1000 buckets, which of these is a valid hash function to use? Assume that / means integer division.
x % 1000
x % 1000000
x / 1000
x / 1000000

Assuming the keys do not exceed 1 billion (10^9), then the valid hash would be x / 1000000. The hash function must have the property that if h(x1) < h(x2), then 
x1 < x2. This is not the case with modular division, so neither of the first two would be valid. There are 1000 buckets, so the result of the hash should be [0,999]. 
So 10^9/divisor = 10^3, divisor = 10^6. Therefore, the valid hash function is x / 1000000. If x is only divided by 1000, a hash result could be larger than 999.

Q6. Briefly explain how it is possible for bucket sort to be faster than O(n log n) when O(n log n) is the best sorting algorithm we’ve seen previously.

O(n log n) is the lower bound of sorting algorithms that are comparison based, where elements are compared using the < operator. Bucket sort can be O(n) because 
it looks directly at the elements themselves, and make additional assumptions about their range. It can be O(n) because if there are n buckets and the hash 
function distributes evenly among the buckets, then there are two independent loops through n elements, resulting in O(n). The first time through inserts the 
element into the array of buckets, and then the second loops sorts the buckets (which would be fast when the elements are evenly distributed over the buckets), 
then insert the elements from the buckets back into the array.





**GRADER: **
**GRADER: 2/2**