// HW01_131044017_Mustafa_AKILLI
// othello_header.h
//
// Created on 22 Eylül 2015 Salı, 17:13 by Mustafa_AKILLI
//
// Description
//
// This is othello game.
//
// The othello_header.h contains struct move_feature_t which move feature of
// player and computer


#ifndef OTHELLO_HEADER_H
#define	OTHELLO_HEADER_H

#include <cstdlib>
#include <iostream>

using namespace std;

//HAMLELER ICIN STRUCT**********************************************************
//
//
typedef struct{

    int legal; //Hareket legal mi degil mi
    int total_gain; //Toplam kazanc miktari
    int column; //Hamlenin sutun numarasi
    int line; //Hamlenin satir numarasi
    int kuzey;//KUZEY
    int kuzeybati;//KUZEYBATI
    int bati;//BATI
    int guneybati;//GUNEYBATI
    int guney;//GUNEY
    int guneydogu;//GUNEYDOGU
    int dogu;//DOGU
    int kuzeydogu;//KUZEYDOGU

}move_feature_t;
//
//
//HAMLELER ICIN STRUCT**********************************************************



//FOR OTHERS********************************************************************
//
//
//Gecerli bir size of board degeri girilene kadar,
//kullanicidan size of board degeri istenir.
int board_size();

//Hucrelerin oyun basi degerleri verilir
void first_view(int size_of_board, char cells[21][21]);

//Guncel board ekrana cizilir.
void paint_board(int size_of_board, char cells[21][21]);

//Skor Yazılır
void scoreboard(int size_of_board, char cells[21][21]);
//
//
//FOR OTHERS********************************************************************


//DOES PLAYER HAVE MOVE*********************************************************
//
//
//Player yapacak hamleye sahip mi degil mi
int does_player_have_move(int size_of_board, char cells[21][21]);

//Struct degerleri sifirlanir
void does_player_have_move_reset_structs(int size_of_board, 
                                        move_feature_t test[401]);

//Player'a ait olan iconlar bulunur
void does_player_have_move_which_ones_is_player_icon(int size_of_board, 
        char cells[21][21], move_feature_t test[401], int *number_of_player_move);

//Player'a ait olan hucrelerin cevreleri kontrol edilir
//cevresinde computer iconları olanlar secilir
void does_player_have_move_which_ones_has_computer_icon_on_around(
        char cells[21][21], move_feature_t test[401], int number_of_player_move);

//computer iconu bittikten sonra sonunda nokta (empty) iconu olanlar varsa
//player hamle yapabilir anlamına gelmektedir
void does_player_have_move_is_it_legal_move(char cells[21][21], 
        move_feature_t test[401], int number_of_player_move, int *can_move);
//
//
//DOES PLAYER HAVE MOVE*********************************************************




//FOR PLAYER********************************************************************
//
//
//Player Hareketi
int for_player_move(int size_of_board, char cells[21][21]);

//Playerdan mantıklı hamle alan fonksiyon
//Nokta olan yerler kabul edilir
int for_player_is_it_empty_icon(int size_of_board, char cells[21][21],
        int *move_player_cells_number, char *move_player_cells_character);

//Playerin hareketinin uygunlugunu kontrol eden
//nokta olan yerlerin cevresi taranir ve legal olup olmadigi kontrol edilir
//Legal bir hamle ise uygulanilir.
int for_player_is_it_legal_move(int size_of_board, char cells[21][21], 
               int column_number, int move_player_cells_number);
//
//
//FOR PLAYER********************************************************************






//FOR COMPUTER******************************************************************
//
//
//Computer Hareketi
void for_computer_move(int size_of_board, char cells[21][21],
                        int *computer_can_move);

//Struct degerleri sifirlanir
void for_computer_reset_structs(int size_of_board,
                                move_feature_t move_of_computer[401],
                                move_feature_t *best_move_for_computer);

//Hangi hucrelerın bos oldugu bulunur.
void for_computer_which_ones_is_empty_icon(int size_of_board, char cells[21][21],
            move_feature_t move_of_computer[401],
            int *number_of_computer_move);

//Bos olan hucrelerin cevreleri kontrol edilir
//cevresinde player iconlari olanlar secilir
void for_computer_which_ones_has_player_icon_on_around(char cells[21][21],
            move_feature_t move_of_computer[401], 
            int number_of_computer_move);

//Player iconu bittikten sonra sonunda computer iconu olanlar secilir
void for_computer_is_it_legal_move(char cells[21][21],
            move_feature_t move_of_computer[401], 
            int number_of_computer_move);

//En akilli hareket bulunur
void for_computer_which_one_is_smartest_move(move_feature_t move_of_computer[401],
            int number_of_computer_move, 
            move_feature_t *best_move_for_computer,int size_of_board);

//En akilli hareket uygulanilir
void for_computer_do_best_move(char cells[21][21],
            move_feature_t best_move_for_computer,
            int *computer_can_move);
//
//
//FOR COMPUTER******************************************************************

#endif	/* OTHELLO_HEADER_H */