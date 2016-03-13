// HW07_131044017_Mustafa_Akilli
// 
// File:   IrrationalNumber.h
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Irrational Number: Real numbers that are not rational.
//
// HW7 IrrationalNumber Header

#ifndef IRRATIONALNUMBER_H
#define	IRRATIONALNUMBER_H

#include "RealNumber.h"

namespace mustafaAkilli
{

    class IrrationalNumber: public RealNumber
    {
    public:
        
        IrrationalNumber(
        const double &newRealNumeratorSub, 
            const int &newRealNumeratorExponentialNumerator,
            const int &newRealNumeratorExponentialDenominator);
        
        //No parameter Constructor
        IrrationalNumber();
        
        //Copy Constructor
        IrrationalNumber(const IrrationalNumber &otherIrrationalNumber);
        
        //DONT USE CONSTRUCTOR
        IrrationalNumber(const double &newIrrationalNumber);
        
         
        //Check Point
        void checkIrrationalNumber(const double &newRealNumeratorSub, 
                             const int &newRealNumeratorExponentialNumerator,
                             const int &newRealNumeratorExponentialDenominator);
        
        
        // overload operator +
        friend const IrrationalNumber operator +(const IrrationalNumber& first, 
                                                const IrrationalNumber& second);
        
        // overload operator -
        friend const IrrationalNumber operator -(const IrrationalNumber& first, 
                                                const IrrationalNumber& second);
  
        // overload operator <
        friend bool operator <(const IrrationalNumber& first, 
                                                   const IrrationalNumber& second);

        // overload operator <<
        friend ostream& operator <<(ostream& outputStream, 
                                                    const IrrationalNumber &first);
       
    private:

    };
}

#endif	/* IRRATIONALNUMBER_H */

