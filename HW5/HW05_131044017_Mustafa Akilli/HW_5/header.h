// HW05_131044017_Mustafa_Akilli
// 
//
// Created on 04 Kasim 2015 Carsamba, 10:57 by Mustafa_Akilli
//
// Description
//
// Reversi Game

#ifndef HEADER_H
#define	HEADER_H

#include <iostream>

#include <cstdlib>
#include <vector>

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


class Cell
{
public:
    //Constructors
    Cell(int newX, int newY, char newSembol);
    Cell();
    
    //Getters (Accessors)
    int getX() const{return X;} //return X
    int getY() const{return Y;} //return T
    char getSembol() const{return cellSembol;} // return cellSembol
    
    //Setters (Mutators)
    void setX(const int &newX) {X=newX;} // Set X
    void setY(const int &newY) {Y=newY;} // Set Y
    void setSembol(const int &newSembolNumber); // Set cellSembol
                                           // 0 girilirse empty_sembol
                                           // 1 girilirse player_sembol
                                           // 2 girilirse computer_sembol
    void setSembol(const char &newSembol){cellSembol=newSembol;} // Set Sembol
    
    
    
    //OPERATOR OVERLOADING******************************************************
    //
    //
    //One Cell object is smaller than the other if the Y components is smaller. 
    //If Y components are equal, then check the X component.
    friend bool operator <(const Cell& firstCell, const Cell& secondCell);
    
    //One Cell object is bigger than the other if the Y components is bigger. 
    //If Y components are equal, then check the X component.
    friend bool operator >(const Cell& firstCell, const Cell& secondCell);
    
    //One Cell object is  equal or bigger than the other if the Y components 
    //is equal or bigger.
    friend bool operator >=(const Cell& firstCell, const Cell& secondCell);
    
    //One Cell object is equal or smaller than the other if the Y components 
    //is equal or smaller.
    friend bool operator <=(const Cell& firstCell, const Cell& secondCell);
    
    //One Cell object is equal the other if the Y components is equal.
    friend bool operator ==(const Cell& firstCell, const Cell& secondCell);
    
    //One Cell object is not equal the other if the Y components is not equal.
    friend bool operator !=(const Cell& firstCell, const Cell& secondCell);
    
    //Operators ++ that increment the X and Y components by one Prefix version
    Cell operator++( );
    
    //Operators ++ that increment the X and Y components by one Postfix version
    Cell operator++(int ignoreMe);
    
    //Operators -- that decrement the X and Y components by one Prefix version
    Cell operator--( );
    
    //Operators -- that decrement the X and Y components by one Postfix version
    Cell operator--(int ignoreMe);
    
    //Stream insertion operators
    friend ostream& operator <<(ostream& outputStream, const Cell &simple);
    
    //Stream extraction operators
    friend istream& operator >>(istream& inputStream, Cell &simple);
    //
    //
    //OPERATOR OVERLOADING******************************************************

    
    
private:
    int X; // row number
    int Y; // column number
    char cellSembol; // cellSembol
    
    const static char empty_sembol='.'; // empty cell icon
    const static char player_sembol='o'; // player cell icon
    const static char computer_sembol='x'; // computer cell icon
};






class Reversi
{
public:
    //Constructors
    Reversi(int newBoardWidth, int newBoardHeight);
    Reversi(int newBoardSize);
    Reversi();
    
    //A function that read from files
    bool readFromFile();
    
    //A function that write from files.
    bool writeFromFile() const;
    
    
    //Getters (Accessors)
    int getBoardHeight() const{return boardHeight;} //return current Height
    int getBoardWidth() const{return boardWidth;} //return current Width
    
    //A function that displays the current board on the screen
    void displayBoard () const;
    
    //A function that plays the computer move
    void playComputer();
    
    //A function that plays the player move
    void playPlayer(int &cellPositionX, string &cellPositionYString); 
    
    //A function that returns if the game ended
    int endGame() const;
    
    //This function plays the game by asking the user the board size first 
    //then asks the user to play and the computer plays, etc.
    void playGame();
    
    //A static function that returns the number of living cells in all the games
    static int getLivingCellsNumber(){return liveCellsNumber;}
    
    // A function that takes another object Reversi as parameter and
    // compares the reversi games. 
    // It returns true is the first game is better for the user, 
    // otherwise it returns false.
    bool isFirstGameIsBetter(const Reversi &otherGameCells) const; 
    
    
    
    

    
    
    
    //ACCESORS
    
    // get GameCells
    vector< vector<Cell> > getGameCells() const{return gameCells;}
    // get GameCellsSize
    int getGameCellsSize() const {return gameCells.size();}
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
    
    
    
    
    
    
    //MATADORS
    
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
    void setLocalLiveCellsNumber(const char &sembol, const int &number);
    // set localLiveCellsNumber
    void setLocalLiveCellsNumber(const int &newLocalLiveCellsNumber) 
                                {localLiveCellsNumber=newLocalLiveCellsNumber;}
    //A static function that set the number of living cells in all the games
    static int setLivingCellsNumber(const char &sembol, const int &number);
    
    
    
    
    
    
    //FOR COMPUTER**************************************************************
    //
    //
    //Struct degerleri sifirlanir
    void forComputerResetStructs(move_feature_t moveOfcomputer[]);

    //Hangi hucrelerin bos oldugu bulunur.
    void forComputerWhichOnesIsEmptyIcon(move_feature_t moveOfcomputer[]);

    //Bos olan hucrelerin cevreleri kontrol edilir
    //cevresinde player iconlari olanlar secilir
    void forComputerWhichOnesHasPlayerIconOnAround(
                                               move_feature_t moveOfcomputer[]) const;

    //Player iconu bittikten sonra sonunda computer iconu olanlar secilir
    void forComputerIsItLegalMove(move_feature_t moveOfcomputer[]) const;

    //En akilli hareket bulunur
    void forComputerWhichOneIsSmartestMove(move_feature_t moveOfcomputer[]);

    //En akilli hareket uygulanilir
    void forComputerDoBestMove();
    //
    //
    //FOR COMPUTER**************************************************************
    
    
    
    
    
    
    
    
    
    
    //FOR PLAYER****************************************************************
    //
    //Playerdan mantikli hamle alan fonksiyon
    //Nokta olan yerler kabul edilir
    //Legal bir hamle ise 1 dondurur
    //Legal bir hamle degilse 0 dondurur.
    int forPlayerIsItEmptyIcon(const int &cellPositionX, 
                                    const int &cellPositionY) const;

    //Playerin hareketinin uygunlugunu kontrol eden
    //nokta olan yerlerin cevresi taranir ve legal olup olmadigi kontrol edilir
    //Legal bir hamle ise uygulanilir.
    //Legal bir hamle ise 1 dondurur
    //Legal bir hamle degilse 0 dondurur.
    int forPlayerIsItLegalMove(const int &cellPositionX, 
                                    const int &cellPositionY);
    //
    //
    //FOR PLAYER****************************************************************
    
    
    
    
    
    
    
    
    
    
    //DOES PLAYER HAVE MOVE*****************************************************
    //
    //
    //Player yapacak hamleye sahip mi degil mi
    int doesPlayerHaveMove();

    //Struct degerleri sifirlanir
    void doesPlayerHaveMoveResetStructs(move_feature_t playerMovetest[]) const;

    //Player'a ait olan iconlar bulunur
    void doesPlayerHaveMoveWhichOnesIsPlayerIcon(
                                            move_feature_t playerMovetest[]);

    //Player'a ait olan hucrelerin cevreleri kontrol edilir
    //cevresinde computer iconlari olanlar secilir
    void doesPlayerHaveMoveWhichOnesHasComputerIconOnAround(
                                            move_feature_t playerMovetest[]) const;

    //computer iconu bittikten sonra sonunda nokta (empty) iconu olanlar varsa
    //player hamle yapabilir anlamina gelmektedir
    void doesPlayerHaveMoveIsItLegalMove(
                                            move_feature_t playerMovetest[]);
    //
    //
    //DOES PLAYER HAVE MOVE*****************************************************
    
    
    
    
    
    
    
    
    //OTHER STAFF***************************************************************
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
    //OTHER STAFF***************************************************************
    
    
    
    
    
    
    
    
    
    

    //OPERATOR OVERLOADING******************************************************
    //
    //   
    //Operator ++ (Prefix version) will advance the game by one step for 
    //computer. 
    //It will return the expected results.
    Reversi operator++( );
    
    
    //Operator ++ (Postfix version) will advance the game by one step for 
    //computer. 
    //It will return the expected results.
    Reversi operator++(int ignoreMe);
    
    //Operator -- (Prefix version) will undo the game by one step for the last 4
    //play (user or computer). 
    //It will return the expected results. 
    //You can undo all the game moves back to the beginning of the game.
    Reversi operator--( );
    
    //Operator -- (Postfix version) will undo the game by one step for the last 4
    //play (user or computer). 
    //It will return the expected results. 
    //You can undo all the game moves back to the beginning of the game.
    Reversi operator--(int ignoreMe);
    
    //Overload the [] operator such that if g is a Reversi object, 
    //g[“A5”] will return the Cell at row 5 and column A. 
    //If there is no such Cells, 
    //then it will return a new Cell with position (-1000,-1000).
    Cell& operator [](string index);
    
    //Behaves exactly the same as []
    Cell& operator ()(string index);
    
    //that takes another a Cell object and plays the game for the user.
    Cell& operator +=(const Cell& move);
    
    //Stream insertion operators that prints the game on the screen
    friend ostream& operator <<(ostream& outputStream, const Reversi &simple);
    
    //
    //
    //OPERATOR OVERLOADING******************************************************
    
    
    
    
    
    
private:
    vector< vector<Cell> > gameCells;//Oyundaki butun hucreleri tutar.

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
    
    //SEMBOLS
    const static char empty_sembol='.'; // empty cell icon
    const static char player_sembol='o'; // player cell icon
    const static char computer_sembol='x'; // computer cell icon
    
    //FOR COMPUTER
    int computerCanMove;// Playerin hamlesinin olup olmadigini tutan degisken
                        // 1 ise hamle vardir.
                        // 0 ise hamle yoktur.
    int numberOfComputerMove;// Computer in yapabilecegi hamle sayisi
    move_feature_t bestMoveForComputer; // computer icin en iyi hamlenin
                                        // struct degerini tutan degisken
    int computerScore; // Playerin skoru
    
    int firstTime;//oyun ilk defa calistiginda 1 olur, sonra 0.
    
    Cell garbage;//For []
};







#endif	/* HEADER_H */

