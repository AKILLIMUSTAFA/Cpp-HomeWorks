// HW01_131044017_Mustafa_AKILLI
// for_player_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Player Hareketi

#include "othello_header.h"
#include<limits>

int for_player_move(int size_of_board, char cells[21][21])
{
    int column_number;//
    int check_player_move;
    int move_player_cells_number;// SATIR DEGERI
    char move_player_cells_character;// SUTUN DEGERI
    
    //Playerdan mantıklı hamle alan fonksiyon
    //Nokta olan yerler kabul edilir
    column_number=for_player_is_it_empty_icon(size_of_board,cells,
        &move_player_cells_number, &move_player_cells_character);
    
    //Playerin hareketinin uygunlugunu kontrol eden
    //nokta olan yerlerin cevresi taranir ve legal olup olmadigi kontrol edilir
    //Legal bir hamle ise uygulanilir.
    check_player_move=for_player_is_it_legal_move(size_of_board, cells,
           column_number,move_player_cells_number);

    //Girilen deger legal degilse
    if(check_player_move)
        cout << "\nInvalid Input";
    
    return check_player_move;
}