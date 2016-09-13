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
    
    Vector v1 = Vector(arr, 3);
    Vector v2 = Vector(arr2, 3);
    
    cout << "v1: ";
    v1.print();
    
    cout << "v2: ";
    v2.print();
    
    cout << "dot product: " << v1*v2 << endl;
    
    Vector v3 = v1 + v2;
    cout << "sum: ";
    v3.print();
  
}
