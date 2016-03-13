// HW05_131044017_Mustafa_Akilli
//
// File:   Class_Cell.cpp
// Author: Mustafa_Akilli
//
// Created on 04 Kasim 2015 Carsamba, 10:59
//
// Description
//
// HW4 Cell Class

#include "header.h"
#include<limits>

//Constructors******************************************************************
Cell::Cell(int newX, int newY, char newSembol):
            X(newX), Y(newY), cellSembol(newSembol)
{//Body intentionally empty.   
}

Cell::Cell():
           X(0), Y(0), cellSembol('.')
{//Body intentionally empty.
}




//Setters (Mutators)************************************************************

// Set cellSembol 0 girilirse empty_sembol,
// 1 girilirse player_sembol, 2 girilirse computer_sembol
void Cell::setSembol(const int &newSembolNumber)
{
    if(newSembolNumber==0)
        cellSembol=empty_sembol;
    else if(newSembolNumber==1)
        cellSembol=player_sembol;
    else if(newSembolNumber==2)
        cellSembol=computer_sembol;
    else
        ;
}

//OPERATOR OVERLOADING**********************************************************
//
//
//One Cell object is smaller than the other if the Y components is smaller. 
//If Y components are equal, then check the X component.
bool operator <(const Cell& firstCell, const Cell& secondCell)
{
    int result;
    
    if(firstCell.Y<secondCell.Y)
        result=true;
    
    else if(firstCell.Y==secondCell.Y)
    {
        if(firstCell.X<secondCell.X)
            result=true;

        else
            result=false;
    }
    
    else
        result=false;
    
    
    return result;
}

//One Cell object is bigger than the other if the Y components is bigger. 
//If Y components are equal, then check the X component.
bool operator >(const Cell& firstCell, const Cell& secondCell)
{
    int result;
    
    if(firstCell.Y>secondCell.Y)
        result=true;
    
    else if(firstCell.Y==secondCell.Y)
    {
        if(firstCell.X>secondCell.X)
            result=true;

        else
            result=false;
    }
    
    else
        result=false;
    
    return result;
}

//One Cell object is  equal or bigger than the other if the Y components 
//is equal or bigger.
bool operator >=(const Cell& firstCell, const Cell& secondCell)
{
    int result;
    
    if(firstCell.Y>=secondCell.Y)
        result=true;
    
    else
        result=false;
    
    return result;
}

//One Cell object is equal or smaller than the other if the Y components 
//is equal or smaller.
bool operator <=(const Cell& firstCell, const Cell& secondCell)
{
    int result;
    
    if(firstCell.Y<=secondCell.Y)
        result=true;
    
    else
        result=false;
    
    return result;
}

//One Cell object is equal the other if the Y components is equal.
bool operator ==(const Cell& firstCell, const Cell& secondCell)
{
    int result;
    
    if(firstCell.Y==secondCell.Y)
        result=true;
    
    else
        result=false;
    
    return result;
}

//One Cell object is not equal the other if the Y components is not equal.
bool operator !=(const Cell& firstCell, const Cell& secondCell)
{
    return !(firstCell==secondCell);
}

//Operators ++ that increment the X and Y components by one Prefix version
Cell Cell::operator++( )
{
    return Cell(++X,++Y,getSembol());
}
    
//Operators ++ that increment the X and Y components by one Postfix version
Cell Cell::operator++(int ignoreMe)
{
    return Cell(X++,Y++,getSembol());
}
    
//Operators -- that decrement the X and Y components by one Prefix version
Cell Cell::operator--( )
{
    return Cell(--X,--Y,getSembol());
}
    
//Operators -- that decrement the X and Y components by one Postfix version
Cell Cell::operator--(int ignoreMe)
{
    return Cell(X--,Y--,getSembol());
}

//Stream insertion operators
ostream& operator <<(ostream& outputStream, const Cell &simple)
{
    outputStream << endl << "X: " << simple.getX() 
                 << " Y: " << simple.getY() 
                 << " SEMBOL: " << simple.getSembol() << endl;
    
    return outputStream;
}

//Stream extraction operators
istream& operator >>(istream& inputStream, Cell &simple)
{
    int newX, newY;
    char newSembol;
    
    cout << endl << "Give the new X: ";
    inputStream >> newX;
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << endl << "Give the new Y: ";
    inputStream >> newY;
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << endl << "Give the new Sembol: ";
    inputStream >> newSembol;
    
    simple.setX(newX);
    simple.setY(newY);
    simple.setSembol(newSembol);
    
    return inputStream;
}
//
//
//OPERATOR OVERLOADING**********************************************************