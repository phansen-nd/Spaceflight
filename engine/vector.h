/*
 * vector.h
 * Patrick Hansen
 * 09/12/2016
 * vector.h - header for a vector class that supports std vector ops.
 */

#include <iostream>

class Vector {
    double *params;
    int size;

public:
    Vector(const double *, int);
    Vector(const Vector &);
    ~Vector();
    
    Vector & operator = (Vector);
    friend double operator * (const Vector &, const Vector &);
    friend Vector operator * (double, const Vector &);
    friend Vector operator + (const Vector &, const Vector &);
    friend Vector operator - (const Vector &, const Vector &);
    friend std::ostream & operator << (std::ostream &, const Vector &);
    double operator [] (int) const;
    
    int getSize() const;
    Vector cross(const Vector &) const;
    friend void swap(Vector &v1, Vector &v2);
};


// Helper function.
int checkDimensions(const Vector &v1, const Vector &v2) {
    if (v1.getSize() == v2.getSize()) {
        return 1;
    }
    std::cout << "Error, dimension mismatch." << std::endl;
    return 0;
}

void swap(Vector &v1, Vector &v2) {
    
    using std::swap;
    
    swap(v1.size, v2.size);
    swap(v1.params, v2.params);
}

// --------------------------------------------------------------------- //
// ------------------------ Implementation ----------------------------- //
// --------------------------------------------------------------------- //

// Constructor.
Vector::Vector(const double *arr, int s) {
    size = s;
    
    // Initialize params.
    params = new double[size]();
    for (int i = 0; i < size; i++) {
        params[i] = arr[i];
    }
}

// Copy constructor.
Vector::Vector(const Vector & v) {
    size = v.size;
    
    params = new double[size]();
    for (int i = 0; i < size; i++) {
        params[i] = v.params[i];
    }
}

// Destructor.
Vector::~Vector() {
    delete[] params;
}

// Copy assignment operator.
Vector & Vector::operator = (Vector v1) {
    swap(*this, v1);
    return *this;
}

// Dot product.
double operator * (const Vector &v1, const Vector &v2) {
    double dot = 0;
    
    // Make sure they're the same size.
    if (!checkDimensions(v1, v2)) {
        return -1;
    }
    
    // Calculate the dot product.
    for (int i = 0; i < v1.size; i++) {
        //std::cout << params[i] << std::endl;
        dot += v1.params[i] * v2.params[i];
    }
    
    return dot;
}

// Scalar multiplication.
Vector operator * (double d, const Vector &v1) {
    
    Vector v = Vector(v1.params, v1.size);
    
    for (int i = 0; i < v.size; i++) {
        v.params[i] *= d;
    }
    
    return v;
}

// Vector addition.
Vector operator + (const Vector &v1, const Vector &v2) {
    
    Vector v = Vector(v1.params, v1.size);
    
    // Make sure they're the same size.
    if (!checkDimensions(v1, v2)) {
        std::cout << "Error adding vectors, returning first argument." << std::endl;
        return v;
    }
    
    // Add them up.
    for (int i = 0; i < v1.size; i++) {
        v.params[i] += v2.params[i];
    }
    
    return v;
}

// Vector subtraction.
Vector operator - (const Vector &v1, const Vector &v2) {
    
    Vector v = Vector(v1.params, v1.size);
    
    // Make sure they're the same size.
    if (!checkDimensions(v1, v2)) {
        std::cout << "Error adding vectors, returning first argument." << std::endl;
        return v;
    }
    
    // Subtract elementwise.
    for (int i = 0; i < v1.size; i++) {
        v.params[i] -= v2.params[i];
    }
    
    return v;
}

// Printing.
std::ostream & operator << (std::ostream &os, const Vector &v) {
    for (int i = 0; i < v.size; i++) {
        os << v.params[i] << " ";
    }
    return os;
}

// Element access.
double Vector::operator [] (int i) const {
    
    // Make sure it's in bounds.
    if (i > (size - 1)) {
        std::cout << "Error - out of bounds access." << std::endl;
        return -1;
    }
    
    return params[i];
}

// Cross product.
Vector Vector::cross(const Vector & v1) const {

    Vector v = *this;
    
    if (size != 3 || v1.size != 3) {
        std::cout << "Error - vectors must both be three dimensional to computer cross product." << std:: endl;
        return v;
    }
    
    double a = params[1] * v1[2] - params[2] * v1[1];
    double b = params[2] * v1[0] - params[0] * v1[2];
    double c = params[0] * v1[1] - params[1] * v1[0];
    
    double arr[3] = {a, b, c};
    
    Vector product = Vector(arr, 3);
    
    return product;
    
}

int Vector::getSize() const {
  return size;
}
