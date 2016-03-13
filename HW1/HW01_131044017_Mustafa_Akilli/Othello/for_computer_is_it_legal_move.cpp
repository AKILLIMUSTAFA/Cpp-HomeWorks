// HW01_131044017_Mustafa_AKILLI
// for_computer_is_it_legal_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Player iconu bittikten sonra sonunda computer iconu olanlar secilir

#include "othello_header.h"

void for_computer_is_it_legal_move(char cells[21][21],
            move_feature_t move_of_computer[401], 
            int number_of_computer_move)
{
    int timer=0;
    int i=1;
    char player_icon='o';
    char computer_icon='x';
    
    //CEVRESINDE PLAYER ICONU OLANLARDA ILERLENIR
    //EGER SONUNDA COMPUTER ICONUNA RASTLANIRSA
    //HAMLE LEGAL BIR HAMLEDIR
    
    while(timer<number_of_computer_move)
    {
        //KUZEY
        if(move_of_computer[timer].kuzey)
        {     
            while(cells[move_of_computer[timer].line-1-i]
                    [move_of_computer[timer].column]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line-1-i]
                    [move_of_computer[timer].column]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //KUZEYBATI
        if(move_of_computer[timer].kuzeybati)
        {
            while(cells[move_of_computer[timer].line-1-i]
                    [move_of_computer[timer].column-1-i]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line-1-i]
                    [move_of_computer[timer].column-1-i]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //BATI
        if(move_of_computer[timer].bati)
        {
            while(cells[move_of_computer[timer].line]
                    [move_of_computer[timer].column-1-i]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line]
                    [move_of_computer[timer].column-1-i]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //GUNEYBATI
        if(move_of_computer[timer].guneybati)
        {
            while(cells[move_of_computer[timer].line+1+i]
                    [move_of_computer[timer].column-1-i]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line+1+i]
                    [move_of_computer[timer].column-1-i]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //GUNEY
        if(move_of_computer[timer].guney)
        {
            while(cells[move_of_computer[timer].line+1+i]
                    [move_of_computer[timer].column]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line+1+i]
                    [move_of_computer[timer].column]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }

        }

        //DEGERLER SIFIRLANIR
        i=1;

        //GUNEYDOGU
        if(move_of_computer[timer].guneydogu)
        {
            while(cells[move_of_computer[timer].line+1+i]
                    [move_of_computer[timer].column+1+i]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line+1+i]
                    [move_of_computer[timer].column+1+i]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }

        }

        //DEGERLER SIFIRLANIR
        i=1;

        //DOGU
        if(move_of_computer[timer].dogu)
        {
            while(cells[move_of_computer[timer].line]
                    [move_of_computer[timer].column+1+i]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line]
                    [move_of_computer[timer].column+1+i]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=1;

        //KUZEYDOGU
        if(move_of_computer[timer].kuzeydogu)
        {
            while(cells[move_of_computer[timer].line-1-i]
                    [move_of_computer[timer].column+1+i]==player_icon)
            {
                ++i;
            }

            if(cells[move_of_computer[timer].line-1-i]
                    [move_of_computer[timer].column+1+i]==computer_icon)
            {       
                move_of_computer[timer].legal=1;
                move_of_computer[timer].total_gain+=i;
            }

        }
        
        i=1;
        ++timer;
    }
}