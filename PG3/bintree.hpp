#ifndef BINTREE_HPP
#define BINTREE_HPP

#include <utility>
#include <string>
#include <vector>

class bintree {
  // A binary search tree for locations in Lineland.

  // Notes: 
  // - Assume a flat, one-dimensional world with locations from -180 to 180.
  // - All locations and distances are measured in the same units (degrees).

public:
  // Default constructor
  bintree() {
  }

  // Copy constructor
  bintree(const bintree &t) {
    // Copy all data members here. It should normally be a deep copy,
    // i.e., the things that pointers point to should be copied as
    // well.
  }

  // Destructor
  ~bintree() {
  }

  // Copy assignment is implemented using the copy-swap idiom
  // https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Copy-and-swap
  friend void swap(bintree &t1, bintree &t2) {
    using std::swap;
    // Swap all data members here, e.g.,
    // swap(t1.foo, t2.foo);
    // Pointers should be swapped -- but not the things they point to.
  }
  bintree &operator= (bintree other) {
    // You don't need to modify this function.
    swap(*this, other);
    return *this;
  }

  void insert(const std::string& name, double p) {
    // Insert an element with name `name` and location `p`.
  }

  void within_radius(double p, double r, std::vector<std::string> &result) const {
    // Search for elements within the range `p` plus or minus `r`.
    // Clears `result` and puts the elements in `result`.
    // Postcondition: `result` contains all (and only) elements of the
    // tree, in any order, that lie within the range `p` plus or minus
    // `r`.
  }
};

#endif
