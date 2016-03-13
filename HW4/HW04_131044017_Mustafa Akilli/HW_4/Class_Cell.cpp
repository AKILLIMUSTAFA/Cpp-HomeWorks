// HW04_131044017_Mustafa_Akilli
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