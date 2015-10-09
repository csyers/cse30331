Milestone 3
===========

Due: 2015/10/08 at 11:59pm
Points: 2

3a. By now, each team member should have selected something specific
to work on. It could be:

- to add a new feature,
- to optimize a function (for time or memory efficiency), or
- to fix a problem.

In any case, it should relate somehow to a data structure or algorithm
covered in class. For each,

- State who will work on this piece.
- Describe what you want to do. If it's a new feature: What is it and
  why is it needed? If it's something inefficient or broken: What is
  it and how is it currently implemented? What is its asymptotic
  time/space complexity? What's wrong with it?
- Describe how this piece interfaces (or will interface) with the rest
  of the code. If it's a function, what are the pre- and
  post-conditions? If it's a class, what are the pre- and
  post-conditions of its public member functions?

3b. You should also be in contact with the developer community (ask
your TA for tips on how to do this successfully). Cut and paste an
excerpt from one of your conversations.

The following quote is part of the conversation I had with someone 
on the application's gitter site:

dail8859 Oct 06 06:39
@csyers So it sounds like you've built the SciLexer.dll and placed it in the PowerEditor/bin directory. How are you launching Notepad++, from within Visual Studios? Once the executable is built, VS also copies it (and also the xml files) to the bin directory. Also, are you building the "Release" or "Debug" configuration?
csyers Oct 06 08:07
@dail8859 thank you for your reply! I have built SciLexer.dll, but I placed it in the PowerEditor/visual.net/Unicode Debug directory, because that is where the notepad++ executable ends up when I build it clicking "Build->Build Notepad++" from VS, after opening the notepadPlus VC++ Project file found in the PowerEditor/visual.net directory. To launch, I just clicked on the .exe in the Unicode Debug directory. Is something wrong with the way I am building it? Thank you for your help.
dail8859 Oct 06 08:11
I think since you are building the "Debug" configuration, you need to copy the xml files manually into the Unicode Debug directory.
I usually just do the "Release" version myself, but the "Debug" should work also.

