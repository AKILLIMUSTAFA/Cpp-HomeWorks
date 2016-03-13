#include "header.h"

void Triangle::setTriangle(const double &firstValue, const double &secondValue, const double &thirdValue)
{
    A=firstValue;
    B=secondValue;
    C=thirdValue;
    
    //Check
    is_it_legal_trilange(firstValue, secondValue, thirdValue);
}


void Triangle::setTriangle(double firstValue, double secondValue)
{
    A=firstValue;
    B=secondValue;
    C=1.0;
    
    //Check
    is_it_legal_trilange(firstValue, secondValue, 1.0);
}


void Triangle::setTriangle(double allValue)
{
    A=allValue;
    B=allValue;
    C=allValue;
    
    //Check
    is_it_legal_trilange(allValue, allValue, allValue);
}


void Triangle::setTriangle()
{
    A=1.0;
    B=1.0;
    C=1.0;
}
