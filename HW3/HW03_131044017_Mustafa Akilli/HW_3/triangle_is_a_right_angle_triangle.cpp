#include "header.h"
#include <iostream>

using namespace std;

bool Triangle::is_a_right_angle_triangle() const
{   
    int angleA=calculate_angle_A();// angle A
    int angleB=calculate_angle_B();// angle B
    int angleC=calculate_angle_C();// angle C
    
    if(angleA==90 || angleB==90 || angleC==90) //İf right_angle_triangle
        return true;
    
    return false; //İf not right_angle_triangle
}