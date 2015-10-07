Homework 3 - Part D
===================
Q7. When inserting a single new value into a red-black tree, what is the worst-case number of rotations and the worst-case number of color flips that have to be performed? Use big-O in terms of n, the number of elements in the tree, and briefly justify your answer.

Q8. Have a glance at http://j.mp/blensearch. The core of this function is basically searching through a sequence of floats, trying to find the place where the sequence changes sign (i.e., from positive to negative or negative to positive). The left-hand version uses binary search, but it had a bug, so it was reverted back to the right-hand version, which uses linear search.

(For the curious: this module’s job is to cover the surface of a 3-d object with triangles for the purposes of rendering it, and this function’s job is to start by locating a tiny cube that intersects the object’s surface. The object is defined by an equation of the form f(x,y,z) = 0, so the points where f changes sign lie on the surface.)

To make things easier, look at these two functions, which just operate on a vector of floats. Function `find_sign_change_linear` corresponds to the right-hand version, and the function `find_sign_change_binary` corresponds to the left-hand version.

~~~
int find_sign_change_linear (const vector<float> &v) {
  // Precondition: v.size() >= 2
  // Returns: i such that v[i] and v[i+1] have different signs, or -1 if none
  int it;
  float a, b;
  it = 0;
  b = v[0];
  do {
      it++;
      a = b;
      b = v[it];
      if (a * b < 0.0)
        return it-1;
  } while (it < v.size()-1);
  return -1;
}
~~~

~~~
int find_sign_change_binary (const vector<float> &v) {
  // Precondition: v.size() >= 2
  // Returns: i such that v[i] and v[i+1] have different signs, or -1 if none
  int l, r, mid;
  float a, b, c;
  l = 0;
  r = v.size()-1;
  a = v[l];
  b = v[r];
  if (a * b < 0.0) {
    while (r - l >= 2) {
      mid = (r + l) / 2;
      c = v[mid];
      if (a * c < 0.0) {
        b = c;
        r = mid;
      }
      else {
        a = c;
        l = mid;
      }
    }
    return l;
  }
  return -1;
}
~~~

There are at least two bugs in find_sign_change_binary. Find one of them and explain how to fix it.

One bug in this code is that it does not account for the array of floats being in random order. For example, if the vector contained the elements <-1, 1, 2, 3, 2, 1, -1>, there is cleary a sign change between v[0] and v[1]. However, the binary search starts by looking at the first and last element, which in this case have the same sign. The resuling coperation (a*b would be greater than 0.0, which would result in a return value of -1. This is not consistent with the module's postcondition. In order to fix this, a pre-condition would have to be that the vector is in sorted order. If the order of the original vector must be preserved, there is no fix in the binary search for this. The implementation must be changed to a linear search, or another search that does not require a sorted vector.
