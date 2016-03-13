#include "header.h"
#include <iostream>
using namespace std;

void Triangle::input()
{
    double firstSide, secondSide, thirdSide;
    
    cout << "Enter First Side: ";
    cin >> firstSide; // First side of Triangle
    
    cout << "Enter Second Side: ";
    cin >> secondSide; // Second side of Triangle
    
    cout << "Enter Third Side: ";
    cin >> thirdSide; // Third side of Triangle
    
    setTriangle(firstSide,secondSide,thirdSide); // Set Triangle
}
