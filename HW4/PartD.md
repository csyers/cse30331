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

The time comlexity of bucket sort is O(n + m). This is because there is a
