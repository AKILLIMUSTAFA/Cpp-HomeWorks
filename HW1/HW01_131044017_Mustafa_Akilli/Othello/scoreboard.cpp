// HW01_131044017_Mustafa_AKILLI
// scoreboard.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Skor Yazılır

#include "othello_header.h"

void scoreboard(int size_of_board, char cells[21][21])
{
    int i, j;
    int computer_score=0;
    int player_score=0;
    char player_icon='o';
    char computer_icon='x';
    
    //Butun hucreler kontrol edilir
    for(i=1;i<=(size_of_board);++i)
    {
        for(j=1;j<=(size_of_board);++j)
        {
            //Player'a ait olan yerler icin
            //Player score 1 arttirilir
            if(cells[i][j]==player_icon)
                ++player_score;
            
            //Computere ait olan yerler icin
            //Computer score 1 arttirilir
            else if(cells[i][j]==computer_icon)
                ++computer_score;
        }
    }
    
    //Player ve computer score ekrana yazdirilir
    cout<<"\nPlayer score: "<< player_score
        <<"\nComputer score: "<< computer_score; 
}