//
// Created by Arman Sadeghi on 8/28/20.
//
#include "Complex.h"
#include "ComplexDB.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;


// overload the << operator
ostream &operator << (ostream &output, const Complex &comp) {
    output << "(" << comp.real << ", " << comp.imaginary << ")" << endl;
    return output;
}

//overload the >> operator
istream &operator >> (istream &input, Complex &comp) {
    char nan; // not a number (anything but a number)
    double realPart;
    double imaginaryPart;
    if (input >> realPart >> imaginaryPart >> nan) {
        comp.real = realPart;
        comp.imaginary = imaginaryPart;
    } else {
        input.clear();
        input.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

// overload the + operator
Complex operator + (const Complex &firstNumber, const Complex &secondNumber) {
    return Complex(firstNumber.real + secondNumber.real, firstNumber.imaginary + secondNumber.imaginary);
}

// overload the - operator
Complex operator - (const Complex &firstNumber, const Complex &secondNumber) {
    return Complex(firstNumber.real - secondNumber.real, firstNumber.imaginary - secondNumber.imaginary);
}

// overload the < operator for complex object comparison
bool operator < (const Complex &firstNumber, const Complex &secondNumber) {
    double value1 = sqrt(firstNumber.real * firstNumber.real + firstNumber.imaginary * firstNumber.imaginary);
    double value2 = sqrt(secondNumber.real * secondNumber.real + secondNumber.imaginary * secondNumber.imaginary);
    return value1 < value2;

    /*
    if (value2 < value1) {
        return true; Complex(firstNumber.real, firstNumber.imaginary);
    } else {
        return false; Complex(secondNumber.real, secondNumber.imaginary);
    }*/
}

// define the constructors
Complex::Complex() {
    real = 0;
    imaginary = 0;
}

Complex::Complex(double r, double i) {
    setComplex(r, i);
}

// define the setter
void Complex::setComplex(const double &r, const double &i) {
    real = r;
    imaginary = i;
}

// define getters
double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

/* for debugging
void listDA(const int CAPACITY, Complex *complexArray) {
    for (int target = 0; target < CAPACITY; target++) {
        for (int i = CAPACITY - 1; i > target; i--) {
            if (complexArray[i] < complexArray[i - 1]) {
                swap(complexArray[i], complexArray[i - 1]);
            }
        }
        cout << complexArray[target];
    }
}

void importComplexFile(string fileName) {
    ifstream inFile; // create an in file object
    ofstream outFile; // create an output stream object
    double real = 0, imaginary = 0; // a, bi
    char plusOrMinus, iChar; // character for (+) (-) and (i)
    string oneLine; // read one line into the variable
    double realSum = 0; // sum of all the real numbers
    double imaginarySum = 0; // sum of all the imaginary numbers
    const int CAPACITY = 10; // capacity for the array
    int index = 0; // index for the array

    ComplexDB DB;

    // open the file
    inFile.open(fileName.c_str()); // convert from string to number
    if (inFile.fail()) { // if unable to open
        cout << "Unable to open --" << fileName << "--" << endl;
        exit(1);
    }
    // open the file, if not found create one
    outFile.open("complexObj.txt");
    // create a complex object
    Complex complexNumber(real, imaginary);
    // create a dynamic array
    //Complex *complexArray;
    //complexArray = new Complex[CAPACITY];

    while (getline(inFile, oneLine)) { // as long as it hasn't reached end of file
        // read from the inFile into the "oneLine" string
        if (oneLine.back() == 'i') { // find the 'i'
            oneLine.erase(prev(oneLine.end()));
        }
        // convert from string into double
        stringstream(oneLine) >> real >> imaginary;
        // set the numbers accordingly into the object
        complexNumber.setComplex(real, imaginary);
        // read into the array
        DB.append(complexNumber);
        //complexArray[index] = complexNumber;
        // go to the next index
        index++;
        // write to the file
        outFile << complexNumber;
    }
    // this loop does the sorting
    DB.add();
    DB.list();
    /* this loop calculates the sum
    for (int i = 0; i < CAPACITY - 1; ++i) {
        realSum += complexArray[i].getImaginary();
        imaginarySum += complexArray[i].getReal();
    }

    inFile.close();

} */