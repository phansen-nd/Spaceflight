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
  
    double arr[3] = {3, 6, 1};
    cout << arr[2] << endl;
    
    Vector v1 = Vector(4, arr);
    Vector v2 = Vector(4, arr);
    cout << v1.getSize() << endl;
    cout << v1.dot(v2) << endl;
  
}
