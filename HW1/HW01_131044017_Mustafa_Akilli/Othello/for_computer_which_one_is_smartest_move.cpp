// HW01_131044017_Mustafa_AKILLI
// for_computer_which_one_is_smartest_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// En akilli hareket bulunur

#include "othello_header.h"

void for_computer_which_one_is_smartest_move(move_feature_t move_of_computer[401],
            int number_of_computer_move, 
            move_feature_t *best_move_for_computer,int size_of_board)
{
    int timer=0;
    int check_corner=0;//Koselerde hamle varsa 1 yoksa 0 olur;
    int corner_total_gain=0;//Kosedeki noktanın toplam kazancı
    
    while(timer<number_of_computer_move)
    {
        //EN COK KAZANCLI OLAN VE KOSEDE OLAN SECILIR
        
        //SOL UST KOSE UYGUNSA
        //SOL ALT KOSE UYGUNSA
        //SAG UST KOSE UYGUNSA
        //SAG ALT KOSE UYGUNSA
        if((move_of_computer[timer].line==1 && move_of_computer[timer].column==1) ||
           (move_of_computer[timer].line==(size_of_board) && move_of_computer[timer].column==0) ||
           (move_of_computer[timer].line==1 && move_of_computer[timer].column==(size_of_board)) ||
           (move_of_computer[timer].line==(size_of_board) && move_of_computer[timer].column==(size_of_board)))
        {      
            if((move_of_computer[timer].total_gain)>corner_total_gain)
            {
                corner_total_gain=move_of_computer[timer].total_gain;
                check_corner=1;
                
                (best_move_for_computer->legal)=move_of_computer[timer].legal;
                (best_move_for_computer->total_gain)=move_of_computer[timer].total_gain;
                (best_move_for_computer->line)=move_of_computer[timer].line;
                (best_move_for_computer->column)=move_of_computer[timer].column;
                (best_move_for_computer->kuzey)=move_of_computer[timer].kuzey;
                (best_move_for_computer->kuzeybati)=move_of_computer[timer].kuzeybati;
                (best_move_for_computer->bati)=move_of_computer[timer].bati;
                (best_move_for_computer->guneybati)=move_of_computer[timer].guneybati;
                (best_move_for_computer->guney)=move_of_computer[timer].guney;
                (best_move_for_computer->guneydogu)=move_of_computer[timer].guneydogu;
                (best_move_for_computer->dogu)=move_of_computer[timer].dogu;
                (best_move_for_computer->kuzeydogu)=move_of_computer[timer].kuzeydogu;
            }  
        }
        
        
        //EGER KOSEDE OLAN YOKSA
        //EN COK KAZANCLI OLAN SECILIR
        if(!check_corner)
        {
            if((move_of_computer[timer].total_gain)>(best_move_for_computer->total_gain))
            {
                (best_move_for_computer->legal)=move_of_computer[timer].legal;
                (best_move_for_computer->total_gain)=move_of_computer[timer].total_gain;
                (best_move_for_computer->line)=move_of_computer[timer].line;
                (best_move_for_computer->column)=move_of_computer[timer].column;
                (best_move_for_computer->kuzey)=move_of_computer[timer].kuzey;
                (best_move_for_computer->kuzeybati)=move_of_computer[timer].kuzeybati;
                (best_move_for_computer->bati)=move_of_computer[timer].bati;
                (best_move_for_computer->guneybati)=move_of_computer[timer].guneybati;
                (best_move_for_computer->guney)=move_of_computer[timer].guney;
                (best_move_for_computer->guneydogu)=move_of_computer[timer].guneydogu;
                (best_move_for_computer->dogu)=move_of_computer[timer].dogu;
                (best_move_for_computer->kuzeydogu)=move_of_computer[timer].kuzeydogu;
            }
        }
        ++timer;
    }
}