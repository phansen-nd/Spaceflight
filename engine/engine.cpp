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
    
    // Constructor.
    Vector v1 = Vector(arr, 3);
    Vector v2 = Vector(arr2, 3);
    
    // Print.
    cout << "v1: " << v1 << endl;
    
    cout << "v2: " << v2 << endl;
    
    // Dot product.
    cout << "v1 * v2: " << v1*v2 << endl;
    
    // Vector addition.
    Vector v3 = v1 + v2;
    cout << "v3 = v1 + v2: " << v3 << endl;
    
    // Element access.
    cout << "v3[1]: " << v3[1] << endl;
    
    // Vector subtraction.
    Vector v4 = v3 - v1;
    cout << "v4 = v3 - v1: " << v4 << endl;
    
    
    // Scalar multiplication.
    Vector v5 = 2 * v1;
    cout << "v5 = 2 * v1: " << v5 << endl;
  
    // Copy constructor.
    Vector v6 = Vector(v1);
    cout << "Copying v1 to v6: " << v6 << endl;
    
    // Copy assignment operator.
    Vector v7 = v1; // This is actually going to call copy con.
    v7 = v2; // Here's the copy ass op.
    cout << "Copying v2 to v7: " << v7 << endl;
}
