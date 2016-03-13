// HW07_131044017_Mustafa_Akilli
// 
// File:   NaturalNumber.h
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Natural Number: The counting numbers {1, 2, 3,…}, are called natural numbers. 
// Some authors include 0, so that the natural numbers are {0, 1, 2, 3, …}.
//
// HW7 NaturalNumber Header


#ifndef NATURALNUMBER_H
#define	NATURALNUMBER_H

#include "Integer.h"


namespace mustafaAkilli
{
    class NaturalNumber: public Integer
    {
    public:
        
        NaturalNumber(
        const double &newRealNumeratorSub, 
            const int &newRealNumeratorExponentialNumerator,
            const int &newRealNumeratorExponentialDenominator,
                
        const int &newRealDenominatorSub, 
            const int &newRealDenominatorExponentialNumerator, 
            const int &newRealDenominatorExponentialDenominator);
        
        //No parameter Constructor
        NaturalNumber();
        
        //Copy Constructor
        NaturalNumber(const NaturalNumber &otherNaturalNumber);
        
         
        //Check Point
        void checkNaturalNumber(const double &newRealNumeratorSub, 
                            const int &newRealNumeratorExponentialNumerator,
                            const int &newRealNumeratorExponentialDenominator,
                            const int &newRealDenominatorSub, 
                            const int &newRealDenominatorExponentialNumerator, 
                            const int &newRealDenominatorExponentialDenominator);
        
        
        // overload operator +
        friend const NaturalNumber operator +(const NaturalNumber& first, 
                                                const NaturalNumber& second);
        
        // overload operator -
        friend const NaturalNumber operator -(const NaturalNumber& first, 
                                                const NaturalNumber& second);
  
        // overload operator <
        friend bool operator <(const NaturalNumber& first, 
                                                   const NaturalNumber& second);

        // overload operator <<
        friend ostream& operator <<(ostream& outputStream, 
                                                    const NaturalNumber &first);
       
    private:
    
    
    };
    
    
}

#endif	/* NATURALNUMBER_H */

