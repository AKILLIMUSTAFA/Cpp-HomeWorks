// HW03_131044017_Mustafa_Akıllı
// 
//
// Created on 29 Ekim 2015 Perşembe, 13:23 by Mustafa_Akıllı
//
// Description
//
// This is my first class. My class name is Triangle.
// This class can represent a triangle on a 2D plane with sides of length A,B,C 

#ifndef HEADER_H
#define	HEADER_H

class Triangle
{
public:
    Triangle(double firstSide,double secondSide, double thirdSide);
    Triangle(double firstSide,double secondSide);
    Triangle(double allSide);
    Triangle();
    
    void input();
    void output() const;
    
    //Accessors
    const double getFirstValue() const {return A;}
    const double getSecondValue() const {return B;}
    const double getThirdValue()const {return C;}
    
    //Mutators
    void setTriangle(const double &firstValue, const double &secondValue, const double &thirdValue);
    void setTriangle(double firstValue, double secondValue);
    void setTriangle(double allValue);
    void setTriangle();
    
    //Calculate Angle
    double calculate_angle_A() const ;
    double calculate_angle_B() const ;
    double calculate_angle_C() const ;
    
    //Calculate Area
    double area() const ;
    
    //Calculate Perimeter
    double perimeter() const ;
    
    //Is a right angle triangle
    bool is_a_right_angle_triangle() const ;
    
private:
    double A;
    double B;
    double C;
};

//Call by value
void call_by_value(Triangle triangle1);

//Call by reference
void call_by_reference(const Triangle &triangle1);

//Is it legal triangle
void is_it_legal_trilange(const double &firstSide, const double &secondSide, 
                          const double &thirdSide);

#endif	/* HEADER_H */

