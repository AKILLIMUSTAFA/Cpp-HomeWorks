// HW06_131044017_Mustafa_Akilli
// 
// File:   main.cpp
// Author: Mustafa_Akilli
//
// Created on 01 Aralik 2015 Sali, 11:49 by Mustafa_Akilli
//
// Description
//
// Reversi Game in Dynamic Array
//
// HW6 main

#include <iostream>
#include <cstdlib>
#include "reversi.h"

using namespace std;

using namespace mustafaAkilli;

//Statics
int Reversi:: liveCellsNumber=0;

//Call by value
void callByValue(Reversi game);

//Call by reference
void callByReference(Reversi &game);

const static int WIDTH=5;
const static int HEIGHT=4;
const static int NEW_WIDTH=10;
const static int NEW_HEIGHT=8;
const static char SEMBOL='x';

int main(int argc, char** argv) {

    //TEST CELL
    Cell testCell(HEIGHT,WIDTH,SEMBOL);

    cout << "CELL TEST***************************************" << endl << endl
         << "HEIGHT:" << testCell.getX()<< endl 
         << "WIDTH: " << testCell.getY()<< endl 
         << "SEMBOL: "  << testCell.getSembol()<< endl << endl
         << "CELL TEST END************************************" << endl << endl;
    
    //CALL BY REFERENCE
    Reversi firstSimple(WIDTH,HEIGHT);
    callByValue(firstSimple);
    
    //CALL BY VALUE
    Reversi secondSimple;
    callByReference(secondSimple);

    //Which One is better?
    cout << "Second game is better: "
         << secondSimple.isFirstGameIsBetter(firstSimple) << endl;
            
    return 0;
}

//Call by value
void callByValue(Reversi game)
{
    Reversi firstStatus(game);
    
    cout << endl << endl << endl << endl
         << "First Simple Begin***************************************" << endl;
    
    //Living Cells Number:
    cout << endl << "Game Living Cells Number: " 
         << game.getLocalLiveCellsNumber()
         << endl << "firstStatus Living Cells Number: " 
         << firstStatus.getLocalLiveCellsNumber()
         << endl << "Total Living Cells Number(Call By Value +4): " 
         << game.getLivingCellsNumber() << endl;
    
    //Display Board
    game.displayBoard();  
    
    //Operator ++game
    ++game;

    //Living Cells Number:
    cout << endl << "Game Living Cells Number: " 
         << game.getLocalLiveCellsNumber()
         << endl << "firstStatus Living Cells Number: " 
         << firstStatus.getLocalLiveCellsNumber()
         << endl << "Total Living Cells Number (Call By Value +4): " 
         << game.getLivingCellsNumber() << endl;
    
    //resize Board
    game.resizeBoard(NEW_WIDTH, NEW_HEIGHT);
    
    cout << endl << "After resize: "
         << endl << "Total Living Cells Number: " 
         << game.getLivingCellsNumber() << endl;
    
    //Display Board
    cout << game;
    
    //Operator game++
    game++;
    
    //Copy Constructor
    cout << "First status: " << endl
         << firstStatus;
    
    Reversi lastStatus(game);     
    
    cout << "Last status: " << endl   
         << lastStatus;
      
    
    cout << endl << endl << "Game Living Cells Number: " 
         << game.getLocalLiveCellsNumber()
         << endl << "firstStatus Living Cells Number: " 
         << firstStatus.getLocalLiveCellsNumber()
         << endl << "lastStatus Living Cells Number: " 
         << lastStatus.getLocalLiveCellsNumber()
         << endl << "Total Living Cells Number (Call By Value +4): " 
         << game.getLivingCellsNumber() << endl << endl;
         
    //Stream insertion
    cout << "--The game result--" << endl
         << game;
     
    //END
    cout << endl
         << "First Simple End*****************************************" << endl
         << endl << endl << endl << endl;
    //
    //
    //firstSimple***************************************************************
}

//Call by reference
void callByReference(Reversi &game)
{
    cout << endl
         << "GAME IS BEGIN***************************************" 
         << endl << endl << endl;
    
    while(!game.endGame())
         game.playGame();
         
    game.playGame();
}