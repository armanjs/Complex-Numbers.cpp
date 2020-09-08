//
// Created by Arman Sadeghi on 9/3/20.
//
#include <iostream>
#include "ComplexDB.h"
#include "Complex.h"

using namespace std;

ostream &operator << (ostream &output, const ComplexDB comp[]){
    int size = sizeof(comp)/sizeof(comp[0]); // find the size of the array
    for (int i = 0; i < size; i++){
        output << "(" << comp[i].real << ", " << comp[i].imaginary << ")" << endl;
    }
    return output;
}

void ComplexDB::set_max_size(int n) {
    max_size = n;
}

ComplexDB::ComplexDB() {
    real = 0;
    imaginary = 0;
    size = 0;
}

void menuSelect(){
    int selection;
    cout << "Enter (1) for add, (2) for delete, (3) for list and (4) for save: ";
    cin >> selection;
}

void add(ComplexDB c, ComplexDB complexArray[]){


}

void list(Complex complexArray[]){
    int CAPACITY = sizeof(*complexArray);
    for (int target = 0; target < CAPACITY; target++){
        for (int i = CAPACITY - 1; target > i ; i--) {
            if (complexArray[i] < complexArray[i-1]){
                swap(complexArray[i], complexArray[i-1]);
            }
        }
        cout << complexArray[target];
    }
}

