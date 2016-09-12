/*
 * engine.cpp
 * Patrick Hansen
 * 09/12/2016
 * engine.cpp - a vector-based physics engine written in C++.
 */

#include <iostream>
#include "vector.h"

using namespace std;

int main (void) {
  
  cout << "Hello, world!" << endl;
  Vector<double> v = Vector<double>(4);
  cout << v.getSize() << endl;
  
}
