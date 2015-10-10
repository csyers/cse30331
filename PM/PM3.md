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

WORK ITEM #1 Issue 98 on Github

I am planning on adding a new feature (more like improving on an existing 
feature). Right now, there is a thing called the FunctionList, which displays 
the functions found in the currently opened file. Chris Syers will work on this 
piece. The requested improvement can be found at the following link:

https://github.com/notepad-plus-plus/notepad-plus-plus/issues/98

This requested feature is for notepad++ to keep the sorted order of the function 
list when opening a new file or closing a reopening notepad++. Desriptions on how 
the FunctionList work appear on the notepad++ website at:

https://notepad-plus-plus.org/features/function-list.html

It is needed to make the FunctionList more useful to the end user. Having the ability 
to keep a sorted order will be easier for the user to know what order their functions 
appear in the FunctionList. Right now, the overarching class of notepad++ is an object 
called Notepad_plus, which is defined in Notepad_plus.h. This contains a pointer to a 
FunctionListPanel object, which is the object of interest. This object has a lot of 
functions, including ones to see if it is open, to set its color, and a display function. 
The FunctionListPanel declaration and implementation can be found in the following directory: 

https://github.com/notepad-plus-plus/notepad-plus-plus/tree/ea548169ccc601c7741be8ed25796f150a296cf5/PowerEditor/src/WinControls/FunctionList

It has a TreeView object, which is how to stores what appears in the FunctionList in the 
application. I will determine how the program determines what order things are displayed, 
and see if there is a way to preserve what sorting was found before a file was opened and, 
and when the file is closed.


WORK ITEM #2 - Issue 235/240 (Mason Prosser)

I am planning on fixing the Find/Replace function, which currently crashes Notepad++ whenever it finds
more than ~6000 matches. According to user @ariccio in the discussion of issue 235, this error is caused
by a std::bad_alloc thrown in FindReplaceDlg.cpp, the file largely responsible for the find/replace
function. Links to the issues can be found here:

https://github.com/notepad-plus-plus/notepad-plus-plus/issues/235
https://github.com/notepad-plus-plus/notepad-plus-plus/issues/240

The file in question can be found here:

https://github.com/notepad-plus-plus/notepad-plus-plus/blob/02b342f4410845593d2b913b392ad5f49136c4ac/PowerEditor/src/ScitillaComponent/FindReplaceDlg.cpp

Currently, the method of storing the matches is not very efficient with memory, which is likely why the
bad_alloc is thrown. I plan to optimize this function so that the container of regex matches uses less
space, and propose to add some sort of graceful error handling if this fix doesn't cover all cases.

WORK ITEM #3

Tim will be working on open issue #323. Notepad++ has a feature that keeps track of a user's find/replace search history. The history is maintained up to a certain depth, defined in a config file. Currently there is a bug where, if the depth is set higher than the default, the entire search history is lost. The recording/retrieving of the history is maintained by the function feedFindHistoryParameters( *node), which progresses through the config.xml file where the search histories are written. The time complexity of this process seems to be O(n), as there is just one for loop that runs the amount of times equal the amount of items in the history. There are no apparent errors with the function, but I suspect there to be dependencies with other functions being called within it. This function is called within the function getUserParametersFromXmlTree(), which progresses through an xml file of user parameters. The preconditions are the existence of the user parameter xml tree. The function returns void, but appends attribute of class "name", presumably the instance of a previous search, into an object find_history.


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

