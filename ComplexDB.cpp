//
// Created by Arman Sadeghi on 9/3/20.
//
#include <iostream>
#include "Complex.h"
using namespace std;

void menuSelect(){
    int selection;
    cout << "Enter (1) for add, (2) for delete, (3) for list and (4) for save: ";
    cin >> selection;
}

void add(){

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

