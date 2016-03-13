// HW06_131044017_Mustafa_Akilli
// 
// File:   reversi.h
// Author: Mustafa_Akilli
//
// Created on 01 Aralik 2015 Sali, 12:03 by Mustafa_Akilli
//
// Description
//
// Reversi Game in Dynamic Array
//
// HW6 reversi class

#ifndef REVERSI_H
#define	REVERSI_H


#include "cell.h"
#include <string>


using std::string;
using std::ostream;


namespace mustafaAkilli
{
    //HAMLELER ICIN STRUCT******************************************************
    //
    //
    struct move_feature_t{

    int legal; //hamle legal mi degil mi
    int total_gain; //Toplam kazanc miktari
    int line; //Hamlenin satir numarasi
    int column; //Hamlenin sutun numarasi
    int kuzey;//KUZEY
    int kuzeybati;//KUZEYBATI
    int bati;//BATI
    int guneybati;//GUNEYBATI
    int guney;//GUNEY
    int guneydogu;//GUNEYDOGU
    int dogu;//DOGU
    int kuzeydogu;//KUZEYDOGU
    };
    //
    //
    //HAMLELER ICIN STRUCT******************************************************
    
    class Reversi
    {
    public:
        //Constructors
        Reversi(const int &newBoardWidth, const int &newBoardHeight);
        Reversi(const int &newBoardSize);
        Reversi();
        
        //Copy Constructor
        Reversi(const Reversi &otherGame);

        //Getters (Accessors)
        int getBoardHeight() const{return boardHeight;} //return current Height
        int getBoardWidth() const{return boardWidth;} //return current Width
        
        //A functions that resize the board.
        //When the board is resized, the game starts from the beginning.
        void resizeBoard(int newBoardWidth, int newBoardHeight);

        //A function that displays the current board on the screen
        void displayBoard () const;

        //A function that plays the computer move
        void playComputer();

        //A function that plays the player move
        void playPlayer(int &cellPositionX, string &cellPositionYString); 

        //A function that returns if the game ended
        bool endGame() const;

        //This function plays the game by asking the user the board size first 
        //then asks the user to play and the computer plays, etc.
        void playGame();

        //A static function that returns the number of living cells 
        //in all the games
        static int getLivingCellsNumber(){return liveCellsNumber;}

        // A function that takes another object Reversi as parameter and
        // compares the reversi games. 
        // It returns true is the first game is better for the user, 
        // otherwise it returns false.
        bool isFirstGameIsBetter(const Reversi &otherGameCells) const; 
        
        //Operator ++ (Prefix version) will advance the game by one step for 
        //computer. 
        //It will return the expected results.
        Reversi operator++( );
        
        //Operator ++ (Postfix version) will advance the game by one step for 
        //computer. 
        //It will return the expected results.
        Reversi operator++(int ignoreMe);
        
        //Stream insertion operators that prints the game on the screen
        friend ostream& operator <<(ostream& outputStream, const Reversi &simple);
        
        
        
        
        
        //ACCESORS**************************************************************
        
        // get GameCells
        Cell& getGameCells() const{return *gameCells;}
        // get ComputerCanMove
        int getComputerCanMove() const {return computerCanMove;}
        // get PlayerCanMove
        int getPlayerCanMove() const {return playerCanMove;}
        // get PlayerScore
        int getPlayerScore() const {return playerScore;}
        // get ComputerScore
        int getComputerScore() const {return computerScore;}
        // get NumberOfPlayerMove
        int getNumberOfPlayerMove() const {return numberOfPlayerMove;}
        // get NumberOfComputerMove
        int getNumberOfComputerMove() const {return numberOfComputerMove;}
        // get firstTime
        int getFirstTime() const {return firstTime;}
        // get localLiveCellsNumber
        int getLocalLiveCellsNumber() const {return localLiveCellsNumber;}
        
        
        
        
        
        
        //MATADORS**************************************************************
        
        // set GameCells
        void setGameCells(); // Oyun basi gamecell doldurulur.
        // set boardHeight
        void setboardHeight(const int &newBoardHeight);// Board in yuksekligi(Y)
        // set boardWidth
        void setboardWidth(const int &newBoardWidth);// Board in genisligi(X)
        // set ComputerCanMove
        void setComputerCanMove(const int &oneOrZero) {computerCanMove=oneOrZero;}
        // set PlayerCanMove
        void setPlayerCanMove(const int &oneOrZero) {playerCanMove=oneOrZero;}
        // set PlayerScore
        void setPlayerScore(const int &newPlayerScore) {playerScore=newPlayerScore;}
        // set ComputerScore
        void setComputerScore(const int &newCompScore) {computerScore=newCompScore;}
        // set NumberOfPlayerMove
        void setNumberOfPlayerMove(const int &newNum){numberOfPlayerMove=newNum;}
        // set NumberOfComputerMove
        void setNumberOfComputerMove(const int &newNum){numberOfComputerMove=newNum;}
        // set firstTime
        void setFirstTime(const int &newFirstTime){firstTime=newFirstTime;}
        // set localLiveCellsNumber
        void setLocalLiveCellsNumber(const int &newLocalLiveCellsNumber) 
                                {localLiveCellsNumber=newLocalLiveCellsNumber;}
        //A static function that set the number of living cells in all the games
        static void setLivingCellsNumber(const int &number)
                                                    {liveCellsNumber=number;}
         
        
        

        
        
        //FOR MOVES*************************************************************
        //
        //
        //MoveFeatureT tipindeki Struct Arrayin degerleri sifirlanir
        void ResetStructMoveFeatureTArray(move_feature_t structMoveFeatureTArray[], 
                                                                int size) const;
        
        //MoveFeatureT tipindeki Structin degerleri sifirlanir
        void ResetStructMoveFeatureT(move_feature_t &structMoveFeatureT) const;
        
        //Hangi hucrelerin verilen sembolde oldugu bulunur.
        void WhichOnesIsGivenSembol(move_feature_t structMoveFeatureTArray[],
                                    const char &Sembol,const int &whoIsMove);
        
        
        //Hangi hucrelerin verilen sembolde oldugu bulunur.
        void WhichOnesHasGivenSembolOnAround(move_feature_t structMoveFeatureTArray[],
            const char &Sembol, const int &whoIsMove) const;
        
        //Karsi tarafin sembolleri bittikten sonra sonunda hamleyi yapan
        //tarafin iconu var ise o hamle legal hamledir.
        void IsItLegalMove(move_feature_t structMoveFeatureTArray[],
            const char &moveSembol, const char &counterSembol, 
                                                    const int &whoIsMove) const;
        
        //En akilli hamle bulunur
        void forComputerWhichOneIsSmartestMove(move_feature_t moveOfcomputer[],
            move_feature_t &bestMoveForComputer) const;
        
        
        //Computerin yaptigi hamle ekrana yazilir
        void forComputerPrintTheMove(move_feature_t &bestMoveForComputer);
        
        
        //Hamle uygulanilir
        void DoMove(move_feature_t &structMoveFeatureT, const char &moveSembol, 
                            const char &counterSembol, const int &whoIsMove);
        
        //Player yapacak hamleye sahip mi degil mi
        int doesPlayerHaveMove();
        
        //Playerin hamlesinin nokta olup olmadini dondurur
        bool forPlayerIsItEmptyIcon(const int &cellPositionX, 
                                        const int &cellPositionY) const;
        //
        //
        //FOR MOVES*************************************************************
        

        
        
        //OTHER STAFF***********************************************************
        //
        //
        //Girilen width ve height degerlerini kontrol amacli
        int checkBoardSizes(int boardWidthorHeight) const;

        //SAYIYI HARFE CEVIRIR
        char digitTranslateLetter(const int &digit) const;

        //HARFI SAYIYA CEVIRIR
        int letterTranslateDigit (const char &letter) const;

        //STRINGI SAYIYA CEVIRIR
        int stringTranslateNumber (string &cellPositionYString) const;

        //SCOREBOARD
        void scoreboard();
        //
        //
        //OTHER STAFF***********************************************************
        
        //Destructor
        ~Reversi();
        
    private:
        Cell * gameCells;//Oyundaki butun hucreleri tutar.
        
        //FOR BOARD
        int boardHeight;// Row Number Size
        int boardWidth; // Columb Number Size


        //FOR PLAYER
        int playerCanMove; // Playerin hamlesinin olup olmadigini tutan degisken
                           // 1 ise hamle vardir.
                           // 0 ise hamle yoktur.
        int numberOfPlayerMove;// Player in yapabilecegi hamle sayisi
        int playerScore; // Playerin skoru


        static int liveCellsNumber; //number of living cells in all the games
        int localLiveCellsNumber; //number of Local living cells in the game.


        //FOR COMPUTER
        int computerCanMove;// Playerin hamlesinin olup olmadigini tutan degisken
                            // 1 ise hamle vardir.
                            // 0 ise hamle yoktur.
        int numberOfComputerMove;// Computer in yapabilecegi hamle sayisi

        int computerScore; // Playerin skoru

        int firstTime;//oyun ilk defa calistiginda 1 olur, sonra 0.

        Cell garbage;//For []
    
    };
}

#endif	/* REVERSI_H */