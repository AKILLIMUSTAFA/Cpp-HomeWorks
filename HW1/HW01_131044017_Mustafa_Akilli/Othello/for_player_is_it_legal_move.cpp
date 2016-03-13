// HW01_131044017_Mustafa_AKILLI
// for_player_is_it_legal_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
//  Playerin hareketinin uygunlugunu kontrol eden
//  nokta olan yerlerin cevresi taranir ve legal olup olmadigi kontrol edilir
//  Legal bir hamle ise uygulanilir.

#include "othello_header.h"

int for_player_is_it_legal_move(int size_of_board, char cells[21][21], 
               int column_number, int move_player_cells_number)
{
    int check_legal=1; //EGER 1 RETURN EDILIRSE LEGAL HAMLEDIR
                       //EGER 0 RETURN EDILIRSE LEGAL OLMAYAN HAMLEDIR
    
    int check_character=1;//SUTUN DEGERININ SAYI KARSILIGINI BULMADA
                          //KONTROL AMACLI OLUSTURULMUS DEGISKEN
    char character='a';
    
    char computer_icon='x';
    char player_icon='o';
    
    int kuzey=0, bati=0, dogu=0, guney=0;
    int kuzeybati=0, guneybati=0, guneydogu=0, kuzeydogu=0;
    
    int i=1, temp_i=0;
    
    //GIRILEN HAMLENIN CEVRESI KONTROL EDILIR
    
    //KUZEY
    if(cells[move_player_cells_number-1][column_number]==computer_icon)
        kuzey=1;
    
    //KUZEYBATI
    if(cells[move_player_cells_number-1][column_number-1]==computer_icon)
        kuzeybati=1;
        
    //BATI
    if(cells[move_player_cells_number][column_number-1]==computer_icon)
        bati=1;
        
    //GUNEYBATI
    if(cells[move_player_cells_number+1][column_number-1]==computer_icon)
        guneybati=1;
        
    //GUNEY
    if(cells[move_player_cells_number+1][column_number]==computer_icon)
        guney=1;
        
    //GUNEYDOGU
    if(cells[move_player_cells_number+1][column_number+1]==computer_icon)
        guneydogu=1;
        
    //DOGU
    if(cells[move_player_cells_number][column_number+1]==computer_icon)
        dogu=1;
        
    //KUZEYDOGU
    if(cells[move_player_cells_number-1][column_number+1]==computer_icon)
        kuzeydogu=1;
    
    //CEVRESINDE COMPUTER ICONU OLANLARDA ILERLENIR
    //EGER SONUNDA KENDINDEN OLAN ICONA RASTLANIRSA
    //HAMLE LEGAL BIR HAMLEDIR
    //KUZEY
    if(kuzey)
    {     
        while(cells[move_player_cells_number-1-i][column_number]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number-1-i][column_number]==player_icon)
        {       
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number-1-temp_i][column_number]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0;
    
    //KUZEYBATI
    if(kuzeybati)
    {
        while(cells[move_player_cells_number-1-i][column_number-1-i]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number-1-i][column_number-1-i]==player_icon)
        {       
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number-1-temp_i][column_number-1-temp_i]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0;
    
    //BATI
    if(bati)
    {
        while(cells[move_player_cells_number][column_number-1-i]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number][column_number-1-i]==player_icon)
        {       
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number][column_number-1-temp_i]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0;
    
    //GUNEYBATI
    if(guneybati)
    {
        while(cells[move_player_cells_number+1+i][column_number-1-i]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number+1+i][column_number-1-i]==player_icon)
        {       
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number+1+temp_i][column_number-1-temp_i]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0;
    
    //GUNEY
    if(guney)
    {
        while(cells[move_player_cells_number+1+i][column_number]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number+1+i][column_number]==player_icon)
        {       
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number+1+temp_i][column_number]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0;
    
    //GUNEYDOGU
    if(guneydogu)
    {
        while(cells[move_player_cells_number+1+i][column_number+1+i]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number+1+i][column_number+1+i]==player_icon)
        {       
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number+1+temp_i][column_number+1+temp_i]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0;
    
    //DOGU
    if(dogu)
    {
        while(cells[move_player_cells_number][column_number+1+i]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number][column_number+1+i]==player_icon)
        {      
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number][column_number+1+temp_i]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0;
    
    //GKUZEYDOGU
    if(kuzeydogu)
    {
        while(cells[move_player_cells_number-1-i][column_number+1+i]==computer_icon)
        {
            ++i;
        }
        
        if(cells[move_player_cells_number-1-i][column_number+1+i]==player_icon)
        {       
            cells[move_player_cells_number][column_number]=player_icon;
            
            while(temp_i<i)
            {
                cells[move_player_cells_number-1-temp_i][column_number+1+temp_i]=player_icon;
                ++temp_i;
            }
            
            check_legal=0;
        }
    
    }

    return check_legal;
}