// HW04_131044017_Mustafa_Akilli
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
    
    //Oyun Basi Mesaji
    cout << "Hello Player." << endl << "Welcome to Reversi." << endl << endl
         << "There is no limit for the Size of Board." << endl
         << "But Size of Board can be pozitif number." << endl << endl;
    
   
    //Gecerli bir size of board degeri girilmezse oyun biter.
    Reversi firstSimple;
    Reversi secondSimple;
    Reversi thirdSimple;
    Reversi fourthSimple;
    Reversi fifthSimple;
    
    
    
    //5 oyunda sira ile hamle yapilir
   while( !firstSimple.endGame() || !secondSimple.endGame() ||
          !thirdSimple.endGame() || !fourthSimple.endGame() ||
          !fifthSimple.endGame() )
    {
        firstSimple.playGame();
        cout << "******************************" << endl;
        secondSimple.playGame();
        cout << "******************************" << endl;
        thirdSimple.playGame();
        cout << "******************************" << endl;
        fourthSimple.playGame();
        cout << "******************************" << endl;
        fifthSimple.playGame();
        cout << "******************************" << endl;
    }    
    
    //Playera ait olan hucre sayisi her obje icin yazdirilir
    cout << "Score Tables: " << endl
         << "First game: " << firstSimple.getPlayerScore() << endl
         << "Second game: " << secondSimple.getPlayerScore() << endl
         << "Third game: " << thirdSimple.getPlayerScore() << endl
         << "Fourth game: " << fourthSimple.getPlayerScore() << endl
         << "Fifth game: " << fifthSimple.getPlayerScore() << endl << endl;
     
    
    
    
    //isFirstGameIsBetter fonksiyonu cagrilir
    //eger isFirstGameIsBetter fonksiyonunu cagiran objenin skoru 
    //parametre olarak alinan objenin skorundan daha iyi ise 1,
    //daha iyi degil ise 0 return edilir
    cout << endl << endl << "Which One Is Better:" << endl
         << endl << "First game vs Second game: "
         << firstSimple.isFirstGameIsBetter(secondSimple)
         << endl << "First game vs Third game: " 
         << firstSimple.isFirstGameIsBetter(thirdSimple)
         << endl << "First game vs Fourth game: " 
         << firstSimple.isFirstGameIsBetter(fourthSimple)
         << endl << "First game vs Fifth game: " 
         << firstSimple.isFirstGameIsBetter(fifthSimple);
    
    
    cout << endl << endl << "All Living Cells Number: " 
         << Reversi::getLivingCellsNumber();
    
    return 0;
}