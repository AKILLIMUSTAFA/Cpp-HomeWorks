// HW01_131044017_Mustafa_AKILLI
// board_size.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04  by Mustafa_AKILLI
//
// Description
//
// Gecerli bir size of board degeri girilene kadar,
// kullanicidan size of board degeri istenir.

#include "othello_header.h"
#include<limits>

int board_size()
{
    
    int SizeOfBoard, temp=1;

    cout << "Hello Player.\n" 
         << "Welcome to Othello.\n\n";

    cout << "Sıze Of Board can be between 4 and 20.\n"
         << "Sıze Of Board can be even number.\n"
         << "Enter Sıze Of Board: ";

    cin >> SizeOfBoard;
    
    //Eger Size of Board gecersiz bir deger ise hata mesaji verilir

    while(temp)
    {
        if(SizeOfBoard>=4 && SizeOfBoard<=20 && (SizeOfBoard%2)==0)
            temp=0; 
        
        else
        {    
            cout << "Invalid Input\n"
                 << "Enter Sıze Of Board: ";  
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> SizeOfBoard;
        }
            
    }
    
    //Gecerli bir size of board degeri return edilir.
    return SizeOfBoard;
    
}

