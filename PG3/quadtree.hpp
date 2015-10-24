#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <utility>
#include <string>
#include <vector>
#include "distance.hpp"

// struct to hold the nodes of the quadtree
struct Node{
  std::string name;	// holds the name of the location
  point location;	// holds a point that contains that lat and lon of a location
  // pointers to four children
  Node* southwest;	
  Node* southeast;
  Node* northwest;
  Node* northeast;
  // function that determines all locations that are within r or point center
  // precondition: none
  // postcondition: result contains the names of all loactions of the caller's subtree that are 
  // within r of point center
  void search(point center, double r, point sw, point ne, std::vector<std::string>& result){
    if(distance_to_box(center, sw, ne) <= r){		// if the search range and bounding box intersect
      if(distance(center,location) <= r) {		// if the location is within the search range
        result.push_back(name);				// add the name to the vector
      }
      // recursively search down each branch, restricting the bounding range of the search
      if (southwest != nullptr) southwest->search(center,r,sw,location,result);
      if (southeast != nullptr) southeast->search(center,r,point(sw.lat,location.lon),point(location.lat,ne.lon),result);
      if (northwest != nullptr) northwest->search(center,r,point(location.lat,sw.lon),point(ne.lat,location.lon),result);
      if (northeast != nullptr) northeast->search(center,r,location,ne,result);
    }
  }
  // destructor of a Node struct. Recursively remove the children, which calls their destructors as well
  ~Node(){
    delete southwest;
    delete southeast;
    delete northwest;
    delete northeast;
  }
};

class quadtree {
  // A point quadtree for locations on Earth.

  // Notes: 
  // - Assume a spherical Earth. But assume that if you keep traveling
  //   west, you will hit lon -180 and stop, and if you keep
  //   traveling east, you will hit lon +180 and stop; you don't
  //   have to worry about wrapping around like Magellan.
  // - Locations are measured in degrees lat and lon, but
  //   distances are measured in miles.
private:
  Node* root;
public:
  // See bintree.hpp for skeleton definitions of the default
  // constructor, copy constructor, destructor, and copy assignment
  // operator (and swap).
  
  // constructor
  // initializes the root pointer to null
  quadtree(){
    root = nullptr;
  }

  // copy constructor
  // precondition: none
  // postconidition: root is the root of a tree with the same elements as t, the quadtree to copy
  quadtree(const quadtree &t){
    root = copyTree(t.root);	// calls helper function copyTree
  }

  // helper function for copying a tree
  // precondition: none
  // postcondition: returns a pointer to a copy of a node other
  Node* copyTree(Node* other){
    if(other==nullptr){			// return nullptr if other is nullptr
      return nullptr;
    }
    Node* newNode = new Node();				// create the new node
    // copy the information from the other node into the newNode
    newNode->name = other->name;			
    newNode->location.lat = other->location.lat; 
    newNode->location.lon = other->location.lon;
    // recursively copy the children of the other node
    newNode->southwest = copyTree(other->southwest);
    newNode->southeast = copyTree(other->southeast);
    newNode->northwest = copyTree(other->northwest);
    newNode->northeast = copyTree(other->northeast);
    // return the newNode
    return newNode;
  }

  // destructor. 
  // precondition: none
  // postcondition: root and all of its children as destroyed 
  ~quadtree(){
    delete root;
  }

  // swap helper function
  friend void swap(quadtree &t1, quadtree &t2){
    using std::swap;
    swap(t1.root, t2.root); 	// swap the roots of the two quadtrees
  }
 
  // overloaded = operator. Uses copy swap idiom
  quadtree &operator= (quadtree other){
    swap(*this,other);
    return *this;
  }

  // function to insert new location into quadtree
  // precondition: point p is within (-90,-180) and (90,180)
  // postcondition: a new Node is inserted into the quadtree
  // in the correct location
  void insert(const std::string& name, point p) {
    // Insert an element with name `name` and location `p`.
    Node* insert_node = new Node();		// create the new Node struct
    // initialize the data members of the Node
    insert_node->name = name;
    insert_node->location = p;
    insert_node->southwest = nullptr;
    insert_node->southeast = nullptr;
    insert_node->northwest = nullptr;
    insert_node->northeast = nullptr;
    // if this is the first insertion, make the new node the root
    if(root==nullptr){
      root = insert_node;
    } else {
      Node *current, *parent;		// cursor node pointers
      // start both at the root
      current = root;
      parent = root;
      if(insert_node->location.lon < current->location.lon){		// if the point is west of the current node
        if(insert_node->location.lat < current->location.lat){		// if the point is south of the current node
          current = current->southwest;						// move cursor to the southwest child
        } else {							// if the point is north of the current node
          current = current->northwest;						// move cursor to the northwest chile
        }
      } else {								// if the point is east of the current node
        if(insert_node->location.lat < current->location.lat){		// if the point is south of the current node
          current = current->southeast;						// move cursor to the southeast child
        } else {							// if the point is north of the current node
          current = current->northeast;						// move cursor to the northeast child
        }
      }
      while(current!=nullptr){						// continue until the process reaches a nullptr that could be added to
        parent = current;						// move parent pointer to the current node
	// move current to the correct child - depending on location of insert_node compared to the current node being looked at
        if(insert_node->location.lon < current->location.lon){
          if(insert_node->location.lat < current->location.lat){
            current = current->southwest;
          } else {
            current = current->northwest;
          }
        } else {
          if(insert_node->location.lat < current->location.lat){
            current = current->southeast;
          } else {
            current = current->northeast;
          }
        }
      }
      // insert the node into the correct place based on the relative location of the insert_node and the parent node
      if(insert_node->location.lon < parent->location.lon){
        if(insert_node->location.lat < parent->location.lat){
          parent->southwest = insert_node;				// insert southwest if lon&lat of insert_node is < lon&lat of parent
        } else {
          parent->northwest = insert_node;				// insert northwest if insert lon < parent lon & insert lat >= parent lat
        }
      } else {
        if(insert_node->location.lat < parent->location.lat){
          parent->southeast = insert_node;				// insert southeast if insert lon >= parent lon & insert lat < parent lat
        } else {
	  parent->northeast = insert_node;				// insert northeast if lon&lat of insert_node is >= lon&lat of parent
	}
      }
    }
  }

  void within_radius(point p, double r, std::vector<std::string> &result) const {
    // Search for elements within the circle with center `p` (in
    // degrees lat and lon) and radius `r` (in miles).
    // Clears `result` and puts the elements in `result`.
    // Postcondition: `result` contains all (and only) the elements of
    // the tree, in any order, that lie within the circle defined by
    // `p` and `r`.
    result.clear();						// clears the results vector
    root->search(p,r,point(-90,-180),point(90,180),result);	// starts the recursive search at the root, with bounding range of the whole coordinate system
  }
};

#endif
