/*
 * vector.h
 * Patrick Hansen
 * 09/12/2016
 * vector.h - header for a vector class that supports std vector ops.
 */

template <typename T>
class Vector {
  T* arr;
  int size;

 public:
  Vector(int = 3);
  int getSize() const;

};

template <typename T>
Vector<T>::Vector(int s) {
  size = s;
}

template <typename T> 
int Vector<T>::getSize() const {
  return size;
}
