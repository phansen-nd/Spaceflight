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
  
    const double arr[3] = {3, 6, 1};
    const double arr2[3] = {1, 1, 3};
    
    Vector v1 = Vector(3, arr);
    Vector v2 = Vector(3, arr2);
    cout << "v1 size: " << v1.getSize() << endl;
    cout << "v2 size: " << v2.getSize() << endl;
    cout << "dot product: " << v1*v2 << endl;
  
}
