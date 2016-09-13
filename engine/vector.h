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
    Vector(const Vector &v);
    ~Vector();
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

int Vector::getSize() const {
  return size;
}


double Vector::dot(const Vector *v) const {
    
    double product = 0;
    
    // Make sure they're the same size.
    if (size != v->size) {
        std::cout << "Error, dimension mismatch." << std::endl;
        return -1;
    }
    
    // Calculate the dot product.
    for (int i = 0; i < size; i++) {
        //std::cout << params[i] << std::endl;
        product += params[i] * v->params[i];
    }
    
    return product;
}
