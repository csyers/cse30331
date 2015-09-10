Homework 1 - Part D
===================
Due 9/10 at the beginning of class
(each question is worth two points)

**Q1:** The linked-list `node` class in the textbook (section 5.2) is _not_ designed to be used directly, 
because it doesn't implement a copy constructor, `operator=`, or a destructor. Describe three bad things
that the following code would do:

	:::c
	for (int i=0; i<1000000; i++) {
		node *a = nullptr;
		list_head_insert(a, 3.0);
		list_head_insert(a, 2.0);
		node *b = a;
		list_head_insert(b, 1.0);
		list_clear(a);
		node *c, *ctail;
		list_copy(b, c, ctail);
	}

There are a few problems with the code, as it is implemented, because of the lack of memory control of the Node 
class. I will describe what the code does and then mention, as I go along, the potential problems. Each time the 
program enters the loops, it declares a Node pointer to NULL called a. Then, it uses the built in function 
list_head_insert to insert two nodes, with values 3.0 and 2.0. So after these method calls, a points to 3.0, which 
has a link to 2.0, which has a link to NULL. Then, another node pointer is intialized, and it is equal to a. This 
is problem number 1. Because the assignment operator is not overloaded, b becomes a pointer that points to the SAME 
node object as a. Thus, when you inset at the head the value of 1.0, b points to 1.0, which links to 2.0, which links 
to 3.0, which link to null. Pointer a still points at 2.0, which points at 3.0, which links to NULL. Thus, when clear 
is called on a, the program frees the 2.0 and 3.0 node, and sets a to null. PROBLEM 2: b still points to 1.0, which 
still has a link to the memory address of the node 2.0 which was just removed. Then, node pointers c and ctail are 
initialized. The function list_copy is called which presents us with PROBLEM 3: I assume that list_copy would
try to traverse the list with b at its head down until the NULL pointer is reached. This will not happen, because
b points to node 3.0, which still has a link, but when it is dereferenced, it will not have an object it is pointing to. 
The loop then repeats. PROBLEM 4: because there is no destructor, when pointer b is moved to equal pointer a in the
next iteration, the node it was pointing to (value 1.0) is lost. It is never freed to the heap. This would cause 
1000000 node objects to be allocated but not freed.

**Q2:**  Analyze the time complexity of function `BLI_convexhull_2d` in Blender 
([convexhull2d.c](https://developer.blender.org/diffusion/B/browse/master/source/blender/blenlib/intern/convexhull2d.c), 
line `194`) in terms of _n_, the number of input points. Please note the following:

- The convex hull of a set of 2-d points is the smallest convex polygon that contains all the points. You can 
read more at the following two pages, but do not refer to any other source!

  * [Convex Hull](https://en.wikipedia.org/wiki/Convex_hull)
  * [Monotone Chain](https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain)

- Assume that `qsort` (called at line `206`) takes **O(n log n)** time. Then `BLI_convexhull_2d()` calls `BLI_convexhull_2d_sorted()`, 
which you also need to analyze. Assume that all other functions take constant (**O(1)**) time. 

- The answer (**O(n log n)**) is given in the second link above, but you must justify your answer. In particular, 
your justification must explain why the double loop at lines `110` and `116` doesn’t lead to an **O(n^2)** complexity.

The algorithm would be O(n log n) complexity. This is because the sort takes O(n log n), and then the actual calculation of the
convex hull would be O(n). Two different hulls are computed, so the function call of BLI_convexfull_2d_sorted() would take 2n
time complexity. All other functions, as it explained in the problem, are O(1). So the overall time complexity of the function 
is n log(n) + 2n + c, which, as n goes to infitity, would be O(n log n).

To explain why the function BLI_convexfull_2d_sorted() is not O(n^2), I will explain why the nested for loops at lines 110 and 116
do not result in quadratic time. The loops in question calculate the upper and lower hulls. To get n^2 time complexity, the loops
would have to have a case where each point would be compared with every other point in the points array. For example, the program 
would have to get to 2 points in the r_points stack, then use every point in the point array before deciding on whatever the correct 
next point is on the hull. This is almost certainly not the case, in fact I think it is impossible that it is the case. It is much
more likely that the algorithm will not have to compare the top two points will all of the remaining points. 

I will attempt to explain this in a few different ways. Because the algorithm scans through a list of points sorted by their x values,
it scans from left to right or right to left. So if, after getting the initial couple points in the r_points array, it takes almost
n comparisons in the inner loop to find the next correct point (the only that satisfies the "is_left" function and breaks), that point
must be almost at the end of set of points. Then, there are only so many points farther to the left/right until the algorithm reaches
the end of the list of sorted points. In other words, there is no way that every point needs to be compared to every other point, which
is when the nested loops would have O(n^2) time complexity.

I believe this is a case of amortized time complexity. This means that the event of a worse case is not very likely, so it should not
be classified as its worse case (O(n^2)). It only encounters the worst case if the if statement on like 118 is false every time. This
cannot be the case. It can only encounter that worst case once in a while. Therefore, it would be incorrect to classify this as O(n^2),
and instead it should be classified at O(n). It happens twice, once for the top hull and once for the bottom hull, resulting in 2n time
complexity. This doesn't outweigh the sort operation, which is O(n log(n)). Therefore, the algorithm would be O(n log(n)). 
