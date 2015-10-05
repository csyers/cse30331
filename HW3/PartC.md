Homework 3 - Part C
===================
Due 2015/10/06 at the beginning of class.

Q5: What other data structure is a red-black tree equivalent to?

A red-black tree is equivalent to a binary search tree, except that it is 
self balancing. This corrects the problem of a BST, which may become very 
lopsided and lead to worst case operation of O(n), instead of the preferred 
O(log n). A red-black tree is a binary tree, because each node can have two 
children, but it has additional information (whether the node is red or black).

Q6: What is the worst-case running time of searching for an element of a red-black tree? Use big-O in terms of n, the number of elements in the tree.

Searching in a binary search tree is O(log n). This is because it is simply a 
BST, which has an average case of O(log n), but because a red-black tree is 
always nearly balanced, its worst-case running time for seartch is O(log n).

