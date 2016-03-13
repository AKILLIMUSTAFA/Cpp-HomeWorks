// HW01_131044017_Mustafa_AKILLI
// does_player_have_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Player yapacak hamleye sahip mi degil mi

#include "othello_header.h"

int does_player_have_move(int size_of_board, char cells[21][21])
{
    int can_move=0;
    int number_of_player_move=0;
    move_feature_t test[401];
    
    //Struct degerleri sifirlanir
    does_player_have_move_reset_structs(size_of_board, test);
    
    //Player'a ait olan iconlar bulunur
    does_player_have_move_which_ones_is_player_icon(size_of_board, cells, 
            test, &number_of_player_move);
    
    //Player'a ait olan hucrelerin cevreleri kontrol edilir
    //cevresinde computer iconları olanlar secilir
    does_player_have_move_which_ones_has_computer_icon_on_around(cells, 
            test, number_of_player_move);
    
    
    //computer iconu bittikten sonra sonunda nokta empty iconu olanlar varsa
    //player hamle yapabilir anlamına gelmektedir
    does_player_have_move_is_it_legal_move(cells, test, number_of_player_move, 
            &can_move);
    
    //Eger player yapilabilir bir hamleye sahip ise 1
    //sahip degil ise 0 return edilir.
    return can_move;
}