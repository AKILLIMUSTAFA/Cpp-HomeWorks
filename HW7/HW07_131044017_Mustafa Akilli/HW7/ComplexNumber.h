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

#ifndef COMPLEXNUMBER_H
#define	COMPLEXNUMBER_H

#include <iostream>

using std::ostream;

namespace mustafaAkilli
{

    class ComplexNumber
    {
    public:
        
        //Constructor
        ComplexNumber(
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
            const int &newImaginaryDenominatorExponentialDenominator);
        
        
        ComplexNumber(const double &newRealPart, const double &newImaginaryPart);
        
        
        //No parameter Constructor
        ComplexNumber();
        
        //Copy Constructor
        ComplexNumber(const ComplexNumber &otherComplexNumber);
        
        
        
        //Setters*************************************************************
        void setRealPart(const double &newRealPart);
        void setImaginaryPart(const double &newImaginaryPart);
        
        void setRealPart();
        void setImaginaryPart();
        
        void setRealNumeratorSub(const double &newRealNumeratorSub);
        void setRealNumeratorExponentialNumerator
                            (const int &newRealNumeratorExponentialNumerator);
        void setRealNumeratorExponentialDenominator
                            (const int &newRealNumeratorExponentialDenominator);
        
        
        void setRealDenominatorSub(const int &newRealDenominatorSub);
        void setRealDenominatorExponentialNumerator
                        (const int &newRealDenominatorExponentialNumerator);
        void setRealDenominatorExponentialDenominator
                        (const int &newRealDenominatorExponentialDenominator);
        
        void setImaginaryNumeratorSub
                        (const double &newImaginaryNumeratorSub);
        void setImaginaryNumeratorExponentialNumerator
                        (const int &newImaginaryNumeratorExponentialNumerator);
        void setImaginaryNumeratorExponentialDenominator
                       (const int &newImaginaryNumeratorExponentialDenominator);
        
        void setImaginaryDenominatorSub(const int &newImaginaryDenominatorSub);
        void setImaginaryDenominatorExponentialNumerator
                       (const int &newImaginaryDenominatorExponentialNumerator);
        void setImaginaryDenominatorExponentialDenominator
                    (const int &newImaginaryDenominatorExponentialDenominator);
        
        
        //Getters************************************************************
        
        //Real Part
        double getRealPart() const{return realPart;}
        //Imaginary Part
        double getImaginaryPart() const{return imaginaryPart;}
    
    //Real Part
      //Numerator Part
          //Sub Part    
        double getRealNumeratorSub() const{return realNumeratorSub;}
        
          //Exponential Part
        int getRealNumeratorExponentialNumerator() const
        {return realNumeratorExponentialNumerator;}
        int getRealNumeratorExponentialDenominator() const
        {return realNumeratorExponentialDenominator;}
        
      //Denominator Part
          //Sub Part
        int getRealDenominatorSub() const{return realDenominatorSub;}
        
          //Exponential Part
        int getRealDenominatorExponentialNumerator() const
        {return realDenominatorExponentialNumerator;}
        int getRealDenominatorExponentialDenominator() const
        {return realDenominatorExponentialDenominator;}
    
    //Imaginary Part
      //Numerator Part
          //Sub Part
        double getImaginaryNumeratorSub() const
        {return imaginaryNumeratorSub;}
        
          //Exponential Part
        int getImaginaryNumeratorExponentialNumerator() const
        {return imaginaryNumeratorExponentialNumerator;}
        int getImaginaryNumeratorExponentialDenominator() const
        {return imaginaryNumeratorExponentialDenominator;}
        
      //Denominator Part
          //Sub Part  
        int getImaginaryDenominatorSub() const{return imaginaryDenominatorSub;}
        
          //Exponential Part
        int getImaginaryDenominatorExponentialNumerator() const
        {return imaginaryDenominatorExponentialNumerator;}
        int getImaginaryDenominatorExponentialDenominator() const
        {return imaginaryDenominatorExponentialDenominator;}
        
        
        //Check Point Imaginary Part
        void checkImaginaryPart(const double &newImaginaryNumeratorSub, 
                      const int &newImaginaryDenominatorSub);
        
        // overload operator +
        friend const ComplexNumber operator +(const ComplexNumber& first, 
                                                const ComplexNumber& second);
        
        // overload operator -
        friend const ComplexNumber operator -(const ComplexNumber& first, 
                                                const ComplexNumber& second);
  
        // overload operator <
        friend bool operator <(const ComplexNumber& first, 
                                                   const ComplexNumber& second);

        // overload operator <<
        friend ostream& operator <<(ostream& outputStream, 
                                                    const ComplexNumber &first);

    private:
        
        //Real Part
        double realPart;
        //Imaginary Part
        double imaginaryPart;
        
    //Real Part
      //Numerator Part
          //Sub Part
        double realNumeratorSub;
          //Exponential Part
        int realNumeratorExponentialNumerator;
        int realNumeratorExponentialDenominator;
      //Denominator Part
          //Sub Part
        int realDenominatorSub;
          //Exponential Part
        int realDenominatorExponentialNumerator;
        int realDenominatorExponentialDenominator;
        
    //Imaginary Part
      //Numerator Part
          //Sub Part
        double imaginaryNumeratorSub;
          //Exponential Part
        int imaginaryNumeratorExponentialNumerator;
        int imaginaryNumeratorExponentialDenominator;
      //Denominator Part
          //Sub Part
        int imaginaryDenominatorSub;
          //Exponential Part
        int imaginaryDenominatorExponentialNumerator;
        int imaginaryDenominatorExponentialDenominator;
    };
}

#endif	/* COMPLEXNUMBER_H */

