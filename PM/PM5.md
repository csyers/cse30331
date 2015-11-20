Milestone 5
===========

Due: 2015/11/19 at 11:59pm
Points: 2

5a. Discuss how you are measuring the performance of your
modifications. For example:

- Inserting code to output time stamps
- Using vmstat and valgrind to study the RAM requirements
- We will compile with profiler flags and run the code through Intel's vtune.

I will most likely use time stamps to measure the time of sorting the function. The 
easiest way to do this will probably to print two time stamps - one immediately before 
starting the forward-and backward sort of the function list, and one immediately after 
the function ocmpletes. To get the most accurate results, I wil lhave to have a file with 
a large number of functions (make n high). 

In terms of space requirements, I will try to use valgrind to get the space usage. This might 
be difficult because I am compiling the project on windows with visual basic 2013. I will investigate 
if there are any easy to use window space management tools that I can download to investigate the 
space affect of the improvmenet on the overall project.

5b. What results have you gotten so far? If you have run into any
problems, please describe them.

I have not been able to get many results so far. This comes mainly because of 
the learning curve associated with using Microsoft Visual Studios Community 2015. 
I am so used to using g++ on the student machines, getting things to build and compile, 
and managing the error messages output by the compiler from visual studios is very difficult. 
I will continue to learn how to use visual studios so I can better edit and test my proposed 
improvements to Notepad++.

Another problem I have run into is understand the large existing code base. There are over 300k 
lines of code in this project, so it is sometimes difficult to track things down to their origins. 
For example, almost all of the objects are defined in different modules, which are sometimes difficult 
to understand, compared to code I am used to looking at that uses stl and boost objects. There are not 
many comments either, which makes it difficult to work with.

A third problem I have been having is abiding by the strict code standards needed for the project. It 
will take a while to get it formatted correctly in order to have a chance of being accepted by the community.
