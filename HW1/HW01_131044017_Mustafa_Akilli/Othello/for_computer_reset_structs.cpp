// HW01_131044017_Mustafa_AKILLI
// for_computer_reset_structs.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Struct degerleri sifirlanir

#include "othello_header.h"

void for_computer_reset_structs(int size_of_board,
                                move_feature_t move_of_computer[401],
                                move_feature_t *best_move_for_computer)
{
    int timer=0;
    
    //DEGERLER SIFIRLANIR
    while(timer<=(size_of_board*size_of_board))
    {
        move_of_computer[timer].legal=0;
        move_of_computer[timer].total_gain=0;
        move_of_computer[timer].column=0;
        move_of_computer[timer].line=0;
        move_of_computer[timer].kuzey=0;
        move_of_computer[timer].kuzeybati=0;
        move_of_computer[timer].bati=0;
        move_of_computer[timer].guneybati=0;
        move_of_computer[timer].guney=0;
        move_of_computer[timer].guneydogu=0;
        move_of_computer[timer].dogu=0;
        move_of_computer[timer].kuzeydogu=0;
        ++timer;
    }
    
    //DEGERLER SIFIRLANIR
    best_move_for_computer->legal=0;
    best_move_for_computer->total_gain=0;
    best_move_for_computer->column=0;
    best_move_for_computer->line=0;
    best_move_for_computer->kuzey=0;
    best_move_for_computer->kuzeybati=0;
    best_move_for_computer->bati=0;
    best_move_for_computer->guneybati=0;
    best_move_for_computer->guney=0;
    best_move_for_computer->guneydogu=0;
    best_move_for_computer->dogu=0;
    best_move_for_computer->kuzeydogu=0;  
}