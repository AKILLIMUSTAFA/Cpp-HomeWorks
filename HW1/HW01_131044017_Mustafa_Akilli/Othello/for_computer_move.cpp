// HW01_131044017_Mustafa_AKILLI
// for_computer_move.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Computer Hareketi

#include "othello_header.h"

void for_computer_move(int size_of_board, char cells[21][21],int *computer_can_move)
{
    move_feature_t move_of_computer[401];
    move_feature_t best_move_for_computer;
    int number_of_computer_move=0;
    
    //Struct degerleri sifirlanir
    for_computer_reset_structs(size_of_board, move_of_computer, &best_move_for_computer);
    
    //Hangi hucrelerın bos oldugu bulunur.
    for_computer_which_ones_is_empty_icon(size_of_board, cells, move_of_computer, 
             &number_of_computer_move);
    
    //Bos olan hucrelerin cevreleri kontrol edilir
    //cevresinde player iconları olanlar secilir
    for_computer_which_ones_has_player_icon_on_around(cells, move_of_computer, 
            number_of_computer_move);
    
    //Player iconu bittikten sonra sonunda computer iconu olanlar secilir
    for_computer_is_it_legal_move(cells, move_of_computer, number_of_computer_move);
    
    //En akilli hareket bulunur
    for_computer_which_one_is_smartest_move(move_of_computer,number_of_computer_move,
                                &best_move_for_computer, size_of_board);
    
    //En akilli hareket uygulanilir
    for_computer_do_best_move(cells, best_move_for_computer, computer_can_move);
    
    cout << "\n\n";   
}