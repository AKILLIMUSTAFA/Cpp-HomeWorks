// HW06_131044017_Mustafa_Akilli
// 
// File:   cell.h
// Author: Mustafa_Akilli
//
// Created on 01 Aralik 2015 Sali, 12:04 by Mustafa_Akilli
//
// Description
//
// Reversi Game in Dynamic Array
//
// HW6 cell class

#ifndef CELL_H
#define	CELL_H


namespace mustafaAkilli
{
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

    private:
        int X; // row number
        int Y; // column number
        char cellSembol; // cellSembol
    };


}


#endif	/* CELL_H */

