Homework 3 - Part B
===================
Due 2015/10/01 at the beginning of class.

Q3: What are the main differences between a binary search tree and a B-tree?

One of the main differences is that a B-tree is not a binary tree. B-tree nodes have many more than two children. Also, each node can  
contains more than a signle entry. Another difference is that the way a B-tree is implemented, none of the leaves become too deep. 
This prevents the problem of have a binary search tree than takes O(n) per operation, which would be the case when ordered elements 
are placed sequentially in a binary search tree. This is the sixth rule of the B-tree, which is every leaf has the same depth. Also, 
the methodology of inserting and deleting elements is slightly different, because most imlemntations allow for the tree to temporarily 
violate rules, then fix them. 

Q4: Consider a B-tree in which the maximum number of entries in a node is 4. What is the minimum number of entries in any non-root node?

If the maximum number of entries in a node is 4, then the minimum number of entries in a node would be 2. The minimum is simply half 
of the maximum. This is rule 1 of the B-tree: every node except the root has at least minimum entries.



**GRADER: **
**GRADER: 2/2**