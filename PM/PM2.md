Milestone 2
===========

Due: 2015/09/24 at 11:59pm
Points: 2

Project Selected: Notepad++

2a. By now, you should have committed to an application to work on.

Talk about the community of developers for your application. How
active is the community discussion forum? Are there regular stable
releases of the source code? Is there a formal mechanism to submit
bugs?  Describe how the code is structured: for example, how large is
it (lines of code), what language(s) is it written in, what
platform(s) is it written for, what external library dependencies are
there?

The community of Notepad++ is extremely active. The community discussion 
forum is found at https://notepad-plus-plus.org/community/, and has posts 
every few hours. There are a lot of stable releases of the code. It appears 
that a release happens about every two weeks. 

There is also a wiki page for Notepad++. It can be found at http://docs.notepad-plus-plus.org/index.php/Main_Page. This contains information about how to tool works and its features. 
There is also a page to tell users how to contribute (https://github.com/notepad-plus-plus/notepad-plus-plus/blob/master/CONTRIBUTING.md). This contains information about how to contribute, and the 
standards exepcted of all code that is pushed.

There is a system for issue/bug tracking. These can be found at https://github.com/notepad-plus-plus/notepad-plus-plus/issues. The system is as follows - any 
pull request must be attached to an open issue, or they will not get reviewed. 
To submit a bug report, you would add a new issue, and it would get reviewed, 
and made into a fixable but if approved. There are currently 484 open issues.

Using a tool called cloc, I counted the SLOC (source lines of code) of the github 
repository that holds Notepad++. The file git_stats.txt contains the output of that 
program. It reveals that there are over 300,000 lines of code in the project, most of 
which (130k) being C++. The other most popular languages are XML and C/C++ header files. 

Notepad++ is written exclusively for windows. In terms of external libraries, it depends 
on Win32 API, and STL. It also has a list of external dependencies listed in Visual Studio, 
which include algorithm, assert, cmath, and other C libraries.

2b. You should also be able to successfully compile and run your
chosen application.

Describe the environment (hardware, operating system, compiler) where
you will do your development. You can use a virtual machine like
VirtualBox or VMWare Player. If you have successfully compiled and run
your application, state the date that your team first did so. If not,
please explain in detail the challenges you are having, and how you
plan to overcome them. What errors do you get? Are there tests to help
you verify you have it working correctly? Have you contacted the
software's development team? Have you met with TAs?

The environment in which I will do my developement is in 2015 Visual 
Studio Community Visual C++ environment. This is the IDE recommended 
by the Notepad++ community. The compiler is g++, I believe. It will 
be done on my windows 7 machine. 

In an attempt to build, it did not quite work. There was an error message 
about a missiling .dll file called SciLexer.dll. After trying for a while 
to build this dll and put it in the right place, the same error message 
continued to appear. It says "SCINTILLA ERROR: cannot load dynamic libarary". 
The next steps are to continue to look at other people with similar problems, 
and change things around until it can link to the dynmaic library. 

The build was indeed successful, as indicated by Visual Studio. The executable 
could not be run, however, because of the dll problem. The test to verify 
that it built correctly is to simply get the text editor up and running, instead 
of getting the .dll linking error.
