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


#include <cstdlib>
#include <cmath>
#include "Integer.h"
using std::cout;
using std::endl;

namespace
{
    const static int ZERO = 0;
    const static int ONE = 1;
}


namespace mustafaAkilli
{
    Integer::Integer(
    const double &newRealNumeratorSub, 
        const int &newRealNumeratorExponentialNumerator,
        const int &newRealNumeratorExponentialDenominator,
                
    const int &newRealDenominatorSub, 
        const int &newRealDenominatorExponentialNumerator, 
        const int &newRealDenominatorExponentialDenominator):
        
        RationalNumber(newRealNumeratorSub, 
                 newRealNumeratorExponentialNumerator,
                 newRealNumeratorExponentialDenominator,
                 newRealDenominatorSub, 
                 newRealDenominatorExponentialNumerator, 
                 newRealDenominatorExponentialDenominator)
    {
        checkInteger(newRealNumeratorSub, 
                     newRealNumeratorExponentialNumerator,
                     newRealNumeratorExponentialDenominator,
                     newRealDenominatorSub, 
                     newRealDenominatorExponentialNumerator, 
                     newRealDenominatorExponentialDenominator);    
    }
        
    //No parameter Constructor
    Integer::Integer():
        RationalNumber(ONE, ONE, ONE, ONE, ONE, ONE)
    {
        //EMPTY
    }
        
    //Copy Constructor
    Integer::Integer(const Integer &otherInteger):
        RationalNumber(otherInteger.getRealNumeratorSub(),
            otherInteger.getRealNumeratorExponentialNumerator(),
            otherInteger.getRealNumeratorExponentialDenominator(),
            otherInteger.getRealDenominatorSub(),
            otherInteger.getRealDenominatorExponentialNumerator(),
            otherInteger.getRealDenominatorExponentialDenominator())
    {
        //EMPTY
    }
        
         
    //Check Point
    void Integer::checkInteger(const double &newRealNumeratorSub, 
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
        
        if( fmod(newRationalNumber,1)==0)
            result=true;//Integer

        if(!result)
        {
            cout << endl << newRationalNumber
                 <<" is not a Integer" << endl
                 << "Program is over." << endl ;   
            exit(1);
        }
    }
        
        
    // overload operator +
    const Integer operator +(const Integer& first, const Integer& second)
    {
        double newRealPart=first.getRealPart()+second.getRealPart();
        return Integer(newRealPart,ONE,ONE,ONE,ONE,ONE);
    }
        
    // overload operator -
    const Integer operator -(const Integer& first,  const Integer& second)
    {
        double newRealPart=first.getRealPart()-second.getRealPart();
        return Integer(newRealPart,ONE,ONE,ONE,ONE,ONE);
    }
  
    // overload operator <
    bool operator <(const Integer& first, const Integer& second)
    {
        int result;
        
        if(first.getRealPart()< second.getRealPart())
            result=true;
        
        else
            result=false;

        return result;   
    }

    // overload operator <<
    ostream& operator <<(ostream& outputStream, const Integer &first)
    {
        outputStream << first.getRealPart();
        return outputStream;
    }
    
    
}