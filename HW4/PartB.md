Homework 4 - Part B
===================
Due 2015/10/29 at the beginning of class.

Q3. What are the advantages and disadvantages of separate chaining and open addressing?

Advantages of separate chaining: One advantage is that the hash function does not have to worry 
about clustering: as long as the hash function is uniformly distributed, it does not matter if 
hash values are close or adjacent (which is a problem in open addressing). Separate chaining also 
performs well with tables with high load factors and large records. The equation for number of 
table elements examined for separate chaining on page 619 reveals another advantage: it degrades 
lineraly as alpha approaches 1, or exceeds 1. Another advantage is that deletion does not cause 
many problems, and reduces the effective load factor.

Disadvantages of separate chaining: One disadvantage of separate chaining is having to navigate 
through pointers when searching and such. Operations on a linked list are usually O(n), so if 
there are a lot of elements that hash to the same key, hash table operations on those operations 
could be expensive. Also, whenever an element is added, a record has to be allocated, which 
incurs some overhead. 

Advantages of open addressing: One advantage of open addressing is that it can save memory if 
the entires are much smaller than a pointer and the load factor is not too small. It also saves 
the overhead time of allocating a new record each insertion. It can also have better locality of 
reference, espeically with linear probing, because the memory locations are physical close to 
each other, unlike having a list in separate chaining. 

Disadvantages of open addressing: One disadvantage of open addressing is that the number of 
entries in the table cannot exceed the number of slots in the array. This can be solved by 
increasing the number of slots, but that is costly. Another disadvantage is that as the load 
factor approaches 1, performance signicantly degrades, reaching almost O(n) complexity. Also, 
a disadvantage is that the hash function must not only uniformly distribute the keys, but must 
avoid having too many keys clustered together, which also reduces performace. Also, if the load 
factor is low, open addressing is a waste of memory, because the array is allocated. Deletion is 
also hard to deal with, because you cannot just reduce the effective load factor (because you 
cannot stop a search when you encounter a previously used location). 

Q4. A hash function should ideally have which properties? Circle all that apply.
(a). It uniformly distributes all possible keys throughout the array.
(b). It can be computed quickly.
(c). Its range (return value) is an integer.
(d). If two keys are equivalent, then they have the same hash value.

All of these apply. It should uniformly distribute to decrease clustering, which 
makes the average case operation faster. It should be quick, because insertion, 
deletion, and searching all require computing the hash function of a key, so it 
would be expensive if the function took a long time to compute. It should return 
an integer, because it is usually used to index an array. Two equivalent keys must 
produce the same hash value, because otherwise the hash function would not be deterministic.

Property c is not necessary, but it is ideal, because it allows for easy implementation 
when accessing the array that hold the records.




**GRADER: **
**GRADER: 2/2**