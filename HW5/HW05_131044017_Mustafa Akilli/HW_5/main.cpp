// HW05_131044017_Mustafa_Akilli
//
// File:   main.cpp
// Author: Mustafa_Akilli
//
// Created on 04 Kasim 2015 Carsamba, 10:56
//
// Description
//
// HW4 main

#include "header.h"
#include<limits>

//Statics
int Reversi:: liveCellsNumber=0;

int main() {
    
    
    //Gecerli bir size of board degeri girilmezse oyun biter.
    Reversi firstSimple(3,3);
    Reversi secondSimple(4,4);
    Reversi thirdSimple(5,7);
    Reversi fourthSimple(8,2);
    Reversi fifthSimple(2,8);
    
    Cell test;
    Cell move(2,3,'.');
    
    //firstSimple***************************************************************
    //
    //
    cout << "First Simple Begin***************************************" << endl;
    
    //DisplayBoard
    firstSimple.displayBoard();
    
    //Operator ++
    ++firstSimple;
    
    
    //Operator []
    test=firstSimple["A1"];
    
    cout << endl << "-----For A1-----" << endl
         << "X: " << test.getX()+1 << endl 
         << "Y: "<< test.getY()+1 << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    test=firstSimple["M7"];
    
    cout << endl << "-----For M7-----" << endl
         << "X: " << test.getX()+1 << endl 
         << "Y: "<< test.getY()+1 << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    
    //Operator ()
    test=firstSimple("B1");
    
    cout << endl << "-----For C1-----" << endl
         << "X: " << test.getX()+1 << endl 
         << "Y: "<< test.getY()+1 << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    test=firstSimple("H10");
    
    cout << endl << "-----For H10-----" << endl
         << "X: " << test.getX()+1 << endl 
         << "Y: "<< test.getY()+1 << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    
    
    //Operator +=
    firstSimple+=move; // move 3C
    
    //MOVES
    //computer move
    ++firstSimple;
    //computer move
    ++firstSimple;

    
    
    //Stream insertion
    cout << "--The game result--" << endl
         << firstSimple;
    
    //END
    cout << "First Simple End*****************************************" << endl;
    
    //
    //
    //firstSimple***************************************************************

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //secondSimple**************************************************************
    //
    //
    cout << endl 
         << "Second Simple Begin**************************************" << endl;
    
    //DisplayBoard
    secondSimple.displayBoard();
    
    //Operator ++
    ++secondSimple;
    
    
    //Operator []
    test=secondSimple["A3"];
    
    cout << endl << "-----For A3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    test=secondSimple["M7"];
    
    cout << endl << "-----For M7-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    
    //Operator ()
    test=secondSimple("C3");
    
    cout << endl << "-----For C3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    test=secondSimple("H10");
    
    cout << endl << "-----For H10-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    
    
    //Operator +=
    move.setX(1); move.setY(2);
    secondSimple+=move; // move 1B
    
    //MOVES
    //computer move
    ++secondSimple;
    //player move
    move.setX(1); move.setY(4);
    secondSimple+=move; // move 1D
    
    
    //Stream insertion
    cout << endl << "--The game result--" << endl
         << secondSimple;
    
    //END
    cout << "Second Simple End****************************************" << endl;
    
    //
    //
    //secondSimple**************************************************************
    
   
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //thirdSimple**************************************************************
    //
    //
    cout << endl 
         << "Third Simple Begin**************************************" << endl;
    
    //DisplayBoard
    thirdSimple.displayBoard();
    
    //Operator ++
    ++thirdSimple;
    
    //Operator []
    test=thirdSimple["A3"];
    
    cout << endl << "-----For A3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    test=thirdSimple["M7"];
    
    cout << endl << "-----For M7-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    
    //Operator ()
    test=thirdSimple("C2");
    
    cout << endl << "-----For C3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    test=thirdSimple("H10");
    
    cout << endl << "-----For H10-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    
    
    //Operator +=
    move.setX(1); move.setY(3);
    thirdSimple+=move; // move 1C
    
    //MOVES
    //computer move
    ++thirdSimple;
    
    
    //Stream insertion
    cout << endl << "--The game result--" << endl
         << thirdSimple;
    
    //END
    cout << "Third Simple End****************************************" << endl;
    
    //
    //
    //thirdSimple**************************************************************
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //fourthSimple**************************************************************
    //
    //
    cout << endl 
         << "Fourth Simple Begin**************************************" << endl;
    
    //DisplayBoard
    fourthSimple.displayBoard();
    
    //Operator ++
    ++fourthSimple;
    
    //Operator []
    test=fourthSimple["A3"];
    
    cout << endl << "-----For A3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    test=fourthSimple["M7"];
    
    cout << endl << "-----For M7-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    
    //Operator ()
    test=fourthSimple("C2");
    
    cout << endl << "-----For C3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    test=fourthSimple("H10");
    
    cout << endl << "-----For H10-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    
    
    //Operator +=
    move.setX(3); move.setY(1);
    fourthSimple+=move; // move 3A
    
    //MOVES
    //computer move
    ++fourthSimple;
    
    
    //Stream insertion
    cout << endl << "--The game result--" << endl
         << fourthSimple;
    
    //END
    cout << "Fourth Simple End****************************************" << endl;
    
    //
    //
    //fourthSimple**************************************************************
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //fifthSimple**************************************************************
    //
    //
    cout << endl 
         << "Fifth Simple Begin**************************************" << endl;
    
    //DisplayBoard
    fifthSimple.displayBoard();
    
    //Operator ++
    ++fifthSimple;
    
    
    //Operator []
    test=fifthSimple["A3"];
    
    cout << endl << "-----For A3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    test=fifthSimple["M7"];
    
    cout << endl << "-----For M7-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    
    //Operator ()
    test=fifthSimple("C2");
    
    cout << endl << "-----For C3-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl; 
    
    test=fifthSimple("H10");
    
    cout << endl << "-----For H10-----" << endl
         << "X: " << test.getX() << endl 
         << "Y: "<< test.getY() << endl 
         << "Sembol: "<< test.getSembol() << endl;
    
    
    
    //Operator +=
    move.setX(2); move.setY(6);
    fifthSimple+=move; // move 2F
    
    //MOVES
    //computer move
    ++fifthSimple;
    
    
    //Stream insertion
    cout << endl << "--The game result--" << endl
         << fifthSimple;
    
    //END
    cout << "Fifth Simple End****************************************" << endl;
    
    //
    //
    //fifthSimple**************************************************************
    
    
    
   
    
    return 0;
}