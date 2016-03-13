// HW01_131044017_Mustafa_AKILLI
// first_view.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Hucrelerin oyun basi degerleri verilir

#include "othello_header.h"

void first_view(int size_of_board, char cells[21][21])
{
    int i=0, j=1;
    char top_side='a';
    
    while(i<=size_of_board)
    { 
        while(j<=size_of_board)
        {
            //ILK SATIRA HARFLER YERLESTIRILIR
            if(i==0)
            {
                cells[i][j]=top_side;
                ++top_side;
            }
            
            //NOKTALAR YERLESTIRILIR
            else
                cells[i][j]='.';
                
            ++j;
        }
        j=1;
        
        //SATIR BASINA BOSLUK YERLESTIRILIR
        if(i>0)
        {
            cells[i][0]=' ';
        }
        else
        {
            cells[i][0]=' ';
        }
        
        //ALT SATIRA GECILIR
        ++i;
    }
    
    //OYUN BASI 2 "X" VE 2 "O" YERLESTIRILIR
    cells[(size_of_board/2)][(size_of_board/2)]='x';
    cells[(size_of_board/2)][(size_of_board/2)+1]='o';
    cells[(size_of_board/2)+1][(size_of_board/2)]='o';
    cells[(size_of_board/2)+1][(size_of_board/2)+1]='x';
}