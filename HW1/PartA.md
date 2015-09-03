Homework 1 - Part A
===================
Due 2015/09/01 at the beginning of class.

Q1. Fork and clone this repository according to the instructions at
[the repository root](https://bitbucket.org/CSE-30331-FA15/cse-30331-fa15). 
Note: in order to get credit for this question, your forked repository
must pass the checks in step 4.

*Please fill in the following so we know who you are:*

- Your name: Christopher Syers
- Your Notre Dame NetID: csyers

Q2. A class that uses dynamically allocated memory should always
include what three member functions (methods)? Why?

A class that uses dynamically allocated memory should always include
a copy constructor, an overloaded assignment operator, and a destructor.
The copy constructor and overloaded assignment operator serve a similar
purpose. They are used so that an object of a class with dynamic memory
is copied correctly. Instead of making copies of the pointers in one class
to the new object, the copy constructor and assignment operator should
allocate new memory for the new copy. This allows the new object to have
the correct value, but makes sure that it is not the same memory location
as the object being copied.
The destructor is responsible for freeing dynamic memory to the heap. If
one is not included, the object will continue to occupy heap memory, even 
when not in use.

To submit, do:

    git commit -am 'Submit Homework 1A'
    git push

