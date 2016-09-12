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
    Vector(int, double *);
    ~Vector();
    int getSize() const;
    double dot(Vector) const;

};

Vector::Vector(int s, double *arr) {
    size = s;
    
    for (int i = 0; i < s; i++) {
        params[i] = arr[i];
    }
}

Vector::~Vector() {
    delete[] params;
}

int Vector::getSize() const {
  return size;
}


double Vector::dot(Vector v) const {
    
    double product = 0;
    
    // Make sure they're the same size.
    if (size != v.size) {
        std::cout << "Error, dimension mismatch." << std::endl;
        return -1;
    }
    
    // Calculate the dot product.
    for (int i = 0; i < size; i++) {
        std::cout << params[i] << std::endl;
        //product += params[i] * v.params[i];
    }
    
    return product;
}
