// HW01_131044017_Mustafa_AKILLI
// for_player_is_it_empty_icon.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Playerdan mantıklı hamle alan fonksiyon
// Nokta olan yerler kabul edilir

#include "othello_header.h"
#include<limits>

int for_player_is_it_empty_icon(int size_of_board, char cells[21][21],
        int *move_player_cells_number, char *move_player_cells_character)
{
    char empty_icon='.', character='a';
    int column_number=0;//SUTUN DEGERININ SAYI KARSILIGI
    int check_character=1;//SUTUN DEGERININ SAYI KARSILIGINI BULMADA
                          //KONTROL AMACLI OLUSTURULMUS DEGISKEN

    cout << "\nGive your move: ";
    cin >> *move_player_cells_number;
    cin >> *move_player_cells_character;
    
    //SUTUN DEGERININ SAYI KARSILIGININ BULUNMASI
    while(check_character)
    {
        if(*move_player_cells_character==(character+column_number))
            check_character=0;
        
        else
            ++column_number;
    }
    
    ++column_number;
    
    //EGER LEGAL OLMAYAN DEGER GIRILIRSE
    while(*move_player_cells_number<1 || 
          *move_player_cells_number>size_of_board ||
          *move_player_cells_character<character ||
          *move_player_cells_character>(character+size_of_board-1) ||
          cells[*move_player_cells_number][column_number]!=empty_icon)
    {  
        column_number=0;//SUTUN DEGERI SIFIRLANIR
        check_character=1;
        
        //UYARI VERILIR
        cout << "Invalid Input\n"
             << "Give your move: ";  
        
        //DEGER TEMIZLENIR VE TEKRAR ALINIR
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> *move_player_cells_number;
        cin >> *move_player_cells_character;
        
        //SUTUN DEGERININ SAYI KARSILIGININ BULUNMASI
        while(check_character)
        {
            if(*move_player_cells_character==(character+column_number))
                check_character=0;
        
            else
                ++column_number;
        }
    
        ++column_number;
    }
    
    return column_number;
}