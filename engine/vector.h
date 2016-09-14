/*
 * vector.h
 * Patrick Hansen
 * 09/12/2016
 * vector.h - header for a vector class that supports std vector ops.
 */

#include <iostream>
#include <math.h>

#define PI 3.14159265

class Vector {
    double *params;
    int size;

public:
    
    // Constructors.
    Vector(const double *, int);
    Vector(const Vector &);
    ~Vector();
    
    // Operators.
    Vector & operator = (Vector);
    friend void swap(Vector &v1, Vector &v2);
    friend double operator * (const Vector &, const Vector &);
    friend Vector operator * (double, const Vector &);
    friend Vector operator + (const Vector &, const Vector &);
    friend Vector operator - (const Vector &, const Vector &);
    friend std::ostream & operator << (std::ostream &, const Vector &);
    double operator [] (int) const;
    double & operator [] (int);
    
    // Member functions.
    int getSize() const;
    Vector cross(const Vector &) const;
    Vector rotate(const Vector &, double);
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
    if (i > (size - 1) || i < 0) {
        std::cout << "Error - out of bounds access." << std::endl;
        return -1;
    }
    
    return params[i];
}

// Element access to allow setting, not just getting.
// This is important because it needs to return an assignable
//  location (reference), not just a value.
double & Vector::operator [] (int i) {
    return params[i];
}

int Vector::getSize() const {
    return size;
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

Vector Vector::rotate(const Vector & v1, double angle) {
    
    // Initialize some easy-to-use variables.
    angle = angle * PI / 180;
    double x = this->params[0];
    double y = this->params[1];
    double z = this->params[2];
    double xax = v1[0];
    double yax = v1[1];
    double zax = v1[2];
    double x2 = xax * xax;
    double y2 = yax * yax;
    double z2 = zax * zax;
    double L = (x2 + y2 + z2);
    double mat[4][4];
    
    // Set up rotation matrix.
    mat[0][0] = (x2 + (y2 + z2) * cos(angle)) / L;
    mat[0][1] = (xax * yax * (1 - cos(angle)) - zax* sqrt(L) * sin(angle)) / L;
    mat[0][2] = (xax * zax* (1 - cos(angle)) + yax * sqrt(L) * sin(angle)) / L;
    mat[0][3] = 0.0;
    
    mat[1][0] = (xax * yax * (1 - cos(angle)) + zax* sqrt(L) * sin(angle)) / L;
    mat[1][1] = (y2 + (x2 + z2) * cos(angle)) / L;
    mat[1][2] = (yax * zax* (1 - cos(angle)) - xax * sqrt(L) * sin(angle)) / L;
    mat[1][3] = 0.0;
    
    mat[2][0] = (xax * zax* (1 - cos(angle)) - yax * sqrt(L) * sin(angle)) / L;
    mat[2][1] = (yax * zax* (1 - cos(angle)) + xax * sqrt(L) * sin(angle)) / L;
    mat[2][2] = (z2 + (x2 + y2) * cos(angle)) / L;
    mat[2][3] = 0.0;
    
    mat[3][0] = 0.0;
    mat[3][1] = 0.0;
    mat[3][2] = 0.0;
    mat[3][3] = 1.0;
    
    // Set up input vector.
    double input[4][1];
    double output[4][1];
    
    input[0][0] = x;
    input[1][0] = y;
    input[2][0] = z;
    input[3][0] = 1.0;
    
    // Do the rotation.
    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 1; j++){
            output[i][j] = 0;
            for(int k = 0; k < 4; k++){
                output[i][j] += mat[i][k] * input[k][j];
            }
        }
    }
    
    double arr[3] = {output[0][0], output[1][0], output[2][0]};
    
    Vector rotated = Vector(arr, 3);
    
    return rotated;
}
