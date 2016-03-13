#include "header.h"
#include <iostream>

using namespace std;

void call_by_value(Triangle triangle1)
{
    double angleA, angleB, angleC;
    int right_angle=triangle1.is_a_right_angle_triangle();
    
    //Check
    is_it_legal_trilange(triangle1.getFirstValue(), triangle1.getSecondValue(), 
                         triangle1.getThirdValue());
    
    //Print all sides of Triangle
    triangle1.output();
    
    //calculate all angles of Triangle
    angleA=triangle1.calculate_angle_A();
    angleB=triangle1.calculate_angle_B();
    angleC=triangle1.calculate_angle_C();
    
    double totalAngle=angleA+angleB+angleC;
    
    
    //if Any angle bigger than 90
    
    //İf First Value bigger than 90
    if(totalAngle!=180 && triangle1.getFirstValue()>triangle1.getSecondValue()
       && triangle1.getFirstValue()>triangle1.getThirdValue())
            angleA+=(180-totalAngle);
    
    //İf Second Value bigger than 90
    else if(totalAngle!=180 && triangle1.getSecondValue()>triangle1.getFirstValue()
       && triangle1.getSecondValue()>triangle1.getThirdValue())
            angleB+=(180-totalAngle);
    
    //İf Third Value bigger than 90
    else if(totalAngle!=180 && triangle1.getThirdValue()>triangle1.getSecondValue()
       && triangle1.getThirdValue()>triangle1.getFirstValue())
            angleC+=(180-totalAngle);
   
    

    //Print all angles of Triangle
    cout << "Angle A: " << angleA << endl
         << "Angle B: " << angleB << endl
         << "Angle C: " << angleC << endl << endl;
    
    
    
    //Print all angles of Triangle
    if(right_angle)
    {
        cout << triangle1.getFirstValue() << "-"
             << triangle1.getSecondValue() << "-"
             << triangle1.getThirdValue()
             << " İt is a right angle triangle" << endl;
    }
    
    else
    {
        cout << triangle1.getFirstValue() << "-"
             << triangle1.getSecondValue() << "-"
             << triangle1.getThirdValue()
             << " İt is not a right angle triangle" << endl;
    }
               
}