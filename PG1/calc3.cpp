// Christopher Syers		CSE30331 Data Structures
// Septempber 15, 2015		PG1

// Implentation of a RPN calculator, using the My_stack class.
// Calculator includes a memory, which is implemented using a
// stack of My_stacks. It is very inefficient on memory.

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h> // for isatty
#include <stack>
#include "My_stack.h" // for class My_stack
using namespace std;

// define a new type of enum, called operation
enum operation{
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE
};
typedef enum operation oper_t;	// define a typedef so the enum can be called oper_t

const bool interactive = isatty(0);
int linenum = 0;

void error (const char *s) {
  if (interactive) {
    cout << "error: " << s << endl;
  } else {
    cerr << "error: " << s << " on line " << linenum << endl;
  }
}

// valid_size(stack<double>& numbers)
// function that returns true if a stack contains 2 or more elements,
// false otherwise 
// precondition: numbers is a stack of doubles
// postcondition: true is returned is the size of the stack is 2 or greater, 
// false is returned otherwise
bool valid_size(My_stack<double>& numbers){
  if(numbers.get_size() < 2){		// if size of stack is less than 2
    return false;			// return false
  } else {
    return true;			// else, return true
  }
}

// do_operation(stack<double>& numbers, oper_t t)
// function that does operation t on the top two elements of a stack
// precondition: stack contains at least 2 elements
// postcondition: the number returned is the result of the two numbers
// with the given operation t, and those two numbers are removed from
// the stack
double do_operation(My_stack<double>& numbers, oper_t t){
  double x = numbers.top();	// get first element
  numbers.pop();		// remove top element
  double y = numbers.top();	// get second element
  numbers.pop();		// remove top element
  double result;
  switch(t){			// switch on the enum to find operation
    case ADD:		
      result =  x+y;		
      break;
    case MULTIPLY:
      result =  x*y;
      break;
    case DIVIDE:
      result = y/x;
      break;
    case SUBTRACT:
      result = y-x;
      break;
  }
  return result;		// return the result of the operation
}

// drop(stack<double>& numbers)
// function that removes the top element in the stack. returns an error if 
// the stack is empty
// precondition: numbers is a stack of doubles
// postcondition: top element is removed from stack, stack remains empty if it is already empty
void drop(My_stack<double>& numbers){
  if(numbers.get_size() == 0){		// if the stack is empty
    error("stack underflow");		// return an error
    return;
  }
  numbers.pop();			// remove top element
}

// swap(stack<double>& numbers)
// function that swaps the top two elements of a stack that is passed in
// precondition: numbers is a stack of doubles
// postcondition: top two elements are switched, or the stack is empty if
// 		  there were fewer than 2 elements in the stack to begin
void swap(My_stack<double>& numbers){
  if(numbers.get_size() < 2){			// checks to see the size of the stack is less than 2
    while(!numbers.empty()){			// loop to empty the array
      numbers.pop();
    }
    error("stack underflow");			// return an error
    return;
  }
  double first, second;				
  first = numbers.top();			// get first element
  numbers.pop();				// remove top element
  second = numbers.top();			// get second element
  numbers.pop();				// remove top element
  numbers.push(first);				// push the stored values in the opposite order
  numbers.push(second);	
}

// undo(stack<double>& numbers, stack<stack<double>>& previous_stacks)
// function that undoes the previous operation by setting the stack equal
// to the top element of the stack of stacks. It also removes the top element
// from the stack of stacks
// precondition: number is a stack of doubles and previous_stacks is a stack of
// stacks of doubles
// postcondition: stack is set to the top element of previous_stacks, and the top
// element is removed from previous_stacks   
void undo(My_stack<double>& numbers, stack<My_stack<double>>& previous_stacks){
  if (previous_stacks.empty()){		// if the previous_stacks is empty, report an error and return
    while(!numbers.empty()){
      numbers.pop();
    }
    error("cannot undo");
    return;
  }
  numbers = previous_stacks.top();	// set number to the top element of previous_stacks
  previous_stacks.pop();		// removes top element of previous stack
}

template <typename Number>
int string_to_number (const string &s, Number &x) {
  stringstream ss(s);
  ss >> x;
  if (ss.eof() && !ss.fail()) 
    return 0;
  else
    return -1;
}

int main (int argc, char *argv[]) {
  My_stack<double> numbers;			// initialize the My_stack of doubles to store the operands
  stack<My_stack<double>> previous_stacks;	// a stack of My_stack classes of doubles, to hold previous stacks (for undo function)
  while (!cin.eof()) {
    if (interactive) cout << "> ";
    
    double result;				// stores the result of the operations
    string s;
    getline(cin, s);
    linenum++;

    double x;	
    if (string_to_number(s, x) == 0) {        	// if the input was a number
      cout << x << endl;			// output x
      previous_stacks.push(numbers);		// push the previous stack into the stack of stacks
      numbers.push(x);				// add x to the stack
    } else if (s == "") {
      // if nothing was passed into the program, do nothing
    } else {
      if (s=="*"){				// case for multiplication
	previous_stacks.push(numbers);		// push previous stack into stack of stacks
        if(valid_size(numbers)){		// if the stack is big enough,
          result = do_operation(numbers,MULTIPLY);	// multiply top 2 numbers
	  cout << result << endl;			// display result
	  numbers.push(result);				// push the result onto the stack
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
          error("stack underflow");
        }
      } else if (s=="+"){			// case for addition, same steps as above
	previous_stacks.push(numbers);		// push previous stack into stack of stacks
        if(valid_size(numbers)){
          result = do_operation(numbers,ADD);
	  cout << result << endl;
	  numbers.push(result);
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
          error("stack underflow");
        }
      } else if (s=="/"){			// case for division, same steps as above
	previous_stacks.push(numbers);		// push previous stack into stack of stacks
        if(valid_size(numbers)){
          result = do_operation(numbers,DIVIDE);
	  cout << result << endl;
	  numbers.push(result);
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
          error("stack underflow");
        }
      } else if (s=="-"){			// case for subtraction, same steps as above
	previous_stacks.push(numbers);		// push previous stack into stack of stacks
        if(valid_size(numbers)){
          result = do_operation(numbers,SUBTRACT);
	  cout << result << endl;
	  numbers.push(result);
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
          error("stack underflow");
        }
      } else if (s=="drop"){			// if the input was "drop," then call the drop function
	previous_stacks.push(numbers);		// push previous stack into stack of stacks
        drop(numbers);
        if(!numbers.empty()){			// if the last element was dropped, you cannot print the top element
  	  cout << numbers.top() << endl;	// prints the top element in the stack
        }
      } else if (s=="swap"){			// if the input was "swap," then call the swap function
	previous_stacks.push(numbers);		// push previous stack into stack of stacks
        swap(numbers);	
        if(!numbers.empty()){
  	  cout << numbers.top() << endl;	// prints the top element in the stack
        }
      } else if (s=="undo"){			// if the input is "undo", call the undo function
        undo(numbers,previous_stacks);
        if(!numbers.empty()){
	  cout << numbers.top() << endl;	// print the top elemetn in the new stack
        }
      }
    }
  }
}
