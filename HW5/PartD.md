Homework 5 - Part D
===================
Due 2015/11/19 at the beginning of class. 2 points each question.

Q7. If you run Dijkstra's algorithm on a graph whose edge weights are
all +1, what would it be equivalent to? Explain.

This would be equivalent to a BFS. The neighbors of the start vertex will be added to the priority queue with 
priority 1, so one of those will be selected for the next iteration. All neightbors of that node would be added 
to the queue with priority 2. So none of those would be selected out of the queue until all the neighbors of a 
were processed. This esentially makes the priority queue act as a regular queue, so the traversal would be a BFS.


If you run Dijkstra's algorithm on a graph whose edge weights are all
-1, what would it be equivalent to? Explain.

This would result in a DFS. This is because once you start down a path, that same path will always be the lowest 
priority in the queue, so it will act like a stack. For example, if there is a graph with edges A->B, B->D, A->C, and 
C->D, starting a search from A would result in the prioriy queue containing B:-1 and C:-1 in the first pass, then 
randomly choosing B would have C:-1 and D:-2 in the queue. Then, D would be selected, and so C:-3 and C:-1 would be 
in the queue. Then C:-3 would be placed in the marked vector. This is equivalent to DFS. The weights would be incorrect, 
because they have to be non-negative to ensure that the priorities would represent the shorest distance.


Q8. Makefiles can be viewed as graphs of dependencies.  For instance,
the Makefile for PG3 can be represented as the following graph:

![Dependency graph](https://bitbucket.org/CSE-30331-FA15/cse-30331-fa15/raw/master/HW5/pg3.png)

Given a Makefile and a target, it should be possible to perform a
graph traversal to find all the dependencies of a particular target.
For instance, the target `distance.o` has 2 dependencies:
`distance.hpp` and `distance.cpp`.  The target `test1`, on the other
hand, has 6 dependencies: `bintree.hpp`, `distance.cpp`,
`distance.hpp`, `distance.o`, `test1.cpp`, and `test1.o`.

For this question, complete the provided `hw5q8.cpp` program which reads
a Makefile into a graph representation and then performs a graph
traversal to find all the dependencies for the provided node. You can
reuse any code from the book or the examples from class.

Here is an example invocation of the program:

```
$ ./hw5q8 pg3.Makefile test1
There are 6 dependencies for target test1:
        bintree.hpp
        distance.cpp
        distance.hpp
        distance.o
        test1.cpp
        test1.o
```



**GRADER: Your Q8 score will be entered to Sakai separately**
**GRADER: 2/2**
