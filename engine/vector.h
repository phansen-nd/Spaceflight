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
    Vector(int, const double *);
    ~Vector();
    
    friend double operator*(const Vector &, const Vector &);
    
    int getSize() const;
    double dot(const Vector *) const;

};

Vector::Vector(int s, const double *arr) {
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
double operator* (const Vector &v1, const Vector &v2) {
    double dot = 0;
    
    // Make sure they're the same size.
    if (v1.size != v2.size) {
        std::cout << "Error, dimension mismatch." << std::endl;
        return -1;
    }
    
    // Calculate the dot product.
    for (int i = 0; i < v1.size; i++) {
        //std::cout << params[i] << std::endl;
        dot += v1.params[i] * v2.params[i];
    }
    
    return dot;
}

int Vector::getSize() const {
  return size;
}
