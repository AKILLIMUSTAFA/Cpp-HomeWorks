// HW07_131044017_Mustafa_Akilli
// 
// File:   RealNumber.h
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Real Number: Numbers that have decimal representations that have a finite or 
// infinite sequence of digits to the right of the decimal point. 
// All rational numbers are real, but the converse is not true.
//
// HW7 RealNumber Header

#include "RealNumber.h"
#include <cmath>

namespace
{
    const static int ZERO = 0;
    const static int ONE = 1;
}


namespace mustafaAkilli
{
    RealNumber::RealNumber(
    const double &newRealNumeratorSub, 
        const int &newRealNumeratorExponentialNumerator,
        const int &newRealNumeratorExponentialDenominator,
                
    const int &newRealDenominatorSub, 
        const int &newRealDenominatorExponentialNumerator, 
        const int &newRealDenominatorExponentialDenominator):
            
        ComplexNumber(newRealNumeratorSub,
            newRealNumeratorExponentialNumerator,
            newRealNumeratorExponentialDenominator,
            newRealDenominatorSub,
            newRealDenominatorExponentialNumerator,
            newRealDenominatorExponentialDenominator,
            ZERO, ONE, ONE, ONE, ONE,ONE)
    {
        //EMPTY
    }
        
        
    RealNumber::RealNumber(const double &newRealNumber):
        ComplexNumber(newRealNumber,ZERO)
    {
        //EMPTY
    }
        
        
    //No parameter Constructor
    RealNumber::RealNumber():
        ComplexNumber(ONE,ONE,ONE,ONE,ONE,ONE,ZERO,ONE, ONE,ONE,ONE,ONE)
    {
        //EMPTY        
    }
        
    //Copy Constructor
    RealNumber::RealNumber(const RealNumber &otherRealNumber):
        ComplexNumber(otherRealNumber.getRealNumeratorSub(),
            otherRealNumber.getRealNumeratorExponentialNumerator(),
            otherRealNumber.getRealNumeratorExponentialDenominator(),
            otherRealNumber.getRealDenominatorSub(),
            otherRealNumber.getRealDenominatorExponentialNumerator(),
            otherRealNumber.getRealDenominatorExponentialDenominator(),
            ZERO, ONE, ONE, ONE, ONE,ONE)
    {
        //EMPTY
    }
        
    // overload operator +
    const RealNumber operator +(const RealNumber& first, 
                                                const RealNumber& second)
    {
        double newRealPart=first.getRealPart()+second.getRealPart();
        return RealNumber(newRealPart);
    }
        
    // overload operator -
    const RealNumber operator -(const RealNumber& first, 
                                                const RealNumber& second)
    {
        double newRealPart=first.getRealPart()-second.getRealPart();
        return RealNumber(newRealPart);
    }
  
    // overload operator <
    bool operator <(const RealNumber& first, const RealNumber& second)
    {
        int result;
        
        if(first.getRealPart()<second.getRealPart())
            result=true;
        
        else
            result=false;

        return result;
    }

    // overload operator <<
    ostream& operator <<(ostream& outputStream, const RealNumber &first)
    {
        outputStream << first.getRealPart();
        return outputStream;   
    }   
}