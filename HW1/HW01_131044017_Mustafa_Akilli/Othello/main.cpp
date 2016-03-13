// HW01_131044017_Mustafa_AKILLI
// main.cpp
//
// Created on 21 Eylül 2015 Pazartesi, 23:04 by Mustafa_AKILLI
//
// Description
//
// Main

#include "othello_header.h"

int main(int argc, char** argv) {

    int size_of_board; //BOARD'IN BUYUKLUGU
    char cells[21][21]; //CHAR TIPINDE 2D ARRAY
    int check_player_move=1; // PLAYERIN ANLAMLI HAREKETINI KONTROL
    int player_can_move=1;//Playerin hamlesinin olup olmadigi kontrol edilir
    int computer_can_move=1;//Computerin hamlesinin olup olmadigi kontrol edilir
    
    //Gecerli bir size of board degeri girilene kadar,
    //kullanicidan size of board degeri istenir.
    size_of_board=board_size();
    
    //Hucrelerin oyun basi degerleri verilir
    first_view(size_of_board, cells);
    
    //Guncel board ekrana cizilir.
    paint_board(size_of_board, cells);
    
    //Eger player veya computer hamle yapabiliyorsa 
    while(player_can_move==1 || computer_can_move==1)
    {
        computer_can_move=1;
        
        //Player yapacak hamleye sahip mi degil mi
        player_can_move=does_player_have_move(size_of_board, cells);
        
        //Eger Player Hamle yapabiliyorsa
        if(player_can_move)  
        {
            while(check_player_move)
            {
                //Player Hareketi
                //Legal bir hareket girilene kadar donguden cikmaz
                check_player_move=for_player_move(size_of_board, cells);              
            }
            check_player_move=1;
        
            //Guncel board ekrana cizilir.
            paint_board(size_of_board, cells);
        }
        
        //Computer Hareketi
        for_computer_move(size_of_board, cells, &computer_can_move);
    
        //Guncel board ekrana cizilir.
        paint_board(size_of_board, cells);
        
        cout <<"\n";
    }
    
    //Skor Yazilir
    scoreboard(size_of_board, cells);
    
    return 0;
}