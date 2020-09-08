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
    /* int arr[] = {1,2,3,4};
    cout << sizeof(arr) / sizeof(arr[0]); */


    /*for debugging only
    Complex c1(3, 6);
    Complex c2(4, 6);

    cout << endl << c1 + c2;
    cout << c1;
    if (c1 < c2){
        cout << "true";
    } */


    return 0;
}
