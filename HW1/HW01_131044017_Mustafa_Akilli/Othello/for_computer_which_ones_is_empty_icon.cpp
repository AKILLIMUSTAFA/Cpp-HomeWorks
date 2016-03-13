// HW01_131044017_Mustafa_AKILLI
// for_computer_which_ones_is_empty_icon.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Hangi hucrelerın bos oldugu bulunur.

#include "othello_header.h"

void for_computer_which_ones_is_empty_icon(int size_of_board, char cells[21][21],
            move_feature_t move_of_computer[401],
            int *number_of_computer_move)
{
    int i=1, j=1;
    int timer=0;
    char empty_icon='.';
    
    while(i<=size_of_board)
    {
        while(j<=size_of_board)
        {
            if(cells[i][j]==empty_icon)
            {
               move_of_computer[timer].line=i;
               move_of_computer[timer].column=j;
               ++timer;
               ++(*number_of_computer_move);
            }
            ++j;
        }
    
        j=1;
        ++i;
    }
}