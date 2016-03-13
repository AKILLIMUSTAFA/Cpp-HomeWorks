// HW07_131044017_Mustafa_Akilli
// 
// File:   RationalNumber.h
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Rational Number: Numbers that can be expressed as a ratio of an integer to a 
// non-zero integer. All integers are rational, but the converse is not true.
//
// HW7 RationalNumber Header

#ifndef RATIONALNUMBER_H
#define	RATIONALNUMBER_H

#include "RealNumber.h"

namespace mustafaAkilli
{
    class RationalNumber: public RealNumber
    {
    public:
        
        RationalNumber(
        const double &newRealNumeratorSub, 
            const int &newRealNumeratorExponentialNumerator,
            const int &newRealNumeratorExponentialDenominator,
                
        const int &newRealDenominatorSub, 
            const int &newRealDenominatorExponentialNumerator, 
            const int &newRealDenominatorExponentialDenominator);
        
        //No parameter Constructor
        RationalNumber();
        
        //Copy Constructor
        RationalNumber(const RationalNumber &otherRationalNumber);
        
         
        //Check Point
        void checkRationalNumber(const double &newRealNumeratorSub, 
                            const int &newRealNumeratorExponentialNumerator,
                            const int &newRealNumeratorExponentialDenominator,
                            const int &newRealDenominatorSub, 
                            const int &newRealDenominatorExponentialNumerator, 
                            const int &newRealDenominatorExponentialDenominator);
        
        
        // overload operator +
        friend const RationalNumber operator +(const RationalNumber& first, 
                                                const RationalNumber& second);
        
        // overload operator -
        friend const RationalNumber operator -(const RationalNumber& first, 
                                                const RationalNumber& second);
  
        // overload operator <
        friend bool operator <(const RationalNumber& first, 
                                                   const RationalNumber& second);

        // overload operator <<
        friend ostream& operator <<(ostream& outputStream, 
                                                    const RationalNumber &first);
       
    private:
    
    
    };
}

#endif	/* RATIONALNUMBER_H */

