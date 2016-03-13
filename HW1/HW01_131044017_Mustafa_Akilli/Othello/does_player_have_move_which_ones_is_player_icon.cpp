// HW01_131044017_Mustafa_AKILLI
// does_player_have_move_which_ones_is_player_icon.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Player'a ait olan iconlar bulunur

#include "othello_header.h"

void does_player_have_move_which_ones_is_player_icon(int size_of_board, 
        char cells[21][21], move_feature_t test[401], int *number_of_player_move)
{
    int i=1, j=1;
    char player_icon='o';
    
    //Player'a ait olan iconlar bulunur
    while(i<=size_of_board)
    {
        while(j<=size_of_board)
        {
            if(cells[i][j]==player_icon)
            {
               test[(*number_of_player_move)].line=i;
               test[(*number_of_player_move)].column=j;
               ++(*number_of_player_move);
            }
            ++j;
        }
        j=1;
        ++i;
    }
}