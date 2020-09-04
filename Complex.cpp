//
// Created by Arman Sadeghi on 8/28/20.
//
#include "Complex.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;

// overload the << operator
ostream &operator<<(ostream &output, const Complex &comp) {
    output << "(" << comp.real << ", " << comp.imaginary << ")" << endl;
    return output;
}

//overload the >> operator
istream &operator>>(istream &input, Complex &comp) {
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

Complex operator+(const Complex &firstNumber, const Complex &secondNumber) {
    return Complex(firstNumber.real + secondNumber.real, firstNumber.imaginary + secondNumber.imaginary);
}

Complex operator-(const Complex &firstNumber, const Complex &secondNumber) {
    return Complex(firstNumber.real - secondNumber.real, firstNumber.imaginary - secondNumber.imaginary);
}

Complex operator<(const Complex &firstNumber, const Complex &secondNumber) {
    double value1 = sqrt(firstNumber.real * firstNumber.real + firstNumber.imaginary * firstNumber.imaginary);
    double value2 = sqrt(secondNumber.real * secondNumber.real + secondNumber.imaginary * secondNumber.imaginary);
    if (value2 < value1) {
        return Complex(firstNumber.real, firstNumber.imaginary);
    } else {
        return Complex(secondNumber.real, secondNumber.imaginary);
    }
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

void importComplexFile(string fileName) {
    ifstream inFile; // create an in file object
    ofstream outFile; // create an output stream object
    double real, imaginary; // a, bi
    char plusOrMinus, iChar; // character for (+) (-) and (i)
    string oneLine; // read one line into the variable
    double realSum = 0; // sum of all the real numbers
    double imaginarySum = 0; // sum of all the imaginary numbers

    // open the file
    inFile.open(fileName.c_str()); // convert from string to number
    if (inFile.fail()) { // if unable to open
        cout << "Unable to open --" << fileName << "--" << endl;
        exit(1);
    }
    // open the file, if not found create one
    outFile.open("complexObj.txt");

    while (getline(inFile, oneLine)) { // as long as it hasn't reached end of file
        // read into "oneLine"
        // read in from "oneLine" and see if it's a number
        if (oneLine.back() == 'i'){ // find the 'i'
            oneLine.erase(prev(oneLine.end()));
        }
        stringstream(oneLine) >> real >> imaginary;
        Complex complexNumber(real, imaginary);
        Complex complexArray[10];
        for (int i = 0; i < 10; ++i) {
            complexArray[i] = complexNumber;
        }
        cout << complexArray[2];
        outFile << complexNumber;
        realSum = realSum + real; // add up all the real numbers
        imaginarySum = imaginarySum + imaginary; // add up all the imaginary numbers
    }

    Complex sumComplex(realSum, imaginarySum);
    outFile << "Sum: " << sumComplex << endl;

    inFile.close();
    cout << realSum << " " << imaginarySum << endl;
}


