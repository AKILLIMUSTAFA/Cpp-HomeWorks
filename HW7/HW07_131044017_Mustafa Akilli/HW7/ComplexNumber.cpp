// HW07_131044017_Mustafa_Akilli
// 
// File:   ComplexNumber.h
// Author: Mustafa_Akilli
//
// Created on 12 Aralik 2015 Cumartesi, 18:43 by Mustafa_Akilli
//
// Description
//
// Complex Number: Includes real numbers, imaginary numbers, and sums 
// and differences of real and imaginary numbers.
//
// HW7 ComplexNumber Header

#include "ComplexNumber.h"
#include <cstdlib>
#include <cmath>
using std::cout;
using std::endl;


namespace
{
    const static int ZERO = 0;
    const static int ONE = 1;
    const static int NEGATIF_ONE = -1;
}


namespace mustafaAkilli
{
    //Constructor
    ComplexNumber::ComplexNumber(
    const double &newRealNumeratorSub, 
        const int &newRealNumeratorExponentialNumerator,
        const int &newRealNumeratorExponentialDenominator,
    
    const int &newRealDenominatorSub, 
        const int &newRealDenominatorExponentialNumerator, 
        const int &newRealDenominatorExponentialDenominator,
    
    const double &newImaginaryNumeratorSub, 
        const int &newImaginaryNumeratorExponentialNumerator, 
        const int &newImaginaryNumeratorExponentialDenominator,
                
    const int &newImaginaryDenominatorSub, 
        const int &newImaginaryDenominatorExponentialNumerator, 
        const int &newImaginaryDenominatorExponentialDenominator)
    {
        checkImaginaryPart(newImaginaryNumeratorSub, newImaginaryDenominatorSub);
        
        setRealNumeratorSub(newRealNumeratorSub);
        setRealNumeratorExponentialNumerator
                            (newRealNumeratorExponentialNumerator);
        setRealNumeratorExponentialDenominator
                            (newRealNumeratorExponentialDenominator);
        
        
        setRealDenominatorSub(newRealDenominatorSub);
        setRealDenominatorExponentialNumerator
                        (newRealDenominatorExponentialNumerator);
        setRealDenominatorExponentialDenominator
                        (newRealDenominatorExponentialDenominator);
        
        setImaginaryNumeratorSub
                        (newImaginaryNumeratorSub);
        setImaginaryNumeratorExponentialNumerator
                        (newImaginaryNumeratorExponentialNumerator);
        setImaginaryNumeratorExponentialDenominator
                       (newImaginaryNumeratorExponentialDenominator);
        
        setImaginaryDenominatorSub(newImaginaryDenominatorSub);
        setImaginaryDenominatorExponentialNumerator
                       (newImaginaryDenominatorExponentialNumerator);
        setImaginaryDenominatorExponentialDenominator
                    (newImaginaryDenominatorExponentialDenominator);
        
        setRealPart();
        setImaginaryPart();
    }
    
    
    ComplexNumber::ComplexNumber(const double &newRealPart, 
                                 const double &newImaginaryPart)
    {
        if(newImaginaryPart>0)
            checkImaginaryPart(newImaginaryPart, newImaginaryPart);
        
        setRealPart(newRealPart);
        setImaginaryPart(newImaginaryPart);
        
        setRealNumeratorSub(newRealPart);
        setRealNumeratorExponentialNumerator(ONE);
        setRealNumeratorExponentialDenominator(ONE);
        
        setRealDenominatorSub(ONE);
        setRealDenominatorExponentialNumerator(ONE);
        setRealDenominatorExponentialDenominator(ONE);
        
        setImaginaryNumeratorSub(newImaginaryPart);
        setImaginaryNumeratorExponentialNumerator(ONE);
        setImaginaryNumeratorExponentialDenominator(ONE);
        
        setImaginaryDenominatorSub(ONE);
        setImaginaryDenominatorExponentialNumerator(ONE);
        setImaginaryDenominatorExponentialDenominator(ONE); 
    }
    
        
    //No parameter Constructor
    ComplexNumber::ComplexNumber()
    {
        setRealNumeratorSub(ONE);
        setRealNumeratorExponentialNumerator(ONE);
        setRealNumeratorExponentialDenominator(ONE);
        
        setRealDenominatorSub(ONE);
        setRealDenominatorExponentialNumerator(ONE);
        setRealDenominatorExponentialDenominator(ONE);
        
        setImaginaryNumeratorSub(NEGATIF_ONE);
        setImaginaryNumeratorExponentialNumerator(ONE);
        setImaginaryNumeratorExponentialDenominator(ONE);
        
        setImaginaryDenominatorSub(ONE);
        setImaginaryDenominatorExponentialNumerator(ONE);
        setImaginaryDenominatorExponentialDenominator(ONE); 
        
        setRealPart();
        setImaginaryPart();
    }
        
    //Copy Constructor
    ComplexNumber::ComplexNumber(const ComplexNumber &otherComplexNumber)
    {
        setRealNumeratorSub(otherComplexNumber.getRealNumeratorSub());
        setRealNumeratorExponentialNumerator
                    (otherComplexNumber.getRealNumeratorExponentialNumerator());
        setRealNumeratorExponentialDenominator
                    (otherComplexNumber.getRealNumeratorExponentialDenominator());
        
        
        setRealDenominatorSub(otherComplexNumber.getRealDenominatorSub());
        setRealDenominatorExponentialNumerator
                    (otherComplexNumber.getRealDenominatorExponentialNumerator());
        setRealDenominatorExponentialDenominator
                    (otherComplexNumber.getRealDenominatorExponentialDenominator());
        
        setImaginaryNumeratorSub
                        (otherComplexNumber.getImaginaryNumeratorSub());
        setImaginaryNumeratorExponentialNumerator
                (otherComplexNumber.getImaginaryNumeratorExponentialNumerator());
        setImaginaryNumeratorExponentialDenominator
                (otherComplexNumber.getImaginaryNumeratorExponentialDenominator());
        
        setImaginaryDenominatorSub(otherComplexNumber.getImaginaryDenominatorSub());
        setImaginaryDenominatorExponentialNumerator
                (otherComplexNumber.getImaginaryDenominatorExponentialNumerator());
        setImaginaryDenominatorExponentialDenominator
                (otherComplexNumber.getImaginaryDenominatorExponentialDenominator());
        
        setRealPart();
        setImaginaryPart();
    }
        
    //Setters*******************************************************************
    void ComplexNumber::setRealPart(const double &newRealPart)
    {
        realPart=newRealPart; 
    }
       
    void ComplexNumber::setImaginaryPart(const double &newImaginaryPart)
    {
        imaginaryPart=newImaginaryPart;   
    }
    
    
    void ComplexNumber::setRealPart()
    {
        realPart=pow(getRealNumeratorSub(),
                static_cast<double>(getRealNumeratorExponentialNumerator())/
                getRealNumeratorExponentialDenominator())/
                pow(getRealDenominatorSub(),
                static_cast<double>(getRealDenominatorExponentialNumerator())/
                getRealDenominatorExponentialDenominator());
    }
    
    void ComplexNumber::setImaginaryPart()
    {
        imaginaryPart=pow(getImaginaryNumeratorSub(),
                static_cast<double>(getImaginaryNumeratorExponentialNumerator())/
                getImaginaryNumeratorExponentialDenominator())/
                pow(getImaginaryDenominatorSub(),
                static_cast<double>(getImaginaryDenominatorExponentialNumerator())/
                getImaginaryDenominatorExponentialDenominator());
    }
        
    void ComplexNumber::setRealNumeratorSub(const double &newRealNumeratorSub)
    {
        realNumeratorSub=newRealNumeratorSub;
    }
    
    
    void ComplexNumber::setRealNumeratorExponentialNumerator
                            (const int &newRealNumeratorExponentialNumerator)
    {
        realNumeratorExponentialNumerator=newRealNumeratorExponentialNumerator;
    }
    
    void ComplexNumber::setRealNumeratorExponentialDenominator
                            (const int &newRealNumeratorExponentialDenominator)
    {
        realNumeratorExponentialDenominator=
                                        newRealNumeratorExponentialDenominator;
    }
        
        
    void ComplexNumber::setRealDenominatorSub(const int &newRealDenominatorSub)
    {
        if(newRealDenominatorSub==0)
        {
            cout << endl << "Real Denominator Sub dont be 0." << endl
                 << "Program is over" << endl;
            exit(1);
        }    
            
        realDenominatorSub=newRealDenominatorSub;
    }
    
    void ComplexNumber::setRealDenominatorExponentialNumerator
                        (const int &newRealDenominatorExponentialNumerator)
    {
        realDenominatorExponentialNumerator=
                                        newRealDenominatorExponentialNumerator;
    }
    
    void ComplexNumber::setRealDenominatorExponentialDenominator
                        (const int &newRealDenominatorExponentialDenominator)
    {
        realDenominatorExponentialDenominator=
                                       newRealDenominatorExponentialDenominator;
    }
        
    void ComplexNumber::setImaginaryNumeratorSub
                        (const double &newImaginaryNumeratorSub)
    {
        imaginaryNumeratorSub=newImaginaryNumeratorSub;
    }
    
    void ComplexNumber::setImaginaryNumeratorExponentialNumerator
                        (const int &newImaginaryNumeratorExponentialNumerator)
    {
        imaginaryNumeratorExponentialNumerator=
                                    newImaginaryNumeratorExponentialNumerator;
    }
    
    void ComplexNumber::setImaginaryNumeratorExponentialDenominator
                       (const int &newImaginaryNumeratorExponentialDenominator)
    {
        imaginaryNumeratorExponentialDenominator=
                                    newImaginaryNumeratorExponentialDenominator;
    }
        
    void ComplexNumber::setImaginaryDenominatorSub(const int &newImaginaryDenominatorSub)
    {
        if(newImaginaryDenominatorSub==0)
        {
            cout << endl << "Imaginary Denominator Sub dont be 0." << endl
                 << "Program is over" << endl;
            exit(1);
        }
        
        imaginaryDenominatorSub=newImaginaryDenominatorSub;
    }
    
    void ComplexNumber::setImaginaryDenominatorExponentialNumerator
                       (const int &newImaginaryDenominatorExponentialNumerator)
    {
        imaginaryDenominatorExponentialNumerator=
                                newImaginaryDenominatorExponentialNumerator;
    }
    
    void ComplexNumber::setImaginaryDenominatorExponentialDenominator
                    (const int &newImaginaryDenominatorExponentialDenominator)
    {
        imaginaryDenominatorExponentialDenominator
                                =newImaginaryDenominatorExponentialDenominator;
    }
    
    //Check Point Imaginary Part
    void ComplexNumber::checkImaginaryPart(const double &newImaginaryNumeratorSub, 
                      const int &newImaginaryDenominatorSub)
    {
        int result=true;
        
        if( (newImaginaryNumeratorSub<0 
                && newImaginaryDenominatorSub<0) ||
            (newImaginaryNumeratorSub>0 
                && newImaginaryDenominatorSub>0))
            result=false;// not Imaginary Number

        
        if(!result)
        {                
            cout <<"Radicand can not be positive for Imaginary Number" << endl
                 << "Program is over." << endl ;   
            exit(1);
        }
    }  
    
    // overload operator +
    const ComplexNumber operator +(const ComplexNumber& first, 
                                                const ComplexNumber& second)
    {
        double newRealPart=first.getRealPart()+second.getRealPart();
        double newImaginaryPart=first.getImaginaryPart()
                                +second.getImaginaryPart();

        return ComplexNumber(newRealPart,newImaginaryPart);
    }
        
    // overload operator -
    const ComplexNumber operator -(const ComplexNumber& first, 
                                                const ComplexNumber& second)
    {
        double newRealPart=first.getRealPart()-second.getRealPart();
        double newImaginaryPart=first.getImaginaryPart()
                                -second.getImaginaryPart();

        return ComplexNumber(newRealPart,newImaginaryPart);
    
    }
  
    // overload operator <
    bool operator <(const ComplexNumber& first, const ComplexNumber& second)
    {
        int result;
        
        if(pow(first.getRealPart(),2)+pow(first.getImaginaryPart(),2)<
           pow(second.getRealPart(),2)+pow(second.getImaginaryPart(),2))
            result=true;
        
        else
            result=false;

        return result;    
    }

    // overload operator <<
    ostream& operator <<(ostream& outputStream,const ComplexNumber &first)
    {   
        if(first.getRealPart()==0 && first.getImaginaryPart()==0)
            outputStream << "0";
        
        else if(first.getRealPart()==0)
        {
            if(first.getImaginaryPart()==-1)
                outputStream << "i";
            
            else
                outputStream << -(first.getImaginaryPart()) << "i";
        }
        
        else if(first.getImaginaryPart()==0)
            outputStream << first.getRealPart();
        
        else
        {
            if(first.getImaginaryPart()==-1.0)
                outputStream << first.getRealPart() << "+i";
            
            else
                outputStream << first.getRealPart() << "+"
                             << -(first.getImaginaryPart()) << "i";
        }
            
        
        return outputStream;
    }
    
    
    
}