#include "header.h"
#include <math.h>

double Triangle::area() const
{
    double u= perimeter() / 2; //Half of the triangle perimeter
    double triangleArea=sqrt(u*(u-A)*(u-B)*(u-C)); // Area of triangle
    
    return triangleArea; // Return area of triangle
}