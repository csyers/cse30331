// Christopher Syers		CSE30331 Data Structures
// Septempber 15, 2015		PG1

// Implentation of a RPN calculator, using the shared_stack class.
// Calculator includes a memory, which is implemented using a
// persistent data structure in the form of a shared_stack of Node 
// pointers

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h> // for isatty
#include "shared_stack.h"

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
bool valid_size(shared_stack<shared_ptr<Node<double>>>& memory){
  if(memory.top()==nullptr || memory.top()->next == nullptr){	// if size of stack is less than 2
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
void do_operation(oper_t t,shared_stack<shared_ptr<Node<double>>>& memory){
  double x = memory.top()->data;	// get first element
  double y = memory.top()->next->data;	// get second element
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
  shared_ptr<Node<double>> new_node = make_shared<Node<double>>(result);
  new_node->next = memory.top();
  memory.push(new_node);
  cout << result << endl;
}

// drop(stack<double>& numbers)
// function that removes the top element in the stack. returns an error if 
// the stack is empty
// precondition: numbers is a stack of doubles
// postcondition: top element is removed from stack, stack remains empty if it is already empty
void drop(shared_stack<shared_ptr<Node<double>>>& memory){
  if(memory.top() == nullptr){		// if the stack is empty
    error("stack underflow");		// return an error
    return;
  }
  shared_ptr<Node<double>> back = memory.top();
  shared_ptr<Node<double>> new_node = back->next;
  memory.push(new_node);
}

// swap(stack<double>& numbers)
// function that swaps the top two elements of a stack that is passed in
// precondition: numbers is a stack of doubles
// postcondition: top two elements are switched, or the stack is empty if
// 		  there were fewer than 2 elements in the stack to begin
void swap(shared_stack<shared_ptr<Node<double>>>& memory){
  if(memory.top() == nullptr || memory.top()->next == nullptr){			// checks to see the size of the stack is less than 2
    memory.push(nullptr);
    error("stack underflow");			// return an error
    return;
  }

  shared_ptr<Node<double>> back = memory.top();
  shared_ptr<Node<double>> new_second = make_shared<Node<double>>(back->data);
  shared_ptr<Node<double>> new_back = make_shared<Node<double>>(back->next->data);
  new_back->next = new_second;
  new_second->next = back->next->next;
  memory.push(new_back);
}

// undo(stack<double>& numbers, stack<stack<double>>& memory)
// function that undoes the previous operation by setting the stack equal
// to the top element of the stack of stacks. It also removes the top element
// from the stack of stacks
// precondition: number is a stack of doubles and memory is a stack of
// stacks of doubles
// postcondition: stack is set to the top element of memory, and the top
// element is removed from memory   
void undo(shared_stack<shared_ptr<Node<double>>>& memory){
  if(memory.empty()){
    error("cannot undo");
    return;
  }
  memory.pop();		// removes top element of memory
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
  shared_stack<shared_ptr<Node<double>>> memory;	// a shared_stack of node pointers that stores the memory
  while (!cin.eof()) {
    if (interactive) cout << "> ";
    
    double result;				// stores the result of the operations
    string s;
    getline(cin, s);
    linenum++;

    double x;	
    if (string_to_number(s, x) == 0) {        	// if the input was a number
      cout << x << endl;			// output x
      shared_ptr<Node<double>> new_node = make_shared<Node<double>>(x);
      if(memory.empty()){
	memory.push(new_node);
      } else {
        new_node->next = memory.top();
        memory.push(new_node);
      }
    } else if (s == "") {
      // if nothing was passed into the program, do nothing
    } else {
      if (s=="*"){				// case for multiplication
        if(valid_size(memory)){		// if the stack is big enough,
          do_operation(MULTIPLY,memory);	// multiply top 2 numbers
	} else {
	  memory.push(nullptr);
          error("stack underflow");
        }
      } else if (s=="+"){			// case for addition, same steps as above
        if(valid_size(memory)){
          do_operation(ADD,memory);
	} else {
	  memory.push(nullptr);
          error("stack underflow");
        }
      } else if (s=="/"){			// case for division, same steps as above
        if(valid_size(memory)){
          do_operation(DIVIDE,memory);
	} else {
	  memory.push(nullptr);
          error("stack underflow");
        }
      } else if (s=="-"){			// case for subtraction, same steps as above
        if(valid_size(memory)){
          do_operation(SUBTRACT,memory);
	} else {
	  memory.push(nullptr);
          error("stack underflow");
        }
      } else if (s=="drop"){			// if the input was "drop," then call the drop function
        drop(memory);
        if(memory.top()!=nullptr){
	  cout << memory.top()->data << endl;	// print the top elemetn in the new stack
        }
      } else if (s=="swap"){			// if the input was "swap," then call the swap function
        swap(memory);	
        if(memory.top()!=nullptr){
	  cout << memory.top()->data << endl;	// print the top elemetn in the new stack
        }
      } else if (s=="undo"){			// if the input is "undo", call the undo function
        undo(memory);
        if(!memory.empty() && memory.top()!=nullptr){
	  cout << memory.top()->data << endl;	// print the top elemetn in the new stack
        }
      }
    }
  }
}
