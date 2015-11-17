Homework 5 - Part B
===================
Due 2015/11/12 at the beginning of class.


Q3: If you are doing a BFS in a graph with n vertices, where n > 1, then how large can the queue become?

It would be able to get to the size of (n-1). This would happen where there is a connection between the starting vertex and 
all of the other vertices in the graph. In this case, the queue would start with the start vertex, and remove that to process it. 
If there are edges from that starting vertex to all other (n-1) vertices, then all of these would be placed in the queue. Then, 
each one would be processed. 

Q4: Given two vertices in a graph s and t, which of the two traversals (BFS and DFS) can be used to find if there is path from s to t?
    A.BFS
    B.DFS
    C.both BFS and DFS
    D.neither BFS or DFS

(C). Both types of traversals can be used to find if there is a path. You would simply start either search at s, and then see if t is 
marked at the end of the traversal.




**GRADER: **
**GRADER: 2/2**