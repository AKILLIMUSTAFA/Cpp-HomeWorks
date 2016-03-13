// HW01_131044017_Mustafa_AKILLI
// does_player_have_move_is_it_legal_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Computer iconu bittikten sonra sonunda nokta (empty) iconu olanlar varsa
// player hamle yapabilir anlamına gelmektedir

#include "othello_header.h"

void does_player_have_move_is_it_legal_move(char cells[21][21], 
        move_feature_t test[401], int number_of_player_move, int *can_move)
{
    int timer=0;
    int i=1;
    char empty_icon='.';
    char computer_icon='x';
    
    //CEVRESINDE COMPUTER ICONU OLANLARDA ILERLENIR
    //EGER SONUNDA NOKTAYA RASTLANIRSA
    //HAMLE LEGAL BIR HAMLEDIR
    while(timer<number_of_player_move)
    {
        //KUZEY
        if(test[timer].kuzey)
        {     
            while(cells[test[timer].line-1-i]
                    [test[timer].column]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line-1-i]
                    [test[timer].column]==empty_icon)
            {       
                (*can_move)=1;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //KUZEYBATI
        if(test[timer].kuzeybati)
        {
            while(cells[test[timer].line-1-i]
                    [test[timer].column-1-i]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line-1-i]
                    [test[timer].column-1-i]==empty_icon)
            {       
                (*can_move)=1;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //BATI
        if(test[timer].bati)
        {
            while(cells[test[timer].line]
                    [test[timer].column-1-i]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line]
                    [test[timer].column-1-i]==empty_icon)
            {       
                (*can_move)=1;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //GUNEYBATI
        if(test[timer].guneybati)
        {
            while(cells[test[timer].line+1+i]
                    [test[timer].column-1-i]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line+1+i]
                    [test[timer].column-1-i]==empty_icon)
            {       
                (*can_move)=1;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //GUNEY
        if(test[timer].guney)
        {
            while(cells[test[timer].line+1+i]
                    [test[timer].column]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line+1+i]
                    [test[timer].column]==empty_icon)
            {       
                (*can_move)=1;
            }

        }

        //DEGERLER SIFIRLANIR
        i=1;

        //GUNEYDOGU
        if(test[timer].guneydogu)
        {
            while(cells[test[timer].line+1+i]
                    [test[timer].column+1+i]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line+1+i]
                    [test[timer].column+1+i]==empty_icon)
            {       
                (*can_move)=1;
            }

        }

        //DEGERLER SIFIRLANIR
        i=1;

        //DOGU
        if(test[timer].dogu)
        {
            while(cells[test[timer].line]
                    [test[timer].column+1+i]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line]
                    [test[timer].column+1+i]==empty_icon)
            {       
                (*can_move)=1;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //KUZEYDOGU
        if(test[timer].kuzeydogu)
        {
            while(cells[test[timer].line-1-i]
                    [test[timer].column+1+i]==computer_icon)
            {
                ++i;
            }

            if(cells[test[timer].line-1-i]
                    [test[timer].column+1+i]==empty_icon)
            {       
                (*can_move)=1;
            }

        } 
        i=1;
        ++timer;
    } 
}