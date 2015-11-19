Homework 5 - Part D
===================
Due 2015/11/19 at the beginning of class. 2 points each question.

Q7. If you run Dijkstra's algorithm on a graph whose edge weights are
all +1, what would it be equivalent to? Explain.




If you run Dijkstra's algorithm on a graph whose edge weights are all
-1, what would it be equivalent to? Explain.




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
