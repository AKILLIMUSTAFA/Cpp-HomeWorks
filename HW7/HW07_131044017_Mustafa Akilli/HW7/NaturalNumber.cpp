// HW07_131044017_Mustafa_Akilli
// 
// File:   NaturalNumber.cpp
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Natural Number: The counting numbers {1, 2, 3,…}, are called natural numbers. 
// Some authors include 0, so that the natural numbers are {0, 1, 2, 3, …}.
//
// HW7 NaturalNumber Cpp

#include <cstdlib>
#include <cmath>
#include "NaturalNumber.h"
using std::cout;
using std::endl;


namespace
{
    const static int ZERO = 0;
    const static int ONE = 1;
}


namespace mustafaAkilli
{
    NaturalNumber::NaturalNumber(
    const double &newRealNumeratorSub, 
        const int &newRealNumeratorExponentialNumerator,
        const int &newRealNumeratorExponentialDenominator,
                
    const int &newRealDenominatorSub, 
        const int &newRealDenominatorExponentialNumerator, 
        const int &newRealDenominatorExponentialDenominator):
        
        Integer(newRealNumeratorSub, 
                 newRealNumeratorExponentialNumerator,
                 newRealNumeratorExponentialDenominator,
                 newRealDenominatorSub, 
                 newRealDenominatorExponentialNumerator, 
                 newRealDenominatorExponentialDenominator)
    {
        checkNaturalNumber(newRealNumeratorSub, 
                     newRealNumeratorExponentialNumerator,
                     newRealNumeratorExponentialDenominator,
                     newRealDenominatorSub, 
                     newRealDenominatorExponentialNumerator, 
                     newRealDenominatorExponentialDenominator); 
    }
        
    //No parameter Constructor
    NaturalNumber::NaturalNumber():
        Integer(ONE, ONE, ONE, ONE, ONE, ONE)
    {
        //EMPTY
    }
        
    //Copy Constructor
    NaturalNumber::NaturalNumber(const NaturalNumber &otherNaturalNumber):
        Integer(otherNaturalNumber.getRealNumeratorSub(),
            otherNaturalNumber.getRealNumeratorExponentialNumerator(),
            otherNaturalNumber.getRealNumeratorExponentialDenominator(),
            otherNaturalNumber.getRealDenominatorSub(),
            otherNaturalNumber.getRealDenominatorExponentialNumerator(),
            otherNaturalNumber.getRealDenominatorExponentialDenominator())
    {
        //EMPTY
    }
        
         
    //Check Point
    void NaturalNumber::checkNaturalNumber(const double &newRealNumeratorSub, 
                            const int &newRealNumeratorExponentialNumerator,
                            const int &newRealNumeratorExponentialDenominator,
                            const int &newRealDenominatorSub, 
                            const int &newRealDenominatorExponentialNumerator, 
                            const int &newRealDenominatorExponentialDenominator)
    {
        int result=false;
        
        double newRationalNumber=pow(newRealNumeratorSub,
                static_cast<double>(newRealNumeratorExponentialNumerator)/
                newRealNumeratorExponentialDenominator)/
                pow(newRealDenominatorSub,
                static_cast<double>(newRealDenominatorExponentialNumerator)/
                newRealDenominatorExponentialDenominator);
        
        if( fmod(newRationalNumber,1)==0 && newRationalNumber>0)
            result=true;//Natural Number

        if(!result)
        {
            cout << endl << newRationalNumber
                 <<" is not a Natural Number" << endl
                 << "Program is over." << endl ;   
            exit(1);
        }
    }
        
        
    // overload operator +
    const NaturalNumber operator +(const NaturalNumber& first, 
                                                const NaturalNumber& second)
    {
        double newRealPart=first.getRealPart()+second.getRealPart();
        return NaturalNumber(newRealPart,ONE,ONE,ONE,ONE,ONE);
    }
        
    // overload operator -
    const NaturalNumber operator -(const NaturalNumber& first, 
                                                const NaturalNumber& second)
    {
        double newRealPart=first.getRealPart()-second.getRealPart();
        return NaturalNumber(newRealPart,ONE,ONE,ONE,ONE,ONE);
    }
  
    // overload operator <
    bool operator <(const NaturalNumber& first, const NaturalNumber& second)
    {
        int result;
        
        if(first.getRealPart()< second.getRealPart())
            result=true;
        
        else
            result=false;

        return result;
    }

    // overload operator <<
    ostream& operator <<(ostream& outputStream, const NaturalNumber &first)
    {
        outputStream << first.getRealPart();
        return outputStream;
    }
    
    
}