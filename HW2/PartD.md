Homework 2 - Part D
===================
Due 2015/09/24 at 9:30am. 2 points each question.


Q7. What sorting algorithm(s) would you use in the following physical situations, and why? Choose from among the sorting algorithms we’ve learned (but if you want to get creative, you can look for other algorithms as well).

- Sorting a hand of 7 playing cards by increasing number (A, 2, …, 10, J, Q, K)
- Sorting 100 tigers in 100 cages alphabetically by name
- Sorting 10,000 US coins by increasing value


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
