//
// Created by Arman Sadeghi on 9/3/20.
//
#include <iosfwd>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "ComplexDB.h"
#include "Complex.h"

using namespace std;

// overload the << operator
ostream &operator<<(ostream &output, const ComplexDB DB) {
    for (int target = 0; target < DB.getCurrentSize(); target++) {
        for (int i = DB.getCurrentSize() - 1; i > target; i--) {
            if (DB.db[i] < DB.db[i - 1]) {
                swap(DB.db[i], DB.db[i - 1]);
            }
        }
        output << target << ": " << DB.db[target];
    }
    return output;
}

// check if list size needs to be increased
void ComplexDB::setMaxSize() {
    // if there's enough size, return
    if (currentSize < maxSize) return;
    // if not store the old size into maxSize
    int oldMaxSize = maxSize;
    // increment the maxSize
    maxSize++;
    // create a new (dynamic) complex array and set the new max siz as capacity
    Complex *newDB = new Complex[maxSize];
    // go thru the old array (db) and copy into the new empty newDB
    for (currentSize = 0; currentSize < oldMaxSize; currentSize++) {
        newDB[currentSize] = db[currentSize];
    }
    delete[] db; // delete the old db ARRAY
    db = newDB;
    newDB = nullptr;
}

// implement the constructors
ComplexDB::ComplexDB() {
    currentSize = 0;
    maxSize = 1;
    db = new Complex[maxSize];
}

// define the menu select function
void ComplexDB::menuSelect() {
    cout << "Shown below is the list imported from the selected file." << endl;
    list();
    int selection;
    cout << "Enter (1) for add, (2) for delete, (3) for list"
            "\n (4) reverse list, and (5) for save, or (-1) to quit: ";
    cin >> selection;
    while (selection != -1) {
        if (selection == 1) {
            add();
        } else if (selection == 2) {
            list();
            del();
        } else if (selection == 3) {
            list();
        } else if (selection == 4) {
            reverseList2();
        } else if (selection == 5) {
            save();
        } else {
            cout << "Invalid input, try again." << endl;
            cout << "Enter (1) for add, (2) for delete, "
                    "(3) for list and (4) for save, or (-1) to quit: ";
            cin.clear();
            cin >> selection;
        }
        cout << "What would u like to do next (1-5): ";
        cin.clear();
        cin >> selection;
    }
}

// adds items to the data base
void ComplexDB::add() {
    double real;
    double imaginary;
    cout << "Enter the real and imaginary part of the number separated by spaces (a+bi -> a b): ";
    cin >> real >> imaginary;
    setMaxSize(); // call function to increase max size if necessary
    // add the numbers to the database
    db[currentSize].setComplex(real, imaginary);
    currentSize++; // go to the next array
    if (imaginary >= 0)
        cout << "(" << real << "+" << imaginary << "i) has been added" << endl;
    else
        cout << "(" << real << "" << imaginary << "i) has been added" << endl;
}

// print out the list in ascending order (bubble sort)
void ComplexDB::list() {
    cout << "In ascending order:" << endl;
    for (int target = 0; target < currentSize; target++) {
        for (int i = currentSize - 1; i > target; i--) {
            if (db[i] < db[i - 1]) {
                swap(db[i], db[i - 1]);
            }
        }
        cout << target << ": " << db[target];
    }
}

// reverse the order of the list
void ComplexDB::reverseList() {
    cout << "In descending order:" << endl;
    for (int target = 0; target < currentSize; target++) {
        for (int i = currentSize - 1; i > target; i--) {
            if (db[i - 1] < db[i]) {
                swap(db[i - 1], db[i]);
            }
        }
        cout << target << ": " << db[target];
    }
}

void ComplexDB::reverseList2() {
    Complex maxNumber = db[0];
    for (int i = 0; i < currentSize - 1; i++) {
        if (db[i] < db[i + 1]) {
            swap(db[i], db[i + 1]);
            if (maxNumber < db[i]) maxNumber = db[i];
        }
    }
    if (maxNumber != db[0]) {
        reverseList2();
    } else {
        for (int target = 0; target < currentSize; target++) {
            cout << target << ": " << db[target];
        }
        cout << "The max number in the array is: " << maxNumber;
    }
}

// define setters
int ComplexDB::getMaxSize() const {
    return maxSize;
}

int ComplexDB::getCurrentSize() const {
    return currentSize;
}

// ask the user for the index to be deleted
void ComplexDB::del() {
    int index = 0;
    cout << "Enter the index to be deleted: ";
    cin >> index;
    Complex tobeDel = db[index];
    // if user enters an invalid index
    if (index < 0 && index > currentSize + 1) {
        cout << "Invalid index" << endl;
        return;
    } // go through the list
    for (int i = index; i < currentSize - 1; ++i) {
        db[i] = db[i + 1];
    }
    currentSize--;
    cout << tobeDel << "Has been deleted." << endl;
}

// adds the complex number to the complex data base
void ComplexDB::append(Complex number) {
    setMaxSize();
    db[currentSize].setComplex(number.getReal(), number.getImaginary());
    currentSize++;
}

// writes the list to target file
void ComplexDB::save() {
    string filename = "output.txt";
    ofstream outFile(filename);
    if (outFile.fail()) { // if unable to open
        cout << "Unable to create --" << filename << "--" << endl;
        exit(1);
    }
    outFile << "In ascending order:" << endl;
    for (int target = 0; target < getCurrentSize(); target++) {
        for (int i = getCurrentSize() - 1; i > target; i--) {
            if (db[i] < db[i - 1]) {
                swap(db[i], db[i - 1]);
            }
        }
        outFile << target << ": " << db[target];
    }
    outFile << endl << "In descending order:" << endl;
    for (int target = 0; target < getCurrentSize(); target++) {
        for (int i = getCurrentSize() - 1; i > target; i--) {
            if (db[i - 1] < db[i]) {
                swap(db[i - 1], db[i]);
            }
        }
        outFile << target << ": " << db[target];
    }

    cout << "Your file has been saved! ";
}