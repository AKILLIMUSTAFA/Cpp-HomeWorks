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

#include "RationalNumber.h"
#include <cstdlib>
#include <cmath>
using std::cout;
using std::endl;

namespace
{
    const static int ZERO = 0;
    const static int ONE = 1;
}

namespace mustafaAkilli
{
    RationalNumber::RationalNumber(
    const double &newRealNumeratorSub, 
        const int &newRealNumeratorExponentialNumerator,
        const int &newRealNumeratorExponentialDenominator,
                
    const int &newRealDenominatorSub, 
        const int &newRealDenominatorExponentialNumerator, 
        const int &newRealDenominatorExponentialDenominator):
        RealNumber(newRealNumeratorSub,
            newRealNumeratorExponentialNumerator,
            newRealNumeratorExponentialDenominator,
            newRealDenominatorSub, 
            newRealDenominatorExponentialNumerator, 
            newRealDenominatorExponentialDenominator)
    {
        checkRationalNumber(newRealNumeratorSub, 
                            newRealNumeratorExponentialNumerator,
                            newRealNumeratorExponentialDenominator,
                            newRealDenominatorSub, 
                            newRealDenominatorExponentialNumerator, 
                            newRealDenominatorExponentialDenominator);
    }
        
    //No parameter Constructor
    RationalNumber::RationalNumber():
        RealNumber(ONE, ONE, ONE, ONE, ONE, ONE)
    {
        //EMPTY
    }
        
    //Copy Constructor
    RationalNumber::RationalNumber(const RationalNumber &otherRationalNumber):
        RealNumber(otherRationalNumber.getRealNumeratorSub(),
            otherRationalNumber.getRealNumeratorExponentialNumerator(),
            otherRationalNumber.getRealNumeratorExponentialDenominator(),
            otherRationalNumber.getRealDenominatorSub(),
            otherRationalNumber.getRealDenominatorExponentialNumerator(),
            otherRationalNumber.getRealDenominatorExponentialDenominator())
    {
        //EMPTY
    }
        
         
    //Check Point
    void RationalNumber::checkRationalNumber(const double &newRealNumeratorSub, 
                            const int &newRealNumeratorExponentialNumerator,
                            const int &newRealNumeratorExponentialDenominator,
                            const int &newRealDenominatorSub, 
                            const int &newRealDenominatorExponentialNumerator, 
                            const int &newRealDenominatorExponentialDenominator)
    {
        int result=false;
        
        double realNumeratorSub=newRealNumeratorSub;
        
        double newRationalNumber=pow(newRealNumeratorSub,
                static_cast<double>(newRealNumeratorExponentialNumerator)/
                newRealNumeratorExponentialDenominator)/
                pow(newRealDenominatorSub,
                static_cast<double>(newRealDenominatorExponentialNumerator)/
                newRealDenominatorExponentialDenominator);
        
        if( fmod(realNumeratorSub,newRationalNumber)==0 ||
            fmod(newRationalNumber,realNumeratorSub)==0)
            result=true;//RationalNumber

        if(!result)
        {
            cout << endl << newRationalNumber << "..."
                 <<" is not a Rational Number" << endl
                 << "Program is over." << endl ;   
            exit(1);
        }
    }
        
        
    // overload operator +
    const RationalNumber operator +(const RationalNumber& first, 
                                                const RationalNumber& second)
    {
        double newRealPart=first.getRealPart()+second.getRealPart();
        return RationalNumber(newRealPart,ONE,ONE,ONE,ONE,ONE);
    }
        
    // overload operator -
    const RationalNumber operator -(const RationalNumber& first, 
                                                const RationalNumber& second)
    {
        double newRealPart=first.getRealPart()-second.getRealPart();
        return RationalNumber(newRealPart,ONE,ONE,ONE,ONE,ONE);
    }
  
    // overload operator <
    bool operator <(const RationalNumber& first, const RationalNumber& second)
    {
        int result;
        
        if(first.getRealPart()< second.getRealPart())
            result=true;
        
        else
            result=false;

        return result;   
    }

    // overload operator <<
    ostream& operator <<(ostream& outputStream, const RationalNumber &first)
    {
        outputStream << first.getRealPart();
        return outputStream;
    }
    

}
