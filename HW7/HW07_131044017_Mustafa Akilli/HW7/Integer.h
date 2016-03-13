// HW07_131044017_Mustafa_Akilli
// 
// File:   Integer.h
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Integer: Positive and negative counting numbers, 
// as well as zero:{…, -2, -1, 0, 1, 2,…}.
//
// HW7 Integer Header

#ifndef INTEGER_H
#define	INTEGER_H

#include "RationalNumber.h"

namespace mustafaAkilli
{
    class Integer: public RationalNumber
    {
    public:
        
        Integer(
        const double &newRealNumeratorSub, 
            const int &newRealNumeratorExponentialNumerator,
            const int &newRealNumeratorExponentialDenominator,
                
        const int &newRealDenominatorSub, 
            const int &newRealDenominatorExponentialNumerator, 
            const int &newRealDenominatorExponentialDenominator);
        
        //No parameter Constructor
        Integer();
        
        //Copy Constructor
        Integer(const Integer &otherInteger);
        
         
        //Check Point
        void checkInteger(const double &newRealNumeratorSub, 
                            const int &newRealNumeratorExponentialNumerator,
                            const int &newRealNumeratorExponentialDenominator,
                            const int &newRealDenominatorSub, 
                            const int &newRealDenominatorExponentialNumerator, 
                            const int &newRealDenominatorExponentialDenominator);
        
        
        // overload operator +
        friend const Integer operator +(const Integer& first, 
                                                const Integer& second);
        
        // overload operator -
        friend const Integer operator -(const Integer& first, 
                                                const Integer& second);
  
        // overload operator <
        friend bool operator <(const Integer& first, 
                                                   const Integer& second);

        // overload operator <<
        friend ostream& operator <<(ostream& outputStream, 
                                                    const Integer &first);
       
    private:
    
    
    };
    
    
}


#endif	/* INTEGER_H */

