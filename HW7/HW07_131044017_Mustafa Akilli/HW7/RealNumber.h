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

#ifndef REALNUMBER_H
#define	REALNUMBER_H

#include "ComplexNumber.h"

namespace mustafaAkilli
{

    class RealNumber: public ComplexNumber
    {
    public:
        
        RealNumber(
        const double &newRealNumeratorSub, 
            const int &newRealNumeratorExponentialNumerator,
            const int &newRealNumeratorExponentialDenominator,
                
        const int &newRealDenominatorSub, 
            const int &newRealDenominatorExponentialNumerator, 
            const int &newRealDenominatorExponentialDenominator);
        
        
        RealNumber(const double &newRealNumber);
        
        
        //No parameter Constructor
        RealNumber();
        
        //Copy Constructor
        RealNumber(const RealNumber &otherRealNumber);
        
        
        // overload operator +
        friend const RealNumber operator +(const RealNumber& first, 
                                                const RealNumber& second);
        
        // overload operator -
        friend const RealNumber operator -(const RealNumber& first, 
                                                const RealNumber& second);
  
        // overload operator <
        friend bool operator <(const RealNumber& first, 
                                                   const RealNumber& second);

        // overload operator <<
        friend ostream& operator <<(ostream& outputStream, 
                                                    const RealNumber &first);
        
        
        
    private:
        
        
    
    };
}

#endif	/* REALNUMBER_H */

