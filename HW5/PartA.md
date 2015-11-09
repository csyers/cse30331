Homework 5 - Part A
===================
Due 2015/11/10 at the beginning of class.

Q1: Which statement or statements are true?
    A. A loop is the same thing as a cycle.
    B. In a directed graph, if there is an edge from u to v and an edge from v to u, then the edges are called multiple edges.
    C. In an undirected graph, the order of two connected vertices is unimportant. 
    D. Every problem can be represented as a graph.

(A) is false. A loop means an edge that connects a vertex to itself. A cycle is a closed walk, which is a set of vertices that can 
be followed to get back to the starting vetex. For example, a loop would be A->A, but a cycle could be the path A->B->A.

(B) is false, because to have multiple edges in a directed grapth, two edges need to connect two vertices in the same direction.

(C) is true. For an undirected graph, as long as two vertices are connected with an edge, the order is not important. An edge from 
u to v means the same thing as an edge from v to u. 

(D) is false. The book states that "often, a problem can be represented as a graph," but that does not mean that every problem can be.



Q2:    Below is a graph represented as an adjacency matrix. Does it have any loops? If so, where?

| 0 | 1 | 2 | 3
--|---|---|---|---
0 | T | F | F | T	
1 | F | F | F | T
2 | T | T | T | F	
3 | F | F | T | F

Yes, there are loops. Vertex 0 loops to itself, and so does vertex 2.
