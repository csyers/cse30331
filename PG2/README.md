Programming Assignment 2 - README
=================================

_Your experimental results here_

SEE THE FILE NAME analysis.txt FOR RESULTS OF THE 5 TRIALS

distance3 - average time: 11.9735788	average space: 91.11875
This was the fastest sort of all. This is because it uses an advanced sorting method, the introsort, which is used to sort arrays. It is fast because it was written by skilled programmers, who considered many possible cases, and probably use advanced techniques in predicting a pivot point. It probably amost guarentees a O(n log n) sort. The space complexity was second best. This would be because no additional space is needed to do a introsort.

distance4a - average time: 12.090561	average space: 121.6960934
This was the second fastest sort. This is because it uses the GCC mergesort, which is an advanced implementation of the mergesort. Mergesort is O(n log n), so it is very fast. But because it requires O(n) space, this implementation of the sort is not as good spacewise as the vector sort. 

distance4b - average time: 12.606826	average space: 152.649219
This algorithm performed third best in time. This is because it uses the same algorithm as the distance3 method (the vector introsort). This algorithm is O(n log n) average case, so it will be very fast sorting the vector. This implementation has the worst space measurement, however. This is because the already large list has to be copied to a differect vector - almost doulbing the space needed if it was just kept in a list.

distance5 - average time: 13.4235584	average space: 90.9703124
This algorithm performed the worst in terms of time. This makes sense, because it is implemenetated as a very simple and naive quicksort algorithm. Specifically, it just uses the middle element as the pivot, instead of trying to develop a more sophisticated method of picking a pivot. Also, it uses quicksort all the way down, instead of switching to an insertsort under certain conditions, which seems to make it faster. The space usage of this implementation was actually the best. This is because it only requires the original vector, and the sorting algorithm does not use any additional space.

_Grader comments here_

