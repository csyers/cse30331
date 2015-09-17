// Christopher Syers		CSE30331 Data Structures
// September 15, 2015		PG1
//
// Interface and implementation of the My_stack class, 
// which implements a stack with a linked list. Defines
// a deafult constructor, non-default constructor, top()
// , push(T), pop(), and empty() member functions. Contains
// a pointer to a Node object, which is the head of a linked
// list containing all of the elements in the stack

#ifndef MY_STACK_H
#define MY_STACK_H

#include <assert.h>

using namespace std;

// templated Node struct. Contains a data member named data,
// and a pointer to the next Node called next 
template<typename T>
struct Node{
  // constructor: initializes next pointer to null and the data member to value passed in
  Node(const T&new_data) : data(new_data), next(nullptr) {}
  // data that the node contains
  T data;
  // pointer to the next node in the list
  Node<T>* next;
};

// My_stack templated class. Contains standard stack functions, along with size() and an
// overloaded = operator and copy constructor 
template<typename T>
class My_stack{
  public:
    // constructor
    My_stack();
    // copy constructor
    My_stack(const My_stack<T> &);
    // overloaded = operator
    const My_stack& operator=(const My_stack<T>&);
    // standard stack functions
    T top();
    void push(T);
    void pop();
    bool empty();
    // helper function that returns the size
    size_t get_size();
  private:
    // variable that hold the number of elements in stack
    size_t size;
    // head pointer to list of Nodes
    Node<T>* head;
};

// function: get_size()
// returns the size member variable of the class: the number of elements in the stack
// precondition: nothing
// postcondition: nothing in the My_stack changes
template<typename T>
size_t My_stack<T>::get_size(){
  return size;	// returns the member variable
}

// copy constructor
// creates a new My_stack with the same elements as the My_stack in parentheses 
// in the statement My_stack<T> new_stack(old_stack), where old_stack is already
// a My_stack object
// precondition: nothing
// postcondition: new_stack will be a My_stack object with the same values as 
// 		  old_stack
template<typename T>
My_stack<T>::My_stack(const My_stack<T> &stackToCopy){
  size = stackToCopy.size;				// set the size of the new My_stack to be the size of the old one
  head = nullptr;					// sets head of new My_stack to be null
  Node<T> *prev_head = stackToCopy.head;		// gets value of old_stack's head
  Node<T> *last_one = nullptr;				// pointer to the last node in the new list
  while(prev_head!=nullptr){				// loop through all elements of the old list
    Node<T> *new_node = new Node<T>(prev_head->data);	// create a new node with the same data, and call it new_node

    if(last_one!=nullptr){				// if this is not the first node
      last_one->next = new_node;			// go to the last item in the list, and make it point to the new node
    } else {
      head = new_node;					// if it is the first node, make it the head
    }
    last_one = new_node;				// last_one is now the most recent one added
    prev_head = prev_head->next;			// advance the previous head pointer one spot
  }
}

// overloading = operator
// allows for statements such as My_stack<T> new_stack = old_stack
// precondition: right is not the same as the left
// postcondition: new_stack has the same elemnets as old_stack
template<typename T>
const My_stack<T>& My_stack<T>::operator=(const My_stack<T>& right){
  if(&right != this){				// only if the left is not equal to the right  
// SAME CODE AS COPY CONSTRUCTOR - SEE ABOVE
    size = right.size;				
    head = nullptr;			
    Node<T> *prev_head = right.head; 
    Node<T> *last_one = nullptr;
    while(prev_head!=nullptr){
      Node<T> *new_node = new Node<T>(prev_head->data);
  
      if(last_one!=nullptr){
        last_one->next = new_node;
      } else {
        head = new_node;
      }
      last_one = new_node;
      prev_head = prev_head->next;
    }
  }
  return (*this);				// return a pointer to the left side of =
}

// deafult constructor
// sets size to 0 and makes the head pointer point to null
// precondition: N/A
// postcondition: My_stack has no elements, and its head pointer is null
template<typename T>
My_stack<T>::My_stack(){
  size = 0;			// set size to 0
  head = nullptr;		// set head pointer to null
}

// top()
// function that returns the top element in the stack
// precondition: there is 1 or more elements on the stack
// post_condition: the top element's data is returned, nothing is changed
template<typename T>
T My_stack<T>::top(){
  assert(head);			// makes sure there is something in the stack first
  return head->data;		// returns the data of the head pointer
}

// push(T value)
// function that pushes a new value onto the top of the stack
// precondition: N/A
// postcondition: the object now contains 1 more element, which
// 		  located at the head of the My_stack object
template<typename T>
void My_stack<T>::push(T value){
  if(!head){					// if there are no elements in the stack
    head = new Node<T>(value);			// make a new node and make head point to it
  } else {	
    Node<T>* temp = new Node<T>(value);		// make a new node
    temp->next = head;				// make the new node point to the previous head
    head = temp;				// make the new node the previous head
  }
  size++;					// increment size member variable
}

// pop()
// function that removes the top element from the My_stack object
// precondition: there is at least 1 element in the stack
// postcondition: the stack now contains one fewer item, and the head is
// 		  adjusted to the new head
template<typename T>
void My_stack<T>::pop(){
  assert(head);				// makes sure there is something in the stack
  Node<T>* oldhead = head;		// gets the head pointer
  head = head->next;			// head is now the second element
  delete oldhead;			// delete the original head
  size--;				// decrement size
}

// empty()
// function that returns true is the stack is empty, and false if it contains
// elements
// precondition: N/A
// postcondition: stack does not change, and the correct return values are given
template<typename T>
bool My_stack<T>::empty(){
  if(size==0){
    return true;
  } else {
    return false;
  }
}
#endif
