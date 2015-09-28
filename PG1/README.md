Programming Assignment 1 - README
=================================

See `pg1.pdf` for the assignment.


_Your complexity analysis and other notes here_

Complexity analysis: The memory complexity of the implemetation of the undo feature in calc2,
which was implemented using a stack of stacks, is O(n^2), where n is the number of items added
to the calculator. This is because every time an item is added to the stack of numbers, the stack
as it looked before is pushed onto a stack of stack of doubles. This means that every number added
adds that number of elements to the stack of stacks. This results in 1+2+3+...+(n-1) for n pushes
onto the numbers stacks. Doing this sumation leads to n(n+1)/2 - 1 doubles that are added to the
stack. This reduces to O(n^2) space complexity.

The memory complexity for the implementation of the memory (undo) feature in calc4, however would
be O(n). This is because it simply creates one data structure, which creates one new node for every
push onto it, or two new nodes for a swap operation. It does not need to store the whole stack in
memory, because of the use of shared pointers. In this way, the previous stack are preserved by having
multiple references to the the same nodes.

In analyzing the space and time performance of the two implementations, calc4 performs a lot better.
When run with test4.sh, the calc2 cannot even complete the task. Running a "top" command to look at
the process statistics while it is running, it can take up to 21.0g of virtual memory, 90% of the CPUs,
and 94% of the computer's memory. It slows down quite the machines for everyone. One the other hand,
calc4 can successfully complete the test4.sh script, finishing in about .933 seconds, and only using
8.96 MB. Also, no memory is lost in calc4. When run with valgrind, all the blocks that were allocated
were freed, which is because of the shared pointers used in the implementation.

NOTE: I did not actually use a shared_stack class object for the final implementation of the persistent
data structure. This implementation did work: however, it took slightly too much overhead to make a
shared_stack. When the code was switched to implement it with an stl stack, it reduced the memory usage
by enough to bring it below 10 MB. The stl stack contains shared_ptr to Node<doubles>. Node is defined in
the shared_stack.h file, and it contains a constructor, a shared_ptr to another Node, and a data member of
type T.

_Grader comments here_

Good commenting throughout the code. Also, it is a good practice to put class and struct definitions in header files.
