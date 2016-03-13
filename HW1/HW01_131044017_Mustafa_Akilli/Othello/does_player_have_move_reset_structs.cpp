// HW01_131044017_Mustafa_AKILLI
// does_player_have_move_reset_structs.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Struct degerleri sifirlanir

#include "othello_header.h"

void does_player_have_move_reset_structs(int size_of_board, 
                                        move_feature_t test[401])
{
    int timer=0;
    
    //DEGERLER SIFIRLANIR
    while(timer<=(size_of_board*size_of_board))
    {
        test[timer].legal=0;
        test[timer].total_gain=0;
        test[timer].column=0;
        test[timer].line=0;
        test[timer].kuzey=0;
        test[timer].kuzeybati=0;
        test[timer].bati=0;
        test[timer].guneybati=0;
        test[timer].guney=0;
        test[timer].guneydogu=0;
        test[timer].dogu=0;
        test[timer].kuzeydogu=0;
        ++timer;
    }
}