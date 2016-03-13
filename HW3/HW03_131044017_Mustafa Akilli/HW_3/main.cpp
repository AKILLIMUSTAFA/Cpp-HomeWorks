// HW03_131044017_Mustafa_Akıllı
// 
// File:   main.cpp
// Author: mustafa
//
// Created on 29 Ekim 2015 Perşembe, 13:22

#include <cstdlib>
#include <iostream>
#include "header.h"

using namespace std;


int main() {
    
    Triangle first, second , third(5,12,13), fourth(5,12,14);
    
    first.input(); // Take triangle sides
    
    call_by_value(first); // Call call_by_value for first
    
    cout << endl <<"**********************" << endl << endl;
    
    call_by_value(third); // Call call_by_value for third
    
    cout << endl <<"**********************" << endl << endl;
    
    second.input(); // Take triangle sides
    
    call_by_reference(second); // Call call_by_reference for second
    
    cout << endl <<"**********************" << endl << endl;
    
    call_by_reference(fourth); // Call call_by_reference for fourth

    return 0;
}

