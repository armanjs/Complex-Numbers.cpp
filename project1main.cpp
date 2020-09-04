#include <iostream>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include "Complex.h"

// Complex Number, project 1
// CMPE 126
// Arman Sadeghi
// September 2, 2020

using namespace std;
void importComplexFile(string fileName);

int main() {

    importComplexFile("../complex.txt");

    /*for debugging only
    Complex c1(3, 6);
    Complex c2(4, 6);

    cout << c1 + c2 << endl;
    cout << c1 << endl; */


    return 1;
}
