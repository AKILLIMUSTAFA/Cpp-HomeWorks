// HW01_131044017_Mustafa_AKILLI
// for_computer_do_best_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// En akilli hareket uygulanilir

#include "othello_header.h"

void for_computer_do_best_move(char cells[21][21],
            move_feature_t best_move_for_computer,
            int *computer_can_move)
{
    int i=1, temp_i=0;
    char column_letter;
    char character='a';
    char player_icon='o';
    char computer_icon='x';
    int check_character=1;
    
    if(best_move_for_computer.legal)
    {
        //SUTUN DEGERININ SAYI KARSILIGININ BULUNMASI
        column_letter=(character+best_move_for_computer.column-1);
        
        //Computerin yaptıgı hareket
        cout << "\nThe computer's move is "<< best_move_for_computer.line
             << column_letter;
        
        
        
        //KUZEY
        if(best_move_for_computer.kuzey)
        {     
            while(cells[best_move_for_computer.line-1-i]
                    [best_move_for_computer.column]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line-1-i]
                    [best_move_for_computer.column]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line-1-temp_i]
                         [best_move_for_computer.column]=computer_icon;
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0;

        //KUZEYBATI
        if(best_move_for_computer.kuzeybati)
        {
            while(cells[best_move_for_computer.line-1-i]
                    [best_move_for_computer.column-1-i]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line-1-i]
                    [best_move_for_computer.column-1-i]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line-1-temp_i]
                         [best_move_for_computer.column-1-temp_i]=computer_icon;
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0;

        //BATI
        if(best_move_for_computer.bati)
        {
            while(cells[best_move_for_computer.line]
                    [best_move_for_computer.column-1-i]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line]
                    [best_move_for_computer.column-1-i]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line]
                         [best_move_for_computer.column-1-temp_i]=computer_icon;
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0;

        //GUNEYBATI
        if(best_move_for_computer.guneybati)
        {
            while(cells[best_move_for_computer.line+1+i]
                    [best_move_for_computer.column-1-i]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line+1+i]
                    [best_move_for_computer.column-1-i]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line+1+temp_i]
                         [best_move_for_computer.column-1-temp_i]=computer_icon;
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0;

        //GUNEY
        if(best_move_for_computer.guney)
        {
            while(cells[best_move_for_computer.line+1+i]
                    [best_move_for_computer.column]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line+1+i]
                    [best_move_for_computer.column]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line+1+temp_i]
                         [best_move_for_computer.column]=computer_icon;
                    ++temp_i;
                }
            }

        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0;

        //GUNEYDOGU
        if(best_move_for_computer.guneydogu)
        {
            while(cells[best_move_for_computer.line+1+i]
                    [best_move_for_computer.column+1+i]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line+1+i]
                    [best_move_for_computer.column+1+i]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line+1+temp_i]
                         [best_move_for_computer.column+1+temp_i]=computer_icon;
                    ++temp_i;
                }
            }

        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0;

        //DOGU
        if(best_move_for_computer.dogu)
        {
            while(cells[best_move_for_computer.line]
                    [best_move_for_computer.column+1+i]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line]
                    [best_move_for_computer.column+1+i]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line]
                         [best_move_for_computer.column+1+temp_i]=computer_icon;
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0;

        //KUZEYDOGU
        if(best_move_for_computer.kuzeydogu)
        {
            while(cells[best_move_for_computer.line-1-i]
                    [best_move_for_computer.column+1+i]==player_icon)
            {
                ++i;
            }

            if(cells[best_move_for_computer.line-1-i]
                    [best_move_for_computer.column+1+i]==computer_icon)
            {       
                cells[best_move_for_computer.line]
                     [best_move_for_computer.column]=computer_icon;
            
                while(temp_i<i)
                {
                    cells[best_move_for_computer.line-1-temp_i]
                         [best_move_for_computer.column+1+temp_i]=computer_icon;
                    ++temp_i;
                }
            }

        }
    }
    
    else
    {
        cout << "\nThe computer does not have a legal move";
        *computer_can_move=0;
    }
}