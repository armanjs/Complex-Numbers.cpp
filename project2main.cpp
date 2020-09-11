#include <iostream>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include "Complex.h"
#include "ComplexDB.h"
// ===========================
// Complex Number Data Base, project 2
// CMPE 126, section 6
// Arman Sadeghi
// September 10, 2020
// ===========================

using namespace std;

// read from file into a complex data base
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

// open the file and return an inFile stream object
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
    ofstream outFile; // create an outFile stream object
    // read from the file into the inFile object
    ifstream inputFile = importComplexFile2("../complex.txt");
    populateDB(inputFile, DB); // reads from file into data base
    DB.menuSelect(); // call function for actions

//    importComplexFile("../complex.txt");

    return 0;
}
