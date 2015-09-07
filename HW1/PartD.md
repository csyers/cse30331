Homework 1 - Part D
===================
Due 9/10, the beginning of the class
(each question worthes two points)

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


**Q2:**  Analyze the time complexity of function `BLI_convexhull_2d` in Blender 
([convexhull2d.c](https://developer.blender.org/diffusion/B/browse/master/source/blender/blenlib/intern/convexhull2d.c), 
line `194`) in terms of _n_, the number of input points. Please note the following:

The convex hull of a set of 2-d points is the smallest convex polygon that contains all the points. You can 
read more at the following two pages, but do not refer to any other source!

* [Convex Hull](https://en.wikipedia.org/wiki/Convex_hull)
* [Montone Chain](https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain)

Assume that `qsort` (called at line `206`) takes **O(n log n)** time. `BLI_convexhull_2d()` calls `BLI_convexhull_2d_sorted()`, 
which you also need to analyze.

Assume that all other functions take constant (**O(1)**) time. The answer (**O(n log n)**) is given 
in the second link above, but you must justify your answer. In particular, your justification must explain 
why the double loop at lines `110` and `116` doesn’t lead to an **O(n^2)** complexity.
