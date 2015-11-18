Homework 5 - Part C
===================
Due 2015/11/17 at the beginning of class.

Q5: Which data structure is usually used for implementing Dijkstra’s shortest path algorithm?
    A.priority queue
    B.stack
    C.queue
    D.hash table

(A), a priority queue. You need to process the vertex that has the smallest value, so a priority queue would be used.

Q6: In Dijkstra’s algorithm, what is the initial value of the distance of each node (other than the starting vertex)?

The initial value of all of the distances execept the starting vertex is infinity, or some other sentinel value that indicates 
that there is no way to get to that vertex. These would be gradually replaced as the algorithm progresses, but they must start 
at infinity of some value that indicates that it is not valid yet.





**GRADER: **
**GRADER: 2/2**