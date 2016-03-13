// HW06_131044017_Mustafa_Akilli
// 
// File:   cell.cpp
// Author: Mustafa_Akilli
//
// Created on 01 Aralik 2015 Sali, 12:10 by Mustafa_Akilli
//
// Description
//
// Reversi Game in Dynamic Array
//
// HW6 cell class implementation
#include "cell.h"



namespace
{
    const static int ZERO=0;
    
    const static int EMPTY_SEMBOL_NUMBER=0;
    const static int PLAYER_SEMBOL_NUMBER=1;
    const static int COMPUTER_SEMBOL_NUMBER=2;
    
    //SEMBOLS
    const static char EMPTY_SEMBOL='.'; // empty cell icon
    const static char PLAYER_SEMBOL='o'; // player cell icon
    const static char COMPUTER_SEMBOL='x'; // computer cell icon
}


namespace mustafaAkilli
{
    //Constructors**************************************************************
    Cell::Cell(int newX, int newY, char newSembol):
                X(newX), Y(newY), cellSembol(newSembol)
    {//Body intentionally empty.   
    }

    Cell::Cell():
               X(ZERO), Y(ZERO), cellSembol('.')
    {//Body intentionally empty.
    }




    //Setters (Mutators)********************************************************

    // Set cellSembol 0 girilirse empty_sembol,
    // 1 girilirse player_sembol, 2 girilirse computer_sembol
    void Cell::setSembol(const int &newSembolNumber)
    {
        if(newSembolNumber==EMPTY_SEMBOL_NUMBER)
            cellSembol=EMPTY_SEMBOL;
        else if(newSembolNumber==PLAYER_SEMBOL_NUMBER)
            cellSembol=PLAYER_SEMBOL;
        else if(newSembolNumber==COMPUTER_SEMBOL_NUMBER)
            cellSembol=COMPUTER_SEMBOL;
        else
            ;
    }

}