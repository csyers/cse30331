
Homework 1 - Part C
===================

Due 2015/09/08 at the beginning of class.


Q1: Using Big-O notation, give the worst-case times for each of the following stack operations, for a stack of size N.

Assuming stack is being implemented with a linked list (also assumes a size variable is kept):
Empty: Empty is O(1). It just looks at the size of the size variable.
Size: Size is O(1). It just returns the number of elements in the stack, which is held in the size variable.
Push: Push is O(1) worst-case time. It simply adds an element to the front of the list. No shifting/indexing required.
Pop: Pop is O(1). It just needs to remove 1 element from the head of the list. It does not require any shifting.
Peek:  Peek is O(1). Regardless of size, it just returns the value of the top element by dereferencing the top pointer.

Q2: The STL queue is a container adapter that wraps around another underlying sequence container.  Given a choice among a vector, list, or deque, which sequence container you would choose as the underlying container for a queue, and why?

A queue is a container adapter which restricts the behavior of a container to a FIFO paradigm.
In this paradigm, items are pushed to the back and popped from the front. I would choose to use
a deque for this behavior. There is O(1) time complexity for insertion/deletion at the beginning
or end of a deque, and that is the only behavior that would be present in a queue (other than the
standard size, empty, front, and back operations). It is not easy to remove from the front of a 
vector, so that would not be a good choice (front removal would be linear time complexity). 
A list or deque would equivalent in terms of complexity, but I would choose a deque because that
is the standard implementation. 
