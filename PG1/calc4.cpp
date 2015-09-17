// Christopher Syers		CSE30331 Data Structures
// Septempber 15, 2015		PG1

// Implentation of a RPN calculator, using the stack class.
// Calculator includes a memory, which is implemented using a
// persistent data structure in the form of a stack of Node 
// pointers

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h> // for isatty
#include <stack>	// for stack of node shared pointers
#include "shared_stack.h" // for new node class
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

// function that returns true if a stack contains 2 or more elements,
// false otherwise 
// precondition: memory is a stack of shared pointers to Node doubles
// postcondition: true is returned is the size of the stack is 2 or greater, 
// false is returned otherwise
bool valid_size(stack<shared_ptr<Node<double>>>& memory){
  if(memory.top()==nullptr || memory.top()->next == nullptr){	// if size of stack is less than 2
    return false;			// return false
  } else {
    return true;			// else, return true
  }
}

// do_operation(stack<double>& numbers, oper_t t)
// function that does operation t on the top two elements of a stack
// precondition: stack contains at least 2 elements
// postcondition: the stack contains a new node that is the result of the operation
// . this node is pushed onto the stack, and points to the value 2 prevous to it
void do_operation(oper_t t,stack<shared_ptr<Node<double>>>& memory){
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
  shared_ptr<Node<double>> new_node = make_shared<Node<double>>(result);	// new node to add, with value of result
  new_node->next = memory.top()->next->next;					// new node points to the first element not used in operation
  memory.push(new_node);							// new_node is pushed onto memory stack
  cout << result << endl;							// the result is printed
}

// function that removes the top element in the stack. returns an error if 
// the stack is empty
// precondition: numbers is a stack of doubles
// postcondition: top element is removed from stack, stack remains empty if it is already empty
void drop(stack<shared_ptr<Node<double>>>& memory){
  if(memory.size()==0 || memory.top() == nullptr){		// if the stack is empty
    error("stack underflow");		// return an error
    return;
  }
  shared_ptr<Node<double>> back = memory.top();			// pointer to the top element in class
  shared_ptr<Node<double>> new_node = back->next;		// new node points to the same thing as the previous one does
  memory.push(new_node);					// add the new node
}

// function that swaps the top two elements of a stack that is passed in
// precondition: numbers is a stack of doubles
// postcondition: top two elements are switched, or the stack is empty if
// 		  there were fewer than 2 elements in the stack to begin
void swap(stack<shared_ptr<Node<double>>>& memory){
  if(memory.top() == nullptr || memory.top()->next == nullptr){			// checks to see the size of the stack is less than 2
    memory.push(nullptr);			// makes the stack effectively empty
    error("stack underflow");			// return an error
    return;
  }
  shared_ptr<Node<double>> back = memory.top();			// get the last element of the stack
  // make two new nodes that are equal in value to the last two in the stack
  shared_ptr<Node<double>> new_second = make_shared<Node<double>>(back->data);		
  shared_ptr<Node<double>> new_back = make_shared<Node<double>>(back->next->data);
  new_back->next = new_second;			// back points to the second one
  new_second->next = back->next->next;		// second one points to the element 2 before the previous last
  memory.push(new_back);			// push the last node
}

// function that undoes the previous operation by setting the stack equal
// to the top element of the stack of stacks. It also removes the top element
// from the stack of stacks
// precondition: memory is a stack of shared pointers to double Nodes
// postcondition: the head of the stack of the prevous stack is now the top element
// in memory
void undo(stack<shared_ptr<Node<double>>>& memory){
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
  stack<shared_ptr<Node<double>>> memory;	// a stack of node pointers that stores the memory
  while (!cin.eof()) {
    if (interactive) cout << "> ";
    
    double result;				// stores the result of the operations
    string s;
    getline(cin, s);
    linenum++;

    double x;	
    if (string_to_number(s, x) == 0) {        	// if the input was a number
      cout << x << endl;			// output x
      shared_ptr<Node<double>> new_node = make_shared<Node<double>>(x);		// make a new node with value x
      if(memory.empty()){			// if the memory is empty,
	memory.push(new_node);			// add the new node to the memory
      } else {
        new_node->next = memory.top();		// make the new node point to the previous top
        memory.push(new_node);			// make the new node the top
      }
    } else if (s == "") {
      // if nothing was passed into the program, do nothing
    } else {
      if (s=="*"){				// case for multiplication
        if(valid_size(memory)){			// if the stack is big enough,
          do_operation(MULTIPLY,memory);	// multiply top 2 numbers
	} else {
	  memory.push(nullptr);			// if there aren't enough elements to do an operation, push a null pointer
          error("stack underflow");		// report an error
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
        if(!memory.empty() && memory.top()!=nullptr){
	  cout << memory.top()->data << endl;	// print the top element in the new stack
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
