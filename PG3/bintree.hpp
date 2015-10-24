#ifndef BINTREE_HPP
#define BINTREE_HPP

#include <utility>
#include <string>
#include <vector>
#include <algorithm> // for max

// node struct for the bintree class
struct Node{
  double location;		// stores location in lineworld
  std::string name;		// name of location
  Node* left;			// pointer to left child
  Node* right;			// pointer to right child
  // function that fills the result vector with all children that fall within the search range
  // precondition: this is not nullptr
  // postcondition: result is filled with the names of nodes whose location is within s_min and s_max
  void search(double s_min, double s_max, double b_min, double b_max, std::vector<std::string>& result){
    if(std::max(s_min, b_min) <= std::min(s_max, b_max)){		// if brange and srange overlap
      if(this->location >= s_min && this->location <= s_max){		// if location is within the srange
        result.push_back(this->name);					// add the name to the vector
      }
      if (this->left != nullptr) this->left->search(s_min, s_max, b_min, this->location, result);	// recursive search down right, adjusting brange
      if (this->right != nullptr) this->right->search(s_min, s_max, this->location, b_max, result);	// recursive search down left, adjusting brange
    }
  }
  // destructor or the Node struct - removes the children recursively by calling delete
  ~Node(){
    delete right;
    delete left;
  }
};

class bintree {
  // A binary search tree for locations in Lineland.

  // Notes: 
  // - Assume a flat, one-dimensional world with locations from -180 to 180.
  // - All locations and distances are measured in the same units (degrees).
private:
  Node* root;		// stores pointer to the root Node

public:
  // Default constructor
  bintree() {
    root = nullptr;	// set data member to nullptr
  }

  // Copy constructor
  bintree(const bintree &t) {
    // Copy all data members here. It should normally be a deep copy,
    // i.e., the things that pointers point to should be copied as
    // well.
    root = copyTree(t.root);
  }

  // helper function for copy constructor
  // precondition: none
  // postcondition: returns a Node* to a bintree that has the same elements as other
  Node* copyTree(Node* other){
    if(other==nullptr){			// return nullptr if there is no Node to copy
      return nullptr;
    }
    Node* newNode = new Node();		// create a new node
    newNode->location = other->location;	// copy the location and name of other node
    newNode->name = other->name;
    newNode->left = copyTree(other->left);	// make the newNode's left pointer the same as the old node's
    newNode->right = copyTree(other->right);	// recursive with the right subtree as well
    return newNode;			
  }
  // Destructor
  ~bintree() {
    delete root;
  }

  // Copy assignment is implemented using the copy-swap idiom
  // https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Copy-and-swap
  friend void swap(bintree &t1, bintree &t2) {
    using std::swap;
    // Swap all data members here, e.g.,
    // swap(t1.foo, t2.foo);
    // Pointers should be swapped -- but not the things they point to.
    swap(t1.root, t2.root);		// swap the data members
  }
  bintree &operator= (bintree other) {
    // You don't need to modify this function.
    swap(*this, other);
    return *this;
  }

  void insert(const std::string& name, double p) {
    // Insert an element with name `name` and location `p`.
    Node* insert_node = new Node();	// make a new Node
    insert_node->name = name;		// set the new Node's data members to the parameters
    insert_node->location = p;
    insert_node->left = nullptr;	// start the new Node's pointers to null
    insert_node->right = nullptr;
    if(root==nullptr){			// if the root is null, just insert the node as the root
      root = insert_node;
    } else {				// if the root is not null:
      Node *current, *parent;
      current = root;
      parent = root;
      current = (insert_node->location < current->location) ? (current->left) : (current->right);	// move current to the correct side of the root: left if less than, right if greater than or equal to
      while(current!=nullptr){		// continue until current is null
	parent = current;		// move parent to the current node
        current = (insert_node->location < current->location) ? (current->left) : (current->right);	// advance current to the correct side of node
      }
      if(insert_node->location < parent->location){		// insert the node to the left if it is less than, right if greater than or equal
        parent->left = insert_node;
      } else {
        parent->right = insert_node;
      }
    }
  }

  void within_radius(double p, double r, std::vector<std::string> &result) const {
    // Search for elements within the range `p` plus or minus `r`.
    // Clears `result` and puts the elements in `result`.
    // Postcondition: `result` contains all (and only) elements of the
    // tree, in any order, that lie within the range `p` plus or minus
    // `r`.
    result.clear();				// clear the current results
    root->search(p-r,p+r,-180,180,result);	// use Node's search to populate results vector
  }
};

#endif
