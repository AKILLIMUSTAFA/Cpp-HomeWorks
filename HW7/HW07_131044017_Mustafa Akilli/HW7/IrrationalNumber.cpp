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

#include "IrrationalNumber.h"
#include <cstdlib>
#include <cmath>
using std::cout;
using std::endl;


namespace
{
    const static int ZERO = 0;
    const static int ONE = 1;
    const static int TWO = 2;
}


namespace mustafaAkilli
{
    IrrationalNumber::IrrationalNumber(
    const double &newRealNumeratorSub, 
        const int &newRealNumeratorExponentialNumerator,
        const int &newRealNumeratorExponentialDenominator):
        
        RealNumber(newRealNumeratorSub,
            newRealNumeratorExponentialNumerator,
            newRealNumeratorExponentialDenominator,
            ONE, ONE, ONE)
    {
        checkIrrationalNumber(newRealNumeratorSub, 
                              newRealNumeratorExponentialNumerator,
                              newRealNumeratorExponentialDenominator);   
    }
        
    //No parameter Constructor
    IrrationalNumber::IrrationalNumber():
        RealNumber(TWO, ONE, TWO, ONE, ONE, ONE)
    {
        //EMPTY
    }
        
    //Copy Constructor
    IrrationalNumber::IrrationalNumber(const IrrationalNumber &otherIrrationalNumber):
        RealNumber(otherIrrationalNumber.getRealNumeratorSub(),
            otherIrrationalNumber.getRealNumeratorExponentialNumerator(),
            otherIrrationalNumber.getRealNumeratorExponentialDenominator(),
            ONE, ONE, ONE)
    {
        //EMPTY
    }
    
    //DONT USE CONSTRUCTOR
    IrrationalNumber::IrrationalNumber(const double &newIrrationalNumber):
        RealNumber(newIrrationalNumber, ONE, ONE, ONE, ONE, ONE)
    {

    }
    
    
    //Check Point
    void IrrationalNumber::checkIrrationalNumber(const double &newRealNumeratorSub, 
                              const int &newRealNumeratorExponentialNumerator,
                              const int &newRealNumeratorExponentialDenominator)
    {
        int result=true;
        
        double realNumeratorSub=newRealNumeratorSub;
        
        double newIrrationalNumber=pow(newRealNumeratorSub,
                static_cast<double>(newRealNumeratorExponentialNumerator)/
                newRealNumeratorExponentialDenominator);
        
        if( fmod(realNumeratorSub,newIrrationalNumber)==0 ||
            fmod(newIrrationalNumber,realNumeratorSub)==0)
            result=false;//RationalNumber

        if(!result)
        {
            cout << endl << newIrrationalNumber 
                 <<" is not a Irrational Number" << endl
                 << "Program is over." << endl ;   
            exit(1);
        }
    }

    // overload operator +
    const IrrationalNumber operator +(const IrrationalNumber& first, 
                                                const IrrationalNumber& second)
    {
        double newRealPart=first.getRealPart()+second.getRealPart();
        return IrrationalNumber(newRealPart);
    }
        
    // overload operator -
    const IrrationalNumber operator -(const IrrationalNumber& first, 
                                                const IrrationalNumber& second)
    {
        double newRealPart=first.getRealPart()-second.getRealPart();
        return IrrationalNumber(newRealPart);
    }
  
    // overload operator <
    bool operator <(const IrrationalNumber& first, const IrrationalNumber& second)
    {
        int result;
        
        if(first.getRealPart()< second.getRealPart())
            result=true;
        
        else
            result=false;

        return result;    
    }

    // overload operator <<
    ostream& operator <<(ostream& outputStream, const IrrationalNumber &first)
    {
        outputStream << first.getRealPart();
        return outputStream;
    }
    
    
}