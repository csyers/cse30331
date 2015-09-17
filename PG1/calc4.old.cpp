// Christopher Syers		CSE30331 Data Structures
// Septempber 15, 2015		PG1

// Implentation of a RPN calculator, using the My_stack class.
// Calculator includes a memory, which is implemented using a
// persistent data structure in the form of a vector of Node 
// pointers.

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h> // for isatty
#include <stack>
#include "My_stack.h" // for class My_stack
#include <vector>

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
void do_operation(My_stack<double>& numbers, oper_t t,vector<Node<double>*>& memory){
  Node<double>* back = memory.back();
  back = back->next;
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
  Node<double>* new_node = new Node<double>(result);
  new_node->next = back->next;
  memory.push_back(new_node);
  cout << result << endl;
  numbers.push(result);
}

// drop(stack<double>& numbers)
// function that removes the top element in the stack. returns an error if 
// the stack is empty
// precondition: numbers is a stack of doubles
// postcondition: top element is removed from stack, stack remains empty if it is already empty
void drop(My_stack<double>& numbers, vector<Node<double>*>& memory){
  if(numbers.get_size() == 0){		// if the stack is empty
    error("stack underflow");		// return an error
    return;
  }
  Node<double>* back = memory.back();
  Node<double>* new_node = back->next;
  memory.push_back(new_node);
  numbers.pop();			// remove top element
}

// swap(stack<double>& numbers)
// function that swaps the top two elements of a stack that is passed in
// precondition: numbers is a stack of doubles
// postcondition: top two elements are switched, or the stack is empty if
// 		  there were fewer than 2 elements in the stack to begin
void swap(My_stack<double>& numbers, vector<Node<double>*>& memory){
  if(numbers.get_size() < 2){			// checks to see the size of the stack is less than 2
    while(!numbers.empty()){			// loop to empty the array
      numbers.pop();
    }
    memory.push_back(nullptr);
    error("stack underflow");			// return an error
    return;
  }

  Node<double>* back = memory.back();
  Node<double>* new_second = new Node<double>(back->data);
  Node<double>* new_back = new Node<double>(back->next->data);
  new_back->next = new_second;
  new_second->next = back->next->next;
  memory.push_back(new_back);
  double first, second;				
  first = numbers.top();			// get first element
  numbers.pop();				// remove top element
  second = numbers.top();			// get second element
  numbers.pop();				// remove top element
  numbers.push(first);				// push the stored values in the opposite order
  numbers.push(second);	
}

// undo(stack<double>& numbers, stack<stack<double>>& memory)
// function that undoes the previous operation by setting the stack equal
// to the top element of the stack of stacks. It also removes the top element
// from the stack of stacks
// precondition: number is a stack of doubles and memory is a stack of
// stacks of doubles
// postcondition: stack is set to the top element of memory, and the top
// element is removed from memory   
void undo(My_stack<double>& numbers, vector<Node<double>*>& memory){
  if(memory.empty()){
    error("cannot undo");
    return;
  }
  // empty the numbers stack
  while(!numbers.empty()){
    numbers.pop();
  }
  memory.pop_back();			// removes top element of memory
  if(memory.empty()){			// if the memory is now empty, leave nubmers and memory empty
    return;
  }
  // temporary stack of double
  My_stack<double> temp;
  // pointer to the back of the memory vector
  Node<double>* cursor = memory.back();
  // while there is something in the memory vector
  while(cursor!=nullptr){
    double new_element = cursor->data;	// get the data from that element
    temp.push(new_element);		// push that element into a temporary stack
    cursor = cursor->next;		// advance the pointer
  }
  while(!temp.empty()){			// loop through the temp stack
    numbers.push(temp.top());		// push its elements onto the numbers stack
    temp.pop();				// remove from the temporary stack
  }
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
  vector<Node<double>*> memory;			// a vector of node pointers that stores the memory
  while (!cin.eof()) {
    if (interactive) cout << "> ";
    
    double result;				// stores the result of the operations
    string s;
    getline(cin, s);
    linenum++;

    double x;	
    if (string_to_number(s, x) == 0) {        	// if the input was a number
      cout << x << endl;			// output x
      numbers.push(x);				// push the result onto the current stack
      Node<double>* new_node = new Node<double>(x); // makes a new node pointer 
      if(memory.empty()){			// if there is nothing in memory yet,
	memory.push_back(new_node);		// add the new node to the array, and leave it pointing to nothing
      } else {
        new_node->next = memory.back();		// make the new node point to the top element of the vector of node pointers
        memory.push_back(new_node);		// push the new node onto the
      }
    } else if (s == "") {
      // if nothing was passed into the program, do nothing
    } else {
      if (s=="*"){				// case for multiplication
        if(valid_size(numbers)){		// if the stack is big enough,
          do_operation(numbers,MULTIPLY,memory);	// multiply top 2 numbers
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
	  memory.push_back(nullptr);
          error("stack underflow");
        }
      } else if (s=="+"){			// case for addition, same steps as above
        if(valid_size(numbers)){
          do_operation(numbers,ADD,memory);
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
	  memory.push_back(nullptr);
          error("stack underflow");
        }
      } else if (s=="/"){			// case for division, same steps as above
        if(valid_size(numbers)){
          do_operation(numbers,DIVIDE,memory);
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
	  memory.push_back(nullptr);
          error("stack underflow");
        }
      } else if (s=="-"){			// case for subtraction, same steps as above
        if(valid_size(numbers)){
          do_operation(numbers,SUBTRACT,memory);
	} else {
          while(!numbers.empty()){
            numbers.pop();
          }
	  memory.push_back(nullptr);
          error("stack underflow");
        }
      } else if (s=="drop"){			// if the input was "drop," then call the drop function
        drop(numbers,memory);
        if(!numbers.empty()){			// if the last element was dropped, you cannot print the top element
  	  cout << numbers.top() << endl;	// prints the top element in the stack
        }
      } else if (s=="swap"){			// if the input was "swap," then call the swap function
        swap(numbers,memory);	
        if(!numbers.empty()){
  	  cout << numbers.top() << endl;	// prints the top element in the stack
        }
      } else if (s=="undo"){			// if the input is "undo", call the undo function
        undo(numbers,memory);
        if(!numbers.empty()){
	  cout << numbers.top() << endl;	// print the top elemetn in the new stack
        }
      }
    }
  }
}
