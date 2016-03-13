#include "header.h"
#include <math.h>
#include <iostream>

using namespace std;

double Triangle::calculate_angle_C() const
{
    double PI=3.14159265; //PI number
    double triangleArea=area(); // Area of triangle
    double angleC=(2*triangleArea)/(A*B); // Sin value Angle of a triangle 
                                          // corner C
    
    return asin (angleC) * 180.0 / PI; //return Angle of a triangle corner C
}
