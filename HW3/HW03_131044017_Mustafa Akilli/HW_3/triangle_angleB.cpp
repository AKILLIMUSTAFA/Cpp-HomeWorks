#include "header.h"
#include <math.h>
#include <iostream>

using namespace std;

double Triangle::calculate_angle_B() const
{
    double PI=3.14159265; //PI number
    double triangleArea=area(); // Area of triangle
    double angleB=(2*triangleArea)/(A*C); // Sin value Angle of a triangle 
                                          // corner B 
    
    return asin (angleB) * 180.0 / PI; //return Angle of a triangle corner B
}
