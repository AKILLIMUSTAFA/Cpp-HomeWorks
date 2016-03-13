#include "header.h"
#include <math.h>
#include <iostream>

using namespace std;

double Triangle::calculate_angle_A() const
{
    double PI=3.14159265; //PI number
    double triangleArea=area(); // Area of triangle
    double angleA=(2*triangleArea)/(B*C); // Sin value Angle of a triangle 
                                          // corner B 
    
    return asin (angleA) * 180.0 / PI; //return Angle of a triangle corner B
}
