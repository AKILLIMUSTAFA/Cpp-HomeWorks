// HW01_131044017_Mustafa_AKILLI
// for_computer_which_ones_has_player_icon_on_around.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Bos olan hucrelerin cevreleri kontrol edilir
// cevresinde player iconlari olanlar secilir

#include "othello_header.h"

void for_computer_which_ones_has_player_icon_on_around(char cells[21][21],
            move_feature_t move_of_computer[401], 
            int number_of_computer_move)
{
    int timer=0;
    char player_icon='o'; 
    
    //GIRILEN HAMLENIN CEVRESI KONTROL EDILIR
    while(timer<(number_of_computer_move))
    {
        //KUZEY
        if(cells[move_of_computer[timer].line-1]
                [move_of_computer[timer].column]==player_icon)
            move_of_computer[timer].kuzey=1;

        //KUZEYBATI
        if(cells[move_of_computer[timer].line-1]
                [move_of_computer[timer].column-1]==player_icon)
            move_of_computer[timer].kuzeybati=1;

        //BATI
        if(cells[move_of_computer[timer].line]
                [move_of_computer[timer].column-1]==player_icon)
            move_of_computer[timer].bati=1;

        //GUNEYBATI
        if(cells[move_of_computer[timer].line+1]
                [move_of_computer[timer].column-1]==player_icon)
            move_of_computer[timer].guneybati=1;

        //GUNEY
        if(cells[move_of_computer[timer].line+1]
                [move_of_computer[timer].column]==player_icon)
            move_of_computer[timer].guney=1;

        //GUNEYDOGU
        if(cells[move_of_computer[timer].line+1]
                [move_of_computer[timer].column+1]==player_icon)
            move_of_computer[timer].guneydogu=1;

        //DOGU
        if(cells[move_of_computer[timer].line]
                [move_of_computer[timer].column+1]==player_icon)
            move_of_computer[timer].dogu=1;

        //KUZEYDOGU
        if(cells[move_of_computer[timer].line-1]
                [move_of_computer[timer].column+1]==player_icon)
            move_of_computer[timer].kuzeydogu=1;
        
        ++timer;
    }
}

