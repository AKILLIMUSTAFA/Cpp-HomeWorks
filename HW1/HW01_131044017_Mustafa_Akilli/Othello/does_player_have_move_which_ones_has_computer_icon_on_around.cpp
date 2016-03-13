// HW01_131044017_Mustafa_AKILLI
// does_player_have_move_which_ones_has_computer_icon_on_around.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Player'a ait olan hucrelerin cevreleri kontrol edilir
// cevresinde computer iconları olanlar secilir

#include "othello_header.h"

void does_player_have_move_which_ones_has_computer_icon_on_around(
        char cells[21][21], move_feature_t test[401], int number_of_player_move)
{
    int timer=0;
    char computer_icon='x'; 
    
    //GIRILEN HAMLENIN CEVRESI KONTROL EDILIR
    
    while(timer<(number_of_player_move))
    {
        //KUZEY
        if(cells[test[timer].line-1]
                [test[timer].column]==computer_icon)
            test[timer].kuzey=1;

        //KUZEYBATI
        if(cells[test[timer].line-1]
                [test[timer].column-1]==computer_icon)
            test[timer].kuzeybati=1;

        //BATI
        if(cells[test[timer].line]
                [test[timer].column-1]==computer_icon)
            test[timer].bati=1;

        //GUNEYBATI
        if(cells[test[timer].line+1]
                [test[timer].column-1]==computer_icon)
            test[timer].guneybati=1;

        //GUNEY
        if(cells[test[timer].line+1]
                [test[timer].column]==computer_icon)
            test[timer].guney=1;

        //GUNEYDOGU
        if(cells[test[timer].line+1]
                [test[timer].column+1]==computer_icon)
            test[timer].guneydogu=1;

        //DOGU
        if(cells[test[timer].line]
                [test[timer].column+1]==computer_icon)
            test[timer].dogu=1;

        //KUZEYDOGU
        if(cells[test[timer].line-1]
                [test[timer].column+1]==computer_icon)
            test[timer].kuzeydogu=1;
            
        ++timer;
    }
}