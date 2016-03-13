// HW07_131044017_Mustafa_Akilli
// 
// File:   ImaginaryNumber.h
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Imaginary Number: Numbers that equal the product of a real number 
// and the square root of –1. The number 0 is both real and imaginary.
//
// HW7 ImaginaryNumber Header

#include "ImaginaryNumber.h"
#include <cmath>

namespace
{
    const static int ZERO = 0;
    const static int ONE = 1;
    const static int NEGATIF_ONE = -1;
}


namespace mustafaAkilli
{

    ImaginaryNumber::ImaginaryNumber(
    const double &newImaginaryNumeratorSub, 
        const int &newImaginaryNumeratorExponentialNumerator, 
        const int &newImaginaryNumeratorExponentialDenominator,

    const int &newImaginaryDenominatorSub, 
        const int &newImaginaryDenominatorExponentialNumerator, 
        const int &newImaginaryDenominatorExponentialDenominator):
        
        ComplexNumber(ZERO,ONE,ONE,ONE,ONE,ONE,
            newImaginaryNumeratorSub,
            newImaginaryNumeratorExponentialNumerator, 
            newImaginaryNumeratorExponentialDenominator,
            newImaginaryDenominatorSub,
            newImaginaryDenominatorExponentialNumerator,
            newImaginaryDenominatorExponentialDenominator)
    {
        ComplexNumber::checkImaginaryPart(newImaginaryNumeratorSub, 
                                        newImaginaryDenominatorSub);
    }
        
        
    ImaginaryNumber::ImaginaryNumber(const double &newImaginaryPart):
        ComplexNumber(ZERO,newImaginaryPart)
    {
        //EMPTY
    }
        
        
    //No parameter Constructor
    ImaginaryNumber::ImaginaryNumber():
         ComplexNumber(ZERO,ONE,ONE,ONE,ONE,ONE, NEGATIF_ONE,ONE,ONE,ONE,ONE,ONE)
    {
        //EMPTY
    }
        
    //Copy Constructor
    ImaginaryNumber::ImaginaryNumber(const ImaginaryNumber &otherImaginaryNumber):
        ComplexNumber(ZERO,ONE,ONE,ONE,ONE,ONE,
            otherImaginaryNumber.getImaginaryNumeratorSub(),
            otherImaginaryNumber.getImaginaryNumeratorExponentialNumerator(), 
            otherImaginaryNumber.getImaginaryDenominatorExponentialDenominator(),
            otherImaginaryNumber.getImaginaryDenominatorSub(),
            otherImaginaryNumber.getImaginaryDenominatorExponentialNumerator(),
            otherImaginaryNumber.getImaginaryDenominatorExponentialDenominator())
    {
         //EMPTY
    }     
        
    // overload operator +
    const ImaginaryNumber operator +(const ImaginaryNumber& first, 
                                                const ImaginaryNumber& second)
    {
        double newImaginaryPart=first.getImaginaryPart()
                                +second.getImaginaryPart();

        return ImaginaryNumber(newImaginaryPart);   
    }
        
    // overload operator -
    const ImaginaryNumber operator -(const ImaginaryNumber& first, 
                                                const ImaginaryNumber& second)
    {
        double newImaginaryPart=first.getImaginaryPart()
                                -second.getImaginaryPart();

        return ImaginaryNumber(newImaginaryPart);  
    }
  
    // overload operator <
    bool operator <(const ImaginaryNumber& first, 
                                                   const ImaginaryNumber& second)
    {
        int result;
        
        if(pow(first.getImaginaryPart(),2)<pow(second.getImaginaryPart(),2))
            result=true;
        
        else
            result=false;

        return result;
    }

    // overload operator <<
    ostream& operator <<(ostream& outputStream, const ImaginaryNumber &first)
    {
        if(first.getImaginaryPart()==0)
            outputStream << "0";
        
        else if(first.getImaginaryPart()==-1.0)
            outputStream << "i";
            
        else
            outputStream << first.getImaginaryPart() << "i";
    
        return outputStream;   
    }
        
}
