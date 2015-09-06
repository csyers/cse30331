
Homework 1 - Part C
===================

Due 2015/09/08 at the beginning of class.


Q1: Using Big-O notation, give the worst-case times for each of the following stack operations, for a stack of size N.

Assuming stack is being implemented with a dynmaic array:
Empty: Empty is O(1). It simply would compare the number of elements in stack to 0.
Size: Size is O(1). It just returns the number of elements in the stack.
Push: Push is O(1) worst-case time. It adds an element to the top. No shifting/indexing required.
Pop: Pop is O(1). It just needs to remove 1 element. It does not require any shifting.
Peek:  Peek is O(1). Regardless of size, it just returns the value of the top element.

Q2: The STL queue is a container adapter that wraps around another underlying sequence container.  Given a choice among a vector, list, or deque, which sequence container you would choose as the underlying container for a queue, and why?

A queue is a container adapter which restricts the behavior of a container to a FIFO paradigm.
In this paradigm, items are pushed to the back and popped from the front. I would choose to use
a deque for this behavior. There is O(1) time complexity for insertion/deletion at the beginning
or end of a deque, and that is the only behavior that wouldbe present in a queue. Although they
all might be equal, I would choose a deque. 
