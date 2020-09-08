//
// Created by Arman Sadeghi on 9/7/20.
//

#ifndef COMPLEX_COMPLEXDB_H
#define COMPLEX_COMPLEXDB_H
#include <iostream>
#include "Complex.h"

using namespace std;

class ComplexDB{
    friend ostream& operator << (ostream& output, const ComplexDB comp[]);

public:
    ComplexDB();
    void add(ComplexDB c[], int index);
    void del(ComplexDB c[], int index);
    void setMaxSize(int n);
    void list(const int CAPACITY, Complex *complexArray);
    ComplexDB getComplexDB();

private:
    int currentSize; // number of elements in array
    int maxSize; // maximum size


};

#endif //COMPLEX_COMPLEXDB_H
