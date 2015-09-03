Homework 1 - Part B
===================

Due 2015/09/03 at the beginning of class.
(For more submission questions, please refer to PartA)

1. In a few words, summarize the advantages of each of: singly-linked lists, doubly-linked lists, and circularly-linked lists.

One advantage of singly-linked list (over an array, for example), is that insertion/deletion
at at a cursor is constant time, as opposed to a dynamic array, where that operation is linear
time. Linked lists are also easy to iterate through, because each contains a pointer to the
next node.

An advantage of a doubly-linked list is that by having a pointer to the next node and the previous
node, operations that require a two-way cursor are easily and efficiently implemented. Double-linked
lists can be traversed easily both forward and backward. 

An advantage of a circularly-linked list is that it is easy to go back to the beginning in a loop.
This could make implementation of something like a board game easy, where there is a loop that
goes through all members of a the circularly linked list. Also, you can reach any node from any 
starting node.

2. Where are the template parameters of a template visible?

    (a) inside the block that contains `template<...>`
    (b) inside the function/class that immediately follows `template<...>`
    (c) the whole program
    (d) all of the above

The template parameters of a template are visible in (b), the function or class that follows
the template prefix `template<...>`. It is not the whole program, because each templated
class or function needs its own template prefix, and its own template parameters. The template
parameter is specific for the function/class that it preceedes.
  
