//
// Created by Arman Sadeghi on 8/28/20.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iostream>
using namespace std;

class Complex{
    friend ostream& operator << (ostream& output, const Complex& comp);
    friend istream& operator >> (istream& input, Complex& comp);
    friend bool operator < (const Complex& firstNumber, const Complex& secondNumber);
    friend Complex operator + (const Complex& firstNumber, const Complex& secondNumber);
    friend Complex operator - (const Complex& firstNumber, const Complex& secondNumber);
    friend bool operator != (const Complex& firstNumber, const Complex& secondNumber);

public:
    // define the constructors
    Complex();
    Complex(double r, double i);
    // define the setters and getters
    void setComplex(const double& real, const double& imag);
    double getReal() const;
    double getImaginary() const;
    //Complex *complexArray;

private:
    // the complex number has two private properties
    double real;
    double imaginary;
};

#endif //COMPLEX_COMPLEX_H
