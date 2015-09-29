Homework 2 - Part D
===================
Due 2015/09/24 at 9:30am. 2 points each question.


Q7. What sorting algorithm(s) would you use in the following physical situations, and why? Choose from among the sorting algorithms we’ve learned (but if you want to get creative, you can look for other algorithms as well).

- Sorting a hand of 7 playing cards by increasing number (A, 2, …, 10, J, Q, K):  to sort 7 cards, I would choose to sort by using insertion sort. I  
would choose this algorithm because it is simple, and works well with a small number of elements. I would start with the card at the front of the hand 
as sorted, then take the next card and insert it into the appropriate place in the sorted portion of the hand. This would be quick and easy to execute.
- Sorting 100 tigers in 100 cages alphabetically by name: I would choose to sort the tigers using selection sort. This is because selection sort only 
requires O(n) swaps, which is fewer than the other sorting algorithms. I would want to minimize swaps because I can imagine that switching tigers from 
cage to cage could be difficult. Presubably, the zookeeper would know the order of them. So he would just take the first one and put it in the right 
cage, then continue on for all tigers.
- Sorting 10,000 US coins by increasing value: to sort these, I would use bucket sort. This is because there are few district values within the 10,000 coins. There are pennies, nickels, dimes, quarters, half-dollars, and dolalr coins, which means there are only 6 different dstinct values the elements can take. Bucket sort is a sorting algorithm that takes an average time on O(n + k), where k is in the number of buckets. In this case, k would be 6. 
This results in an efficient sorting of the 10,000 coins. This is actually what I'd do in real life: I would take each coin and place it in a bucket 
with the other coins of that value. If I had to choose an in class algorithm, I would use insertion sort, taking each coin 1 by 1 and inserting it into 
the correct position amongst the sorted coins.

I would not choose to use heapsort for any of these cases, because it would be difficult to heapify and reheapify physical objects. 
Also, I chose not to use any recursive algorithm, because as Professor Chiang said in class on Tuesday, recursion is very difficult 
for humans to think of. So although using quicksort might be best for sorting the tigers, I would not choose to do that because of its 
diffulty to implemenet.




Q8. Take a look at the sorting routine in Blender (https://developer.blender.org/diffusion/B/browse/master/source/blender/blenlib/intern/sort.c). The function header is (line 94):

    void BLI_qsort_r(void *a, size_t n, size_t es, BLI_sort_cmp_t cmp, void *thunk)

where

- `a` is the address of the array to be sorted,
- `n` is the number of elements,
- `es` is the size of each element in bytes,
- `cmp(x, y, thunk)` is a function that returns -1 if x < y, +1 if x > y, and 0 if x == y,
- `thunk` can be ignored.

Please answer **two** of the following questions (your choice).

- If there are fewer than 7 elements, a different sorting algorithm is used (lines 102-112). What is it, and why is it used?
The pivot element (pm) is selected in lines 113-124. There are three cases: n = 7, 7 < n <= 40, and 40 < n. What’s going on in each of these cases, and why?
- The partitioning happens in lines 128-152 and 165-169. Describe what happens to the elements that are equal to the pivot, and why.
- Lines 153-163, as the comment says, switch to insertion sort -- under what condition, and why?
- The recursive part is lines 170-177. What’s the meaning of the comment at line 173, and the (gasp) `goto` at line 176?

If there are fewer than 7 elements, a simple insertion sort is used to sort the elements. This would happen because the time to sort would not be that 
large, and the constant would be small for an insert sort. There is a worst case of n^2 comparisons, and there is no overhead in preparing the array. 
It simply starts at the second element, and switches it down until it is in the correct position. It then moves to the next position, and compares it 
to consecutive previous elements, swapping when necessary. When n = 7, line 113 sets the pm. It is set to the middle element. If the number of elements 
is greater than 7 and equal to or less than 40, then pm is set to the median of the first, last, and middle elements. Finally, when there are greater 
than 40 elements, the algorithm picks the pivot by taking the median of increments of 1/8 of the array. d is set to 1/8 of the size, and pl is set to 
the median of the first element, the element 1/8 down the array, and the element 2/8 down the array. Likewise, pm is set to the median of the middle 
element. the element 1/8 towards the beginning, and the element 1/8 towards the end. pn is set to the median of the end, 1/8 back, and 2/8 back. Then, 
the median of all of those medians is selected as the pivot. The reason there are three different ways to select the pivot is because of how much it is 
worth picking a good pivot. With few elemets (7), it doesn't really matter if the pivot position selected is bad, because the sort will not take long 
anyway. Likewise, for an array of size 7 to 40, getting the median of the beginning, middle, and end would be sufficient. Any addition selection will 
not greatly change the chances of getting a better pivot. With greater than 40 elements, it is good to sample from many parts of the array, because 
it will reduce the change of getting a bad pivot, which would be very costly with a large array.

The algorithm switches to an insertion sort when swap_cnt is equal to 0. This only happens if no switches are done while doing the quicksort. The 
program switches the pivot point to the beginning of the array, then sets two pointers to the second element and the end element. It then proceeds to 
go through each element, comparing it with the pivot. If none of the elements are in the wrong portion of the array (and none are equal to the pivot), 
then swap_cnt would be 0. It switches to an insertion sort because the array is likely small and almost sorted when no swaps are made. Insertion sort 
is efficient for short, almost sorted arrays, so that is why it is done.

ANSWER TO ANOTHER QUIESTION - JUST DID IT FOR FUN
r would be equal to 0 when an element is the same value as the pivot. When this is the case, swap_cnt is set to 1, and the element that is the same is 
swapped with the end or beginning element. It then increments or decrements the current "end" or "beginning" of the array. Esentially, it pushes all 
of the elements equal to the pivot to the beginning of the array or to the end of the array. I am not sure why it would do this. Perhaps it is so that 
is more likely to be picked as a pivot in a future iteration of the algorithm.

**GRADER: 4/4**