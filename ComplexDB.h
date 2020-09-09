//
// Created by Arman Sadeghi on 9/7/20.
//

#ifndef COMPLEX_COMPLEXDB_H
#define COMPLEX_COMPLEXDB_H

#include <iostream>
#include "Complex.h"

using namespace std;

class ComplexDB {
    friend ostream &operator<<(ostream &output, const ComplexDB comp[]);

public:
    ComplexDB();

    void add();

    void del();

    void setMaxSize();

    void list();

    void append(Complex number);

    void menuSelect();

    int getMaxSize() const;

    int getCurrentSize() const;

    ComplexDB getComplexDB();

private:
    int currentSize; // number of elements in array
    int maxSize; // maximum size
    Complex *db = nullptr;

};

#endif //COMPLEX_COMPLEXDB_H
