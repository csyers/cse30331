Homework 4 - Part D
===================
Due 2015/11/05 at the beginning of class.

Q7. Write a hash function for the following class:

    class person {
      std::string firstname, lastname;
      int birthyear, birthmonth, birthday;
    };

The hash function doesn't have to be great; we just want you to familiarize yourself with how to do it. You can use anything you want from STL or Boost, as long as the following compiles:

    std::unordered_set<person> me;

Please fill your solution in the file hw4q7.cpp.

Q8. In class, we did a simplified complexity analysis of bucket sort, assuming that m was O(n). Here, analyze both the time and space complexity of bucket sort, in terms of both m (the number of buckets) and n (the number of items to be sorted). Do not assume that m is O(n). Do assume:

- the hash function distributes keys evenly
- the hash table uses separate chaining (bucket sort always uses separate chaining) where the buckets are linked lists
- the inner sort is O(n^2) and is in-place (it’s commonly insertion sort)

The space complexity of a bucket sort using linked list as the hash table:
The space complexity would be O(n+m). Space complexity comes from the need of the auxiliary vector needed for the hash table to place items 
into. In the class handout, this corresponds to the pseudo code line "b <- an array of m buckets." This is the cause for the m in the space 
complexity analysis. The n comes because the bucket sort much make a copy of each element to be sorted when it is inserted into b[h(x)]. 
Therefore, whichever term is larger dominates the complexity. If there were 1000000 buckets and 10 elements, the space would be bound 
by the vector of size 1000000 needed to be the buckets. On the other hand, if there is only 1 bucket and 1000000 elements, then there 
would be a linked list of size 10000000, so the space would be bound by n.

The time complexity of a bucket sort:
Using the pseudocode from the class handout, the first loop inserts n elements into the temporary array. This loop is therefore O(n). Then, 
there is a loop that goes through each bucket. This loop sorts each bucket (I will come back to this), and then read from each bucket and 
inserts into the original list. This inserting portion is O(n+m), because each bucket will take c1(n/m)+c2 operations. There are m buckets, 
so multiplying this by m leads to c1n + c2m, which is O(n+m). Now, I will talk about the time complexity of the sorting in further detail. 

Intuitively, the sort to degenerate to O(n^2) when there is only 1 bucket, because then it would simply just be an insertion sort. Through 
a proof, you can show that if there are a sufficient amount of buckets (say n buckets), then the search would only be O(n). I will now show 
the complexity of sorting the m buckets: the expected number of elements in each bucket is n/m. The probablility that an element goes in a 
given bucket is 1/m. We want the expected value of this. This is a bionmial distribution, where p = 1/m. Mean = np = n/m, and variance = 
np(1-p) = n/m(1-1/m) = n/m - n/m^2. The number of operation in each search is then variance plus mean^2 = n/m - n/m^2 + n^2/m^2 = 
(nm^2 + mn^2 - mn)/m^3. So this term must also be added to the complexity. 

The total complexity can then be viewed as O(n + m + (nm^2 + mn^2 - mn)/m^3). This seems to make sense. When m is very low (say = 1), 
the comlexity should be n^2. In the above case it is, becuase the last term becomes O(n^2). When m dominates, then it becomes O(m), 
which is right because it has to go through all of the buckets at the end to construct the array. When n dominates and k is suficiently 
large (there are enough buckets), then the sort is O(n). 





**GRADER: Q8: Time complexity: O(n (1+n/m)), Space complexity: O(m+n) additional space
Score of HW 7 will not be shown up here, but will show up on Sakai with HW4 soon. So the point shown below only reflects your Q8 score**
**GRADER: 1/2**
