// HW01_131044017_Mustafa_AKILLI
// paint_board.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Guncel board ekrana cizilir.

#include "othello_header.h"

void paint_board(int size_of_board, char cells[21][21])
{
    int i=0, j=0, left_side=1;
    
    cout << "\n";
    
    while(i<=size_of_board)
    {       
        //SATIR BASINA RAKAM YERLESTIRILIR
        if(i>0)
        {
            cout << ""<< left_side;
            ++left_side;
        }
        
        //ILK SATIRA RAKAM YERINE BOSLUK YERLESTIRILIR
        else
        {
            cout << " ";
        }
        
        //ARRAY PRINT EDILIR
        while(j<=size_of_board)
        {
            //10 RAKAMINA KADAR SAYILARDAN SONRA BOSLUK YAZILIR
            if(i<10)
            {
                cout << ""<< cells[i][j];
                ++j;
            }
            
            //10 RAKAMINDAN SONRA SAYILARDAN SONRA BOSLUK YAZILMAZ
            else
            {   
                ++j;
                if(j<=size_of_board)
                    cout << ""<< cells[i][j];
            }
        }
        j=0;
        cout << "\n";
        ++i;
    }  
}