#include <iostream>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include "Complex.h"
#include "ComplexDB.h"

// Complex Number, project 1
// CMPE 126
// Arman Sadeghi
// September 2, 2020

using namespace std;

void importComplexFile(string fileName);

void populateDB(ifstream &inputStream, ComplexDB &DB) {
    double real = 0, imaginary = 0; // a, bi
    string oneLine; // read one line into the variable
    int index = 0; // index for the array
    Complex complexNumber(real, imaginary);

    while (getline(inputStream, oneLine)) { // as long as it hasn't reached end of file
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
        // go to the next index
        index++;
    }
}

ifstream importComplexFile2(string fileName) {
    ifstream inFile; // create an in file object

    // open the file
    inFile.open(fileName.c_str()); // convert from string to number
    if (inFile.fail()) { // if unable to open
        cout << "Unable to open --" << fileName << "--" << endl;
        exit(1);
    }
    return inFile;
}

int main() {

//    import - read input file
//    read to DB - add complex numbers to complexDB
//    create output file
//    save - loop over Database and put in output file

    ComplexDB DB; // create a complex data base object
    ofstream outFile;
    ifstream inputFile = importComplexFile2("../complex.txt");
    populateDB(inputFile, DB); // reads from file into data base
    DB.menuSelect();

//    importComplexFile("../complex.txt");

    return 0;
}
