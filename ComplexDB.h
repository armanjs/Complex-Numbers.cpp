//
// Created by Arman Sadeghi on 9/7/20.
//

#ifndef COMPLEX_COMPLEXDB_H
#define COMPLEX_COMPLEXDB_H
#include <iostream>
using namespace std;

class ComplexDB{
    friend ostream& operator << (ostream& output, const ComplexDB comp[]);

public:
    ComplexDB();
    void add(ComplexDB c[], int index);
    void set_max_size(int n);
    void setComplex(const double& real, const double& imag);
    int size;
    int max_size;
    ComplexDB *list;

private:
    double real;
    double imaginary;
};

#endif //COMPLEX_COMPLEXDB_H
