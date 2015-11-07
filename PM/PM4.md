Milestone 4
===========

Due: 2015/11/05 at 11:59pm
Points: 2

4a. For each modification, you should have an idea that you plan to
implement. Describe your idea, and its expected performance
(asymptotic time/space complexity and/or practical time/space usage).

The modification I will be trying to do will be adding a reverse-sort 
option to the function panel, and to possible imporve the time of the sort 
for the strings in the function panel. Right now, the list of display string 
are stored in a binary tree called a TreeView. It hold items of type HTREEITEM. 
I will attempt to make FunctionListPanel display the contents of its tree in 
reverse order when a button is pressed.

Time complexity:
A reverse order traversal has the same time complexity of an in-order traversal: 
O(n). This is because each element must be processes, but it does not take 
any more complexity than that.

I will also dive deeper into the idea of maybe changing the implemetation to be 
of a hash table (with the possiblity of implemeting a bucket sort when the 
elements need to be ordered. This would improve the insertion, which would 
currently be O(log n) with a BST, to O(1), and the sorting would be O(n) 
approximately. This might not be ideal, because of the need to have a fast 
way of printing the functions in order when the button is pressed by the user. 
This also might be wasteful of space because there are oftentimes very few 
functions, so the hash table would not be very full.

I will also attempt to replicate the menchanisms that are in place for acutally 
adding a button to the FunctionListPanel widget. This would not add much time 
or space complexity, because it would just require one extra check when the 
sorting function is called (which button is pressed).


4b. How is your team managing the project source code? Are you working
on multiple computers? Do you have a shared repository? Are you using
branches to make experimental changes to the code?

Because the scopr of our projects do not overlap, we will not be using 
branches on the same repository to make experimental changes. Instead, 
we will each branch off of the master repository, which is hosted on 
github, and work from there. This is more conducive to how the developers 
want to see code sumbitted - they only want one change per pull request. 
So because we are all working on separate issues, we would all have to push 
our changes separately anyway. Therefore, we will each be working on seaprate 
branches, but can still provide support to each other if needed.
