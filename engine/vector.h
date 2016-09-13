/*
 * vector.h
 * Patrick Hansen
 * 09/12/2016
 * vector.h - header for a vector class that supports std vector ops.
 */

class Vector {
    double *params;
    int size;

public:
    Vector(const double *, int);
    ~Vector();
    
    friend double operator * (const Vector &, const Vector &);
    friend Vector operator + (const Vector &, const Vector &);
    double operator [] (int);
    
    int getSize() const;
    void print() const;
};


// Helper function.
int checkDimensions(const Vector &v1, const Vector &v2) {
    if (v1.getSize() == v2.getSize()) {
        return 1;
    }
    std::cout << "Error, dimension mismatch." << std::endl;
    return 0;
}

// --------------------------------------------------------------------- //
// ------------------------ Implementation ----------------------------- //
// --------------------------------------------------------------------- //

Vector::Vector(const double *arr, int s) {
    size = s;
    
    // Initialize params.
    params = new double[size]();
    for (int i = 0; i < size; i++) {
        params[i] = arr[i];
    }
}

Vector::~Vector() {
    delete[] params;
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

int Vector::getSize() const {
  return size;
}

void Vector::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << params[i] << " ";
    }
    std::cout << std::endl;
}
