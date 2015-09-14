Homework 2 - Part A
===================
Due 2015/09/15 at the beginning of class.
 

1. In the first step of inserting a new entry into a binary heap, where is the new entry initially placed? Why?

In the first step, the new entry is placed in the spot that preserve the fact that the tree must be complete. This 
means placing it as far left in the deepest level of the tree, or to the far left of a new depth, if the heap was 
already full. It then uses the reheapification upward algorithm to make the sure the heap still obeys the condition 
that an entry is never less than the entry of its children. So basically, the fact that the new entry is intially 
placed at the place that keeps the binary tree complete is because a heap must be a complete binary tree, and this 
ensures that this will be true after the upward switching operations.

2. Suppose top is called on a priority queue that has exactly two entries with equal priority. How is the return value of top selected?
A. The implementation gets to choose either one.
B. The one which was inserted first.
C. The one which was inserted most recently.
D. This can never happen (violates the precondition).

(A). The implementation decides which one to remove. This is on page 546 of the textbook, where it says "If there are several equally 
high priorities, the implementation may decide which one to return." The only post-condition is that the heap remains a heap after the 
operation, which would be true no matter what element is returned. So it is up to the implementation.
