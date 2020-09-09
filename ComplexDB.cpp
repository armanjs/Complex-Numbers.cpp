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

void list(const int CAPACITY, Complex *complexArray);

using namespace std;

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

void ComplexDB::setMaxSize() {
    // if there's enough size, return
    if (currentSize < maxSize) return;
    // if not store the old size into maxSize
    int oldMaxSize = maxSize;
    // add to the maxSize by half of its original (e.g. 10 -> 15)
    maxSize++;
    // create a new complex array and set the new max siz as capacity
    Complex *newDB = new Complex[maxSize];
    // go thru the old array (db) and copy into the new empty newDB
    for (currentSize = 0; currentSize < oldMaxSize; currentSize++) {
        newDB[currentSize] = db[currentSize];
    }
    delete[] db; // delete the old db ARRAY
    db = newDB; //
    newDB = nullptr;
}

ComplexDB::ComplexDB() {
    currentSize = 0;
    maxSize = 1;
    db = new Complex[maxSize];
}


void ComplexDB::menuSelect() {
    cout << "Shown below is the list imported from the selected file." << endl;
    list();
    int selection;
    cout << "Enter (1) for add, (2) for delete, (3) for list and (4) for save, or (-1) to quit: ";
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
            save();
        } else {
            cout << "Invalid input, try again." << endl;
            cout << "Enter (1) for add, (2) for delete, "
                    "(3) for list and (4) for save, or (-1) to quit: ";
            cin.clear();
            cin >> selection;
        }
        cout << "What would u like to do next (1-4): ";
        cin.clear();
        cin >> selection;
    }
}

void ComplexDB::add() {
    double real;
    double imaginary;
    cout << "Enter the real and imaginary part of the number separated by spaces: ";
    cin >> real >> imaginary;
    setMaxSize();
    db[currentSize].setComplex(real, imaginary);
    currentSize++;
    cout << "(" << real << "+" << imaginary << "i) has been added" << endl;
}

void ComplexDB::list() {
    for (int target = 0; target < currentSize; target++) {
        for (int i = currentSize - 1; i > target; i--) {
            if (db[i] < db[i - 1]) {
                swap(db[i], db[i - 1]);
            }
        }
        cout << target << ": " << db[target];
    }
}

int ComplexDB::getMaxSize() const {
    return maxSize;
}

int ComplexDB::getCurrentSize() const {
    return currentSize;
}

void ComplexDB::del() {
    int index = 0;
    cout << "Enter the index to be deleted: ";
    cin >> index;
    Complex tobeDel = db[index];

    if (index < 0 && index > currentSize + 1) {
        cout << "Invalid index" << endl;
        return;
    }
    for (int i = index; i < currentSize - 1; ++i) {
        db[i] = db[i + 1];
    }
    currentSize--;

    cout << tobeDel << "Has been deleted." << endl;

}

void ComplexDB::append(Complex number) {
    setMaxSize();
    db[currentSize].setComplex(number.getReal(), number.getImaginary());
    currentSize++;
}


void ComplexDB::save() {
    string filename = "output.txt";
    ofstream outFile(filename);
    if (outFile.fail()) { // if unable to open
        cout << "Unable to create --" << filename << "--" << endl;
        exit(1);
    }

    for (int target = 0; target < getCurrentSize(); target++) {
        for (int i = getCurrentSize() - 1; i > target; i--) {
            if (db[i] < db[i - 1]) {
                swap(db[i], db[i - 1]);
            }
        }
        outFile << target << ": " << db[target];
    }
    cout << "Your file has been saved!";
}