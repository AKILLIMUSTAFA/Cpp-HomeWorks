// HW07_131044017_Mustafa_Akilli
// 
// File:   main.cpp
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 17:03 by Mustafa_Akilli
//
// Description
//
// Test for Numbers
//
// HW7 main Cpp

#include <iostream>
#include <cstdlib>
#include "ImaginaryNumber.h"
#include "IrrationalNumber.h"
#include "Integer.h"
#include "NaturalNumber.h"

using namespace std;
using namespace mustafaAkilli;


int main(int argc, char** argv) 
{
    //SPACE********************************************************************
    cout << "TEST FOR COMPLEX NUMBER" << endl;
    //SPACE********************************************************************
    
    
    
    
    
    //TEST FOR COMPLEX NUMBER BEGIN*********************************************
    
    //Constructors
    ComplexNumber firstComplexNumber(2,1,1, 1,1,1, -3,1,1, 1,1,1);
    ComplexNumber secondComplexNumber(0,-5);
    ComplexNumber thirdComplexNumber(4,0);
    
    //No parameter Constructor
    ComplexNumber fourthComplexNumber;
    
    //Copy Constructor
    ComplexNumber fifthComplexNumber(firstComplexNumber);
    
    // overload operator +
    ComplexNumber sixthComplexNumber(secondComplexNumber+thirdComplexNumber);
        
    // overload operator -
    ComplexNumber seventhComplexNumber(firstComplexNumber-fourthComplexNumber);
  
    // overload operator < 
    if(firstComplexNumber<secondComplexNumber)
        cout << endl 
             << "first Complex Number is smaller than second Complex Number" 
             << endl;
            
    if(secondComplexNumber<firstComplexNumber)
        cout << endl 
             << "second Complex Number is smaller than first Complex Number" 
             << endl;

    // overload operator <<
    cout << endl << "firstComplexNumber: " 
         << firstComplexNumber << endl
         << "secondComplexNumber: " 
         << secondComplexNumber << endl
         << "thirdComplexNumber: " 
         << thirdComplexNumber << endl
         << "fourthComplexNumber(No parameter constructor): " 
         << fourthComplexNumber << endl
         << "fifthComplexNumber(Copy constructor(firstComplexNumber)): " 
         << fifthComplexNumber << endl
         << "sixthComplexNumber(second+third): " 
         << sixthComplexNumber << endl
         << "seventhComplexNumber(first-fourth): " 
         << seventhComplexNumber << endl;
    
    
    //TEST FOR COMPLEX NUMBER END***********************************************
    
    
    
    
    
    
    
    
    
    //SPACE********************************************************************
    cout << endl << endl << endl << "TEST FOR IMAGINARY NUMBER" << endl;
    //SPACE********************************************************************
    
    
    
    
    
    
    
    
    
    //TEST FOR IMAGINARY NUMBER BEGIN*******************************************
    
    //Constructors
    ImaginaryNumber firstImaginaryNumber(-7,1,1, 1,1,1);
    ImaginaryNumber secondImaginaryNumber(-5);
    ImaginaryNumber thirdImaginaryNumber(-4); 
    
    //No parameter Constructor
    ImaginaryNumber fourthImaginaryNumber;
    
    //Copy Constructor
    ImaginaryNumber fifthImaginaryNumber(firstImaginaryNumber);
    
    // overload operator +
    ImaginaryNumber sixthImaginaryNumber(secondImaginaryNumber
                                                        +thirdImaginaryNumber);
        
    // overload operator -
    ImaginaryNumber seventhImaginaryNumber(firstImaginaryNumber-
                                                        fourthImaginaryNumber);
  
    // overload operator < 
    if(firstImaginaryNumber<secondImaginaryNumber)
        cout << endl 
             << "first Imaginary Number is smaller than second Imaginary Number" 
             << endl;
            
    if(secondImaginaryNumber<firstImaginaryNumber)
        cout << endl 
             << "second Imaginary Number is smaller than first Imaginary Number" 
             << endl;

    // overload operator <<
    cout << endl << "firstImaginaryNumber: " 
         << firstImaginaryNumber << endl
         << "secondImaginaryNumber: " 
         << secondImaginaryNumber << endl
         << "thirdImaginaryNumber: " 
         << thirdImaginaryNumber << endl
         << "fourthImaginaryNumber(No parameter constructor): " 
         << fourthImaginaryNumber << endl
         << "fifthImaginaryNumber(Copy constructor(firstImaginaryNumber)): " 
         << fifthImaginaryNumber << endl
         << "sixthImaginaryNumber(second+third): " 
         << sixthImaginaryNumber << endl
         << "seventhImaginaryNumber(first-fourth): " 
         << seventhImaginaryNumber << endl;
    
    
    //TEST FOR IMAGINARY NUMBER END*********************************************
    
    
    
    
    
    
    
    
    //SPACE********************************************************************
    cout << endl << endl << endl << "TEST FOR REAL NUMBER" << endl;
    //SPACE********************************************************************
    
    
    
    
    
    
    
    //TEST FOR REAL NUMBER BEGIN*******************************************
    
    //Constructors
    RealNumber firstRealNumber(8,1,1, 1,1,1);
    RealNumber secondRealNumber(2);
    RealNumber thirdRealNumber(4); 
    
    //No parameter Constructor
    RealNumber fourthRealNumber;
    
    //Copy Constructor
    RealNumber fifthRealNumber(firstRealNumber);
    
    // overload operator +
    RealNumber sixthRealNumber(secondRealNumber+thirdRealNumber);
        
    // overload operator -
    RealNumber seventhRealNumber(firstRealNumber-fourthRealNumber);
  
    // overload operator < 
    if(firstRealNumber<secondRealNumber)
        cout << endl 
             << "first Real Number is smaller than second Real Number" 
             << endl;
            
    if(secondRealNumber<firstRealNumber)
        cout << endl 
             << "second Real Number is smaller than first Real Number" 
             << endl;

    // overload operator <<
    cout << endl << "firstRealNumber: " 
         << firstRealNumber << endl
         << "secondRealNumber: " 
         << secondRealNumber << endl
         << "thirdRealNumber: " 
         << thirdRealNumber << endl
         << "fourthRealNumber(No parameter constructor): " 
         << fourthRealNumber << endl
         << "fifthRealNumber(Copy constructor(firstRealNumber)): " 
         << fifthRealNumber << endl
         << "sixthRealNumber(second+third): " 
         << sixthRealNumber << endl
         << "seventhRealNumber(first-fourth): " 
         << seventhRealNumber << endl;
    
    
    //TEST FOR REAL NUMBER END*********************************************
    
    
    
    //SPACE********************************************************************
    cout << endl << endl << endl << "TEST FOR IRRATIONAL NUMBER" << endl;
    //SPACE********************************************************************
    
    
    
    
    //TEST FOR IRRATIONAL NUMBER BEGIN******************************************
    
    //Constructors
    IrrationalNumber firstIrrationalNumber(8,1,2);
    IrrationalNumber secondIrrationalNumber(2,1,2);
    IrrationalNumber thirdIrrationalNumber(5,1,2); 
    
    //No parameter Constructor
    IrrationalNumber fourthIrrationalNumber;
    
    //Copy Constructor
    IrrationalNumber fifthIrrationalNumber(firstIrrationalNumber);
    
    // overload operator +
    IrrationalNumber sixthIrrationalNumber(secondIrrationalNumber
                                                        +thirdIrrationalNumber);
        
    // overload operator -
    IrrationalNumber seventhIrrationalNumber(firstIrrationalNumber
                                                        -fourthIrrationalNumber);
  
    // overload operator < 
    if(firstIrrationalNumber<secondIrrationalNumber)
        cout << endl 
             << "first Irrational Number is smaller than second Irrational Number" 
             << endl;
            
    if(secondIrrationalNumber<firstIrrationalNumber)
        cout << endl 
             << "second Irrational Number is smaller than first Irrational Number" 
             << endl;

    // overload operator <<
    cout << endl << "firstIrrationalNumber: " 
         << firstIrrationalNumber<< endl
         << "secondIrrationalNumber: " 
         << secondIrrationalNumber << endl
         << "thirdIrrationalNumber: " 
         << thirdIrrationalNumber << endl
         << "fourthIrrationalNumber(No parameter constructor): " 
         << fourthIrrationalNumber << endl
         << "fifthIrrationalNumber(Copy constructor(firstIrrationalNumber)): " 
         << fifthIrrationalNumber << endl
         << "sixthIrrationalNumber(second+third): " 
         << sixthIrrationalNumber << endl
         << "seventhIrrationalNumber(first-fourth): " 
         << seventhIrrationalNumber << endl;
    
    
    //TEST FOR IRRATIONAL NUMBER END********************************************
    
    
    
    
    
    //SPACE********************************************************************
    cout << endl << endl << endl << "TEST FOR RATIONAL NUMBER" << endl;
    //SPACE********************************************************************
    
    
    
    
    
    
    //TEST FOR RATIONAL NUMBER BEGIN******************************************
    
    //Constructors
    RationalNumber firstRationalNumber(4,1,2,1,1,1);
    RationalNumber secondRationalNumber(5,1,1,1,1,1);
    RationalNumber thirdRationalNumber(-2,1,1,1,1,1); 
    
    //No parameter Constructor
    RationalNumber fourthRationalNumber;
    
    //Copy Constructor
    RationalNumber fifthRationalNumber(firstRationalNumber);
    
    // overload operator +
    RationalNumber sixthRationalNumber(secondRationalNumber
                                                        +thirdRationalNumber);
        
    // overload operator -
    RationalNumber seventhRationalNumber(firstRationalNumber
                                                        -fourthRationalNumber);
  
    // overload operator < 
    if(firstRationalNumber<secondRationalNumber)
        cout << endl 
             << "first Rational Number is smaller than second Rational Number" 
             << endl;
            
    if(secondRationalNumber<firstRationalNumber)
        cout << endl 
             << "second Rational Number is smaller than first Rational Number" 
             << endl;

    // overload operator <<
    cout << endl << "firstRationalNumber: " 
         << firstRationalNumber<< endl
         << "secondRationalNumber: " 
         << secondRationalNumber << endl
         << "thirdRationalNumber: " 
         << thirdRationalNumber << endl
         << "fourthRationalNumber(No parameter constructor): " 
         << fourthRationalNumber << endl
         << "fifthRationalNumber(Copy constructor(firstRationalNumber)): " 
         << fifthRationalNumber << endl
         << "sixthRationalNumber(second+third): " 
         << sixthRationalNumber << endl
         << "seventhRationalNumber(first-fourth): " 
         << seventhRationalNumber << endl;
    
    
    //TEST FOR RATIONAL NUMBER END********************************************
    
    
    
    
    
    //SPACE********************************************************************
    cout << endl << endl << endl << "TEST FOR INTEGER NUMBER" << endl;
    //SPACE********************************************************************
    
    
    
    
    
    
    //TEST FOR INTEGER NUMBER BEGIN******************************************
    
    //Constructors
    Integer firstInteger(64,1,2,1,1,1);
    Integer secondInteger(3,1,1,1,1,1);
    Integer thirdInteger(-6,1,1,1,1,1); 
    
    //No parameter Constructor
    Integer fourthInteger;
    
    //Copy Constructor
    Integer fifthInteger(firstInteger);
    
    // overload operator +
    Integer sixthInteger(secondInteger+thirdInteger);
        
    // overload operator -
    Integer seventhInteger(firstInteger-fourthInteger);
  
    // overload operator < 
    if(firstInteger<secondInteger)
        cout << endl 
             << "first Integer is smaller than second Integer" 
             << endl;
            
    if(secondInteger<firstInteger)
        cout << endl 
             << "second Integer is smaller than first Integer" 
             << endl;

    // overload operator <<
    cout << endl << "firstInteger: " 
         << firstInteger<< endl
         << "secondInteger: " 
         << secondInteger << endl
         << "thirdInteger: " 
         << thirdInteger << endl
         << "fourthInteger(No parameter constructor): " 
         << fourthInteger << endl
         << "fifthInteger(Copy constructor(firstInteger)): " 
         << fifthInteger << endl
         << "sixthInteger(second+third): " 
         << sixthInteger << endl
         << "seventhInteger(first-fourth): " 
         << seventhInteger << endl;
    
    
    //TEST FOR INTEGER NUMBER END********************************************
    
    
    
    //SPACE********************************************************************
    cout << endl << endl << endl << "TEST FOR NATURAL NUMBER" << endl;
    //SPACE********************************************************************
    
    
    
    //TEST FOR INTEGER NUMBER BEGIN******************************************
    
    //Constructors
    NaturalNumber firstNaturalNumber(81,1,2,1,1,1);
    NaturalNumber secondNaturalNumber(3,1,1,1,1,1);
    NaturalNumber thirdNaturalNumber(4,1,1,1,1,1); 
    
    //No parameter Constructor
    NaturalNumber fourthNaturalNumber;
    
    //Copy Constructor
    NaturalNumber fifthNaturalNumber(firstNaturalNumber);
    
    // overload operator +
    NaturalNumber sixthNaturalNumber(secondNaturalNumber+thirdNaturalNumber);
        
    // overload operator -
    NaturalNumber seventhNaturalNumber(firstNaturalNumber-fourthNaturalNumber);
  
    // overload operator < 
    if(firstNaturalNumber<secondNaturalNumber)
        cout << endl 
             << "first Natural Number is smaller than second Natural Number" 
             << endl;
            
    if(secondNaturalNumber<firstNaturalNumber)
        cout << endl 
             << "second Natural Number is smaller than first Natural Number" 
             << endl;

    // overload operator <<
    cout << endl << "firstNaturalNumber: " 
         << firstNaturalNumber<< endl
         << "secondNaturalNumber: " 
         << secondNaturalNumber << endl
         << "thirdNaturalNumber: " 
         << thirdNaturalNumber << endl
         << "fourthNaturalNumber(No parameter constructor): " 
         << fourthNaturalNumber << endl
         << "fifthNaturalNumber(Copy constructor(firstNaturalNumber)): " 
         << fifthNaturalNumber << endl
         << "sixthNaturalNumber(second+third): " 
         << sixthNaturalNumber << endl
         << "seventhNaturalNumber(first-fourth): " 
         << seventhNaturalNumber << endl;
    
    
    //TEST FOR INTEGER NUMBER END********************************************
    
    
    return 0;
}

