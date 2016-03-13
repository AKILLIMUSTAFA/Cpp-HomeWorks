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

#ifndef IMAGINARYNUMBER_H
#define	IMAGINARYNUMBER_H

#include "ComplexNumber.h"

namespace mustafaAkilli
{

    class ImaginaryNumber: public ComplexNumber
    {
    public:
        
        ImaginaryNumber(
        const double &newImaginaryNumeratorSub, 
            const int &newImaginaryNumeratorExponentialNumerator, 
            const int &newImaginaryNumeratorExponentialDenominator,
                
        const int &newImaginaryDenominatorSub, 
            const int &newImaginaryDenominatorExponentialNumerator, 
            const int &newImaginaryDenominatorExponentialDenominator);
        
        
        ImaginaryNumber(const double &newImaginaryPart);
        
        
        //No parameter Constructor
        ImaginaryNumber();
        
        //Copy Constructor
        ImaginaryNumber(const ImaginaryNumber &otherImaginaryNumber);
        
        // overload operator +
        friend const ImaginaryNumber operator +(const ImaginaryNumber& first, 
                                                const ImaginaryNumber& second);
        
        // overload operator -
        friend const ImaginaryNumber operator -(const ImaginaryNumber& first, 
                                                const ImaginaryNumber& second);
  
        // overload operator <
        friend bool operator <(const ImaginaryNumber& first, 
                                                   const ImaginaryNumber& second);

        // overload operator <<
        friend ostream& operator <<(ostream& outputStream, 
                                                    const ImaginaryNumber &first);  
        
    private:
        
        
    
    };
}

#endif	/* IMAGINARYNUMBER_H */

