Homework 3 - Part A
===================
Due 2015/09/29 at the beginning of class.

Q1: What are the stopping cases for the recursive binary search function?

The stopping cases for the recusive binary search are that the element is found, or the size of the list to search is 0. When the object is found, the location of that object is stored in a variable and a flag is set to be true, adn no more calls to a recursive search function are made. Likewise, when the list is divided in half too many times, eventually the size of the list will get to 0, meaning there are no more elements to search. This results in a breaking of the recursion, and the found flag would still be 0 if the element was not found.

Q2: The following numbers are inserted into an empty binary search tree in the given order: 10, 1, 3, 5, 15, 12, 16. What is the longest root-to-leaf path in the resulting tree?

The binary search tree with those numbers would be:

			10
	
	1				15

		3		12		16

			5

The depth of the tree is 3, because the element 5 is 3 nodes away from the root node, which is 10. I am not sure whether the root node is inlucded in the root-to-leaf number. Including the root, the longest root-to-leaf path is 4 (10 -> 1 -> 3 -> 5), and not including the root, it would be 3.
