// HW06_131044017_Mustafa_Akilli
// 
// File:   reversi.cpp
// Author: Mustafa_Akilli
//
// Created on 01 Aralik 2015 Sali, 12:08 by Mustafa_Akilli
//
// Description
//
// Reversi Game in Dynamic Array
//
// HW6 reversi class implementation

#include <iostream>
#include <limits>
#include "reversi.h"
#include <cstdlib>
#include <vector>


using namespace std;


namespace
{  
    const static int EMPTY_SEMBOL_NUMBER=0;
    const static int PLAYER_SEMBOL_NUMBER=1;
    const static int COMPUTER_SEMBOL_NUMBER=2;
    
    //SEMBOLS
    const static char EMPTY_SEMBOL='.'; // empty cell icon
    const static char PLAYER_SEMBOL='o'; // player cell icon
    const static char COMPUTER_SEMBOL='x'; // computer cell icon
    
    const static int NEGATIF_ONE=-1; // -1
    const static int ZERO=0; // 0
    const static int ONE=1; // 1
    const static int TWO=2; // 2
    const static int THREE=3; // 3
    const static int FOUR=4; // 4
    const static int FIVE=5; // 5
    const static int SIX=6; // 6
    const static int SEVEN=7; // 7
    const static int EIGHT=8; // 8
    const static int NINE=9; // 9
    const static int TEN=10; // 10
    
    const static int DEFAULT_WIDTH=10; // DEFAULT_WIDTH
    const static int DEFAULT_HEIGHT=10; // DEFAULT_HEIGHT
    const static int ACTIVE=1; // ACTIVE
    const static int PASSIVE=0; // PASSIVE
    
    const static int ONE_LIVING_CELLS=1; // one living cell
    const static int TWO_LIVING_CELLS=2; // two living cell
    const static int FOUR_LIVING_CELLS=4; // four living cell
    
    const static int ONE_SCORE=1; // one score
    const static int TWO_SCORE=2; // two score
    
    const static int PLAYER_MOVE=1;
    const static int COMPUTER_MOVE=2;
    
    
    
}


namespace mustafaAkilli
{
    //Constructors**************************************************************
    Reversi::Reversi(const int &newBoardWidth, const int &newBoardHeight)
    {
        checkBoardSizes(newBoardHeight);
        checkBoardSizes(newBoardWidth);
        setboardHeight(newBoardHeight);
        setboardWidth(newBoardWidth);
        setComputerCanMove(ACTIVE);
        setPlayerCanMove(ACTIVE);
        setFirstTime(ACTIVE);
        setLocalLiveCellsNumber(ZERO);
        setGameCells();
    }
     
    Reversi::Reversi(const int &newBoardSize)
    {
        checkBoardSizes(newBoardSize);
        setboardHeight(newBoardSize);
        setboardWidth(newBoardSize);
        setComputerCanMove(ACTIVE);
        setPlayerCanMove(ACTIVE);
        setFirstTime(ACTIVE);
        setLocalLiveCellsNumber(ZERO);
        setGameCells();
    }
    
    
    Reversi::Reversi()
    {
        setboardHeight(DEFAULT_HEIGHT);
        setboardWidth(DEFAULT_WIDTH);
        setComputerCanMove(ACTIVE);
        setPlayerCanMove(ACTIVE);
        setFirstTime(ACTIVE);
        setLocalLiveCellsNumber(ZERO);
        setGameCells();
    }
    
    //Copy Constructor
    Reversi::Reversi(const Reversi &otherGame)
    {
        setboardHeight(otherGame.getBoardHeight());
        setboardWidth(otherGame.getBoardWidth());
        setLocalLiveCellsNumber(otherGame.getLocalLiveCellsNumber());
        setLivingCellsNumber(otherGame.getLivingCellsNumber()
                                        +otherGame.getLocalLiveCellsNumber());
        
        Cell*  newGameCells = new Cell[getBoardHeight()*getBoardWidth()]; 
        
        for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
           newGameCells[i]=otherGame.gameCells[i];
        
        gameCells=newGameCells;
    }
    
    
    
    //A functions that resize the board.
    //When the board is resized, the game starts from the beginning.
    void Reversi::resizeBoard(int newBoardWidth, int newBoardHeight)
    {
        delete [] gameCells;
        setboardHeight(newBoardHeight);
        setboardWidth(newBoardWidth);
        setComputerCanMove(ACTIVE);
        setPlayerCanMove(ACTIVE);
        setFirstTime(ACTIVE);
        setLivingCellsNumber(getLivingCellsNumber()-getLocalLiveCellsNumber());
        setGameCells();
    }
    
    //A function that displays the current board on the screen
    void Reversi::displayBoard () const
    {
        
        //A 1'i temsil ediyor
        //B 2'yi temsil ediyor
        //....................
        //....................
        //I 9'u temsil ediyor
        //J ise 0'i temsil ediyor
        //ornegin: AJE 105'e esit.
        //ornegin: CD 34'e esit.
        int columbNumberDigits=ZERO; // columb number sayisinin basamak 
                                  // sayisini tutan degisken
        int rowNumberDigits=ZERO; //  row number sayisinin basamak 
                                      // sayisini tutan degisk.
        int tempRowNumber=getBoardHeight(); //row sayisinin degerinde gecici degisk.
        int tempColumbNumber=getBoardWidth(); //row sayisinin degerinde gecici deg.
        int checkRowNumber; //yazilan row sayilarinin digit degerini check eden deg.
        int controlRowNumber=ZERO;//son yazilan row sayisinin digit sayisini tutan deg. 
        int digitRowNumber=NEGATIF_ONE; //yazilan row number sayisinin digit sayisi
        int digitColumbNumber=ZERO; //yazilan columb number sayisinin digit sayisi

        //boardWidth (columb) sayisinin kac basamak oldugu bulunur.
        while (tempColumbNumber) {
            tempColumbNumber /= TEN;
            ++columbNumberDigits;
        }
        

        // boardHeight (row) sayisinin kac basamak oldugu bulunur.
        while (tempRowNumber) {
            tempRowNumber /= TEN;
            ++rowNumberDigits;
        }

        cout << endl;

        //sol ust kosede bosluk birakilir
        for(int i=ZERO; i<=rowNumberDigits ;++i)
            cout << " ";


        vector<char> digitToLetter;// sayilarin basamaklarinin harf karsiligini 
                                 // tutan vector
        char letter; // harfleri tutan degisken
        int number; // for dongusundeki i degerini tutan gecici degisken
        int totalDigitsNumber; //numberin digit sayisini tutan degisken
        int digit; // rakamlari tutan degisken

        //Ilk satira harfler yazilir
        for(int i=ONE; i<=getBoardWidth() ;++i)
        {
            number=i; // i  number' a atanir
            totalDigitsNumber=ZERO; // totalDigitsNumber sifirlanir


            while(number)
            {
                digit=number%TEN; //sayinin son basamagi bulunur.
                number=number/TEN; //sayi 10 a bolunur.
                letter=digitTranslateLetter(digit); // basamagin harf karsiligi
                                                    // bulunur.
                digitToLetter.push_back(letter); // vektore bulunan harf eklenir.
                ++totalDigitsNumber; // Sayinin kac basamakli oldugu bulunur.
            }

            //Sayinin harf karsiligi yazilir
            for(int j=totalDigitsNumber-ONE; j>=ZERO ; --j)
                cout << digitToLetter[j];

            //vector sifirlanir
            digitToLetter.clear();


            //Harfler yerlestirildikten sonra sonraki bosluk birakilir
            for(int t=totalDigitsNumber-ONE; t<columbNumberDigits; ++t)
                        cout << " ";
        }

        //Row numbers and Sembols
        cout << endl;
        for(int i=ZERO; i<getBoardWidth()*getBoardHeight() ;++i)
        {
            number=gameCells[i].getX(); // i  number' a atanir

            // Sayinin kac basamakli oldugu bulunur.
            while (number) {
                number /= TEN;
                ++digitRowNumber;
            }

            //Basamak sayisi arttikca yazilan bosluk sayisini azaltma amacli
            if(digitRowNumber > controlRowNumber)
            {
                --rowNumberDigits;
                ++controlRowNumber;
            }

            //sifirlanir
            digitRowNumber=NEGATIF_ONE;

            //bosluklar ve semboller ekrana basilir
            cout << gameCells[i].getX();
            for(int space=ZERO; space<rowNumberDigits; ++space)
                cout << " ";

            for(int j=ZERO; j<getBoardWidth() ;++j)
            {
                cout << gameCells[i].getSembol();
                for(int t=ZERO; t<columbNumberDigits; ++t)
                    cout << " ";
                ++i;
            }
            --i;
            
            cout << endl;
        }
        cout << endl;  
    }
    
    //A function that plays the computer move
    void Reversi::playComputer()
    {  
        move_feature_t moveOfcomputer[getBoardHeight()*getBoardWidth()+ONE];
        move_feature_t bestMoveForComputer; // computer icin en iyi hamlenin
                                        // struct degerini tutan degisken
        setNumberOfComputerMove(ZERO);
        
        //Struct degerleri sifirlanir
        ResetStructMoveFeatureTArray(moveOfcomputer, 
                                        getBoardHeight()*getBoardWidth()+ONE);
        ResetStructMoveFeatureT(bestMoveForComputer); 
        
        //Hangi hucrelerin bos oldugu bulunur.
        WhichOnesIsGivenSembol(moveOfcomputer,EMPTY_SEMBOL,COMPUTER_MOVE);

        //Bos olan hucrelerin cevreleri kontrol edilir
        //cevresinde player iconlari olanlar secilir
        WhichOnesHasGivenSembolOnAround(moveOfcomputer,PLAYER_SEMBOL,COMPUTER_MOVE);
        
        //Player iconu bittikten sonra sonunda computer iconu olanlar secilir
        IsItLegalMove(moveOfcomputer,COMPUTER_SEMBOL, PLAYER_SEMBOL, COMPUTER_MOVE);
         
        //En akilli hamle bulunur
        forComputerWhichOneIsSmartestMove(moveOfcomputer,bestMoveForComputer);
        
        //Computerin yaptigi hamle ekrana yazilir
        forComputerPrintTheMove(bestMoveForComputer);
        
        //En akilli hamle uygulanilir
        DoMove(bestMoveForComputer,COMPUTER_SEMBOL, PLAYER_SEMBOL, COMPUTER_MOVE);

        cout << endl << endl;
    }
    
    //A function that plays the player move
    void Reversi::playPlayer(int &cellPositionX, string &cellPositionYString)
    {
        //Girilen sutun harflerinin sayi karsiligi
        int cellPositionYNumber=stringTranslateNumber(cellPositionYString);
        int checkIsItLegalMove=ZERO;       
        
        while(!checkIsItLegalMove)
        {        
            //Cell empty icon ise 1 degilse 0 dondurur
            checkIsItLegalMove=forPlayerIsItEmptyIcon(cellPositionX, 
                                                        cellPositionYNumber); 

            if(checkIsItLegalMove)
            {                
                move_feature_t moveForPlayer[ONE];
                
                //Struct degerleri sifirlanir
                ResetStructMoveFeatureTArray(moveForPlayer, ONE);
                
                moveForPlayer[ZERO].line=cellPositionX;
                moveForPlayer[ZERO].column=cellPositionYNumber;
                 
                setNumberOfPlayerMove(ONE);

                //Hamlenin cevresinde computer iconlari olan yonler belirlenir
                WhichOnesHasGivenSembolOnAround(moveForPlayer,COMPUTER_SEMBOL,
                        PLAYER_MOVE);
                  
                
                //Computer iconu bittikten sonra sonunda player iconu olanlar secilir
                IsItLegalMove(moveForPlayer,PLAYER_SEMBOL, COMPUTER_SEMBOL, 
                        PLAYER_MOVE);

                //Hamle legal ise uygulanir
                if(moveForPlayer[ZERO].legal)
                {
                    DoMove(moveForPlayer[ZERO],PLAYER_SEMBOL, COMPUTER_SEMBOL, 
                            PLAYER_MOVE);    
                    checkIsItLegalMove=ONE;
                } 
                
                else
                    checkIsItLegalMove=ZERO;
            }

            if(!checkIsItLegalMove)
            {
                cout << endl << "Invalid Input\n"
                     << "Give your move: ";

                //DEGER TEMIZLENIR VE TEKRAR ALINIR
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> cellPositionX;
                cin >> cellPositionYString;

                cellPositionYNumber=stringTranslateNumber(cellPositionYString);
            }          
        }   
    
    }
    
    //A function that returns if the game ended
    bool Reversi::endGame() const
    {
        int result;
    
        if(getPlayerCanMove()==ZERO && getComputerCanMove()==ZERO)
            result=true;

        else
            result=false;

        return result;
    }
    
    //This function plays the game by asking the user the board size first 
    //then asks the user to play and the computer plays, etc.
    void Reversi::playGame()
    {
        int cellPositionX;
        string cellPositionYString;

        if(getFirstTime())
        {
            int sizeOfBoardX; // Kullanicidan alinan Board Yuksekligi
            int sizeOfBoardY; // Kullanicidan alinan Board Genisligi

            cout << "Enter Size of Board Width: ";

            cin >> sizeOfBoardX;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Size of Board Height: ";
            cin >> sizeOfBoardY;


            resizeBoard(sizeOfBoardX, sizeOfBoardY);
            setFirstTime(ZERO);
            
            //Guncel board ekrana cizilir.
            displayBoard();  
            
        }

        //Eger player veya computer hamle yapabiliyorsa oyun devam eder.
        if(!endGame())
        {
            setComputerCanMove(ACTIVE); //Computerin hamlesi aktif hale gelir.

            //Player yapacak hamleye sahip mi degil mi
            setPlayerCanMove(doesPlayerHaveMove());

            //Eger Player Hamle yapabiliyorsa
            if(getPlayerCanMove())  
            {
                cout << endl << "Give your move: ";

                //HAMLE ALINIR
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> cellPositionX;
                cin >> cellPositionYString;


                //A function that plays the player move
                playPlayer(cellPositionX, cellPositionYString);              

                //Guncel board ekrana cizilir.
                displayBoard();
            }

            else
                 cout << endl << "The player does not have a legal move";

            //Computer hamlesi
            playComputer();

            //Guncel board ekrana cizilir.
            displayBoard();

            cout << endl;

            scoreboard();
        }

        //Eger player veya computer hamle yapamiyorsa oyun biter.
        else
        {
            //Player ve computer score ekrana yazdirilir
            cout<< endl <<"Player score: "<< getPlayerScore()
                << endl <<"Computer score: "<< getComputerScore() 
                << endl << endl; 

            cout << endl << "This Game is Over..." << endl;
        }
    }

    // A function that takes another object Reversi as parameter and
    // compares the reversi games. 
    // It returns true is the first game is better for the user, 
    // otherwise it returns false.
    bool Reversi::isFirstGameIsBetter(const Reversi &otherGameCells) const
    {
        int result;
    
        if(getPlayerScore()>otherGameCells.getPlayerScore())
            result=true;

        else
            result=false;

        return result;
    }
    
    //Operator ++ (Prefix version) will advance the game by one step for 
    //computer. 
    //It will return the expected results.
    Reversi Reversi::operator++( )
    {
        setLivingCellsNumber(getLivingCellsNumber()-getLocalLiveCellsNumber());
        playComputer();
        displayBoard(); 
        return Reversi(getBoardWidth(),getBoardHeight());
    }
    
    //Operator ++ (Postfix version) will advance the game by one step for 
    //computer. 
    //It will return the expected results.
    Reversi Reversi::operator++(int ignoreMe)
    {
        setLivingCellsNumber(getLivingCellsNumber()-getLocalLiveCellsNumber());
        playComputer();
        displayBoard(); 
        return Reversi(getBoardWidth(),getBoardHeight());
    }
    
    
    //Stream insertion operators that prints the game on the screen
    ostream& operator <<(ostream& outputStream, const Reversi &simple)
    {
        simple.displayBoard(); 
    }
    

    
    
    

    
    
    
    //MATADORS******************************************************************
    //
    //
    // set GameCells
    void Reversi::setGameCells()
    {
        Cell*  newGameCells = new Cell[getBoardHeight()*getBoardWidth()];
        //new ile alan ayrilir
        
        int testRow=ZERO; // row numberi artirmaya yarayan degisken
        int testColumb=ZERO; // columb numberi artirmaya yarayan degisken
        int row=ONE; // row sayisi
        int columb=ZERO; // columb sayisi
        
        
        for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
        {
            //Row Number
            if(testRow<getBoardWidth())
                ++testRow;
                
            else
            {
                testRow=ONE;
                ++row;
            }

            //Columb Number
            if((i%getBoardWidth())==ZERO)
                columb=ONE;
            
            else
                ++columb;

            //Row and column Numbers atanir.
            newGameCells[i].setX(row);
            newGameCells[i].setY(columb);
            newGameCells[i].setSembol(EMPTY_SEMBOL_NUMBER);
                
        }
        
        //OYUN BASI "X" VE "O" YERLESTIRILIR
        int computerSembolLocationX=getBoardHeight()/TWO;
        int computerSembolLocationY=getBoardWidth()/TWO;

        
        if(getBoardWidth()>ONE && getBoardHeight()>ONE)
        {
            
            setLivingCellsNumber(getLivingCellsNumber()+FOUR_LIVING_CELLS);
            setLocalLiveCellsNumber(FOUR_LIVING_CELLS);

            for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
            {
                if(newGameCells[i].getX()==computerSembolLocationX &&
                        newGameCells[i].getY()==computerSembolLocationY)
                            newGameCells[i].setSembol(COMPUTER_SEMBOL_NUMBER);
                    
                if(newGameCells[i].getX()==computerSembolLocationX &&
                    newGameCells[i].getY()==computerSembolLocationY+ONE)
                                newGameCells[i].setSembol(PLAYER_SEMBOL_NUMBER);
                    
                if(newGameCells[i].getX()==computerSembolLocationX+ONE &&
                    newGameCells[i].getY()==computerSembolLocationY+ONE)
                            newGameCells[i].setSembol(COMPUTER_SEMBOL_NUMBER);
                    
                if(newGameCells[i].getX()==computerSembolLocationX+ONE &&
                    newGameCells[i].getY()==computerSembolLocationY)
                                newGameCells[i].setSembol(PLAYER_SEMBOL_NUMBER);                   
            }
                
            setPlayerScore(TWO_SCORE);
            setComputerScore(TWO_SCORE);
        }
        
        
        else
        {        
            if(getBoardWidth()==ONE && getBoardHeight()>ONE )
            {
                
                setLivingCellsNumber(getLivingCellsNumber()+TWO_LIVING_CELLS);
                setLocalLiveCellsNumber(TWO_LIVING_CELLS);
            
                for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
                {
                    if(newGameCells[i].getX()==computerSembolLocationX &&
                            newGameCells[i].getY()==computerSembolLocationY+ONE)
                    {
                        newGameCells[i].setSembol(COMPUTER_SEMBOL_NUMBER);
                        newGameCells[i+ONE].setSembol(PLAYER_SEMBOL_NUMBER);        
                    }                                                  
                }

                setPlayerScore(ONE_SCORE);
                setComputerScore(ONE_SCORE);
            }
            
            
            else if(getBoardHeight()==ONE && getBoardWidth()>ONE)
            {
                setLivingCellsNumber(getLivingCellsNumber()+TWO_LIVING_CELLS);
                setLocalLiveCellsNumber(TWO_LIVING_CELLS);
                
                
                for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
                {                 
                    if(newGameCells[i].getX()==computerSembolLocationX+ONE &&
                            newGameCells[i].getY()==computerSembolLocationY)
                    {
                        newGameCells[i].setSembol(COMPUTER_SEMBOL_NUMBER);
                        newGameCells[i+ONE].setSembol(PLAYER_SEMBOL_NUMBER);
                    }                                               
                }

                setPlayerScore(ONE_SCORE);
                setComputerScore(ONE_SCORE);
            }
            
            else
            {
                setLivingCellsNumber(getLivingCellsNumber()+ONE_LIVING_CELLS);
                setLocalLiveCellsNumber(ONE_LIVING_CELLS);
                
                for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
                    if(newGameCells[i].getX()==computerSembolLocationX+ONE &&
                            newGameCells[i].getY()==computerSembolLocationY+ONE)
                              newGameCells[i].setSembol(COMPUTER_SEMBOL_NUMBER);

                setPlayerScore(ZERO);
                setComputerScore(ONE_SCORE);
            }
        }
        

        gameCells=newGameCells;
        
    }
    
    
    // set boardHeight
    void Reversi::setboardHeight(const int &newBoardHeight)
    {
        if(newBoardHeight<=ZERO)
        {
            cout << endl << "Illegal Height Size" << endl << "Game Over";
            exit(1);
        }

        else
            boardHeight=newBoardHeight;
    }

    // set boardWidth
    void Reversi::setboardWidth(const int &newBoardWidth)
    {
        if(newBoardWidth<=ZERO)
        {
            cout << endl << "Illegal Width Size" << endl << "Game Over";
            exit(1);
        }

        else
            boardWidth=newBoardWidth;
    }

    //
    //
    //MATADORS******************************************************************
    
   
    

    
    
    //FOR MOVES*************************************************************
    //
    //
    //MoveFeatureT tipindeki Struct Arrayin degerleri sifirlanir
    void Reversi::ResetStructMoveFeatureTArray(
    move_feature_t structMoveFeatureTArray[],int size) const
    {
        //DEGERLER SIFIRLANIR
        for(int timer=ZERO; timer<size; ++timer)
        {
            structMoveFeatureTArray[timer].legal=ZERO;
            structMoveFeatureTArray[timer].total_gain=ZERO;
            structMoveFeatureTArray[timer].column=ZERO;
            structMoveFeatureTArray[timer].line=ZERO;
            structMoveFeatureTArray[timer].kuzey=ZERO;
            structMoveFeatureTArray[timer].kuzeybati=ZERO;
            structMoveFeatureTArray[timer].bati=ZERO;
            structMoveFeatureTArray[timer].guneybati=ZERO;
            structMoveFeatureTArray[timer].guney=ZERO;
            structMoveFeatureTArray[timer].guneydogu=ZERO;
            structMoveFeatureTArray[timer].dogu=ZERO;
            structMoveFeatureTArray[timer].kuzeydogu=ZERO;
        }
    }

    //MoveFeatureT tipindeki Structin degerleri sifirlanir
    void Reversi::ResetStructMoveFeatureT(
    move_feature_t &structMoveFeatureT) const
    {
        //DEGERLER SIFIRLANIR
        structMoveFeatureT.legal=ZERO;
        structMoveFeatureT.total_gain=ZERO;
        structMoveFeatureT.column=ZERO;
        structMoveFeatureT.line=ZERO;
        structMoveFeatureT.kuzey=ZERO;
        structMoveFeatureT.kuzeybati=ZERO;
        structMoveFeatureT.bati=ZERO;
        structMoveFeatureT.guneybati=ZERO;
        structMoveFeatureT.guney=ZERO;
        structMoveFeatureT.guneydogu=ZERO;
        structMoveFeatureT.dogu=ZERO;
        structMoveFeatureT.kuzeydogu=ZERO;  
    }
   
    
    //Hangi hucrelerin verilen sembolde oldugu bulunur.
    void Reversi::WhichOnesIsGivenSembol(
    move_feature_t structMoveFeatureTArray[],const char &Sembol,
            const int &whoIsMove)
    {
        int timer=ZERO;

        for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
        {
            if(gameCells[i].getSembol()==Sembol)
            {
                structMoveFeatureTArray[timer].line=gameCells[i].getX();
                structMoveFeatureTArray[timer].column=gameCells[i].getY();
                ++timer;
                
                //Player icin
                if(whoIsMove==PLAYER_MOVE)
                    setNumberOfPlayerMove(getNumberOfPlayerMove()+ONE);
        
                //Computer icin
                 else if(whoIsMove==COMPUTER_MOVE)
                    setNumberOfComputerMove(getNumberOfComputerMove()+ONE);     
            }
        }            
    }
    
    //Arrayde olan hucrelerin cevreleri kontrol edilir
    //cevresinde verilen sembolden olanlar secilir
    void Reversi::WhichOnesHasGivenSembolOnAround(
    move_feature_t structMoveFeatureTArray[], const char &Sembol, 
            const int &whoIsMove) const
    {   
        int limit;
        
        //Player icin
        if(whoIsMove==PLAYER_MOVE) limit=getNumberOfPlayerMove();
        
        //Computer icin
        else if(whoIsMove==COMPUTER_MOVE) limit=getNumberOfComputerMove();
        
        //else
        else limit=ZERO;
        
        //GIRILEN HAMLENIN CEVRESI KONTROL EDILIR
        for(int timer=ZERO; timer<limit; ++timer)
        {
            //(getX()-ONE)*getBoardWidth()+getY()-ONE (HAMLENIN ARRAYDAKI YERI)
            
            //KUZEY
            if(structMoveFeatureTArray[timer].line!=ONE)
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column-ONE
                -getBoardWidth()].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].kuzey=ONE;
            }

            //KUZEYBATI
            if(structMoveFeatureTArray[timer].line!=ONE && 
                    structMoveFeatureTArray[timer].column!=ONE)
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column-TWO
                -getBoardWidth()].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].kuzeybati=ONE;
            }

            //BATI
            if(structMoveFeatureTArray[timer].column!=ONE)
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -TWO].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].bati=ONE;
            }        

            //GUNEYBATI
            if(structMoveFeatureTArray[timer].line!=getBoardWidth() && 
                    structMoveFeatureTArray[timer].column!=ONE )
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -TWO+getBoardWidth()].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].guneybati=ONE;
            }

            //GUNEY
            if(structMoveFeatureTArray[timer].line!=getBoardWidth())
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -ONE+getBoardWidth()].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].guney=ONE;
            }

            //GUNEYDOGU
            if(structMoveFeatureTArray[timer].line!=getBoardWidth() && 
                    structMoveFeatureTArray[timer].column!=getBoardHeight())
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                +getBoardWidth()].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].guneydogu=ONE;
            }

            //DOGU
            if(structMoveFeatureTArray[timer].column!=getBoardHeight())
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()
                +structMoveFeatureTArray[timer].column].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].dogu=ONE;
            }

            //KUZEYDOGU
            if(structMoveFeatureTArray[timer].line!=ONE && 
                    structMoveFeatureTArray[timer].column!=getBoardHeight())
            {
                if(gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -getBoardWidth()].getSembol()==Sembol)
                    structMoveFeatureTArray[timer].kuzeydogu=ONE;
            }
        }
        
        
        
        
    }  
    
    
    //Karsi tarafin sembolleri bittikten sonra sonunda hamleyi yapan
    //tarafin iconu var ise o hamle legal hamledir.
    void Reversi::IsItLegalMove(move_feature_t structMoveFeatureTArray[],
        const char &moveSembol, const char &counterSembol, 
            const int &whoIsMove) const
    {
        int i=ZERO;
        int endTheBoard=ONE; // Boardin bitip bitmedigini kontrol amacli
        int limit;
        
        //Player icin
        if(whoIsMove==PLAYER_MOVE) limit=getNumberOfPlayerMove();
        
        //Computer icin
        else if(whoIsMove==COMPUTER_MOVE) limit=getNumberOfComputerMove();
        
        //else
        else limit=ZERO;
        
        //CEVRESINDE RAKIBIN SEMBOLU OLANLARDA ILERLENIR
        //EGER SONUNDA HAMLEYI YAPAN TARAFIN SEMBOLUNE RASTLANIRSA
        //HAMLE LEGAL BIR HAMLEDIR

        for(int timer=ZERO; timer<limit; ++timer)
        {
            //KUZEY
            if(structMoveFeatureTArray[timer].kuzey)
            {   
                while(endTheBoard==ONE && 
                    gameCells[(structMoveFeatureTArray[timer].line-ONE)
                    *getBoardWidth()+structMoveFeatureTArray[timer].column
                    -ONE-((i+ONE)*getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].line-ONE-i<ONE)
                        endTheBoard=ZERO;
                }

                if(endTheBoard==ONE && 
                    gameCells[(structMoveFeatureTArray[timer].line-ONE)
                    *getBoardWidth()+structMoveFeatureTArray[timer].column
                    -ONE-((i+ONE)*getBoardWidth())].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }
            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;

            //KUZEYBATI
            if(structMoveFeatureTArray[timer].kuzeybati)
            {
                while(endTheBoard==ONE && 
                    gameCells[(structMoveFeatureTArray[timer].line-ONE)
                    *getBoardWidth()+structMoveFeatureTArray[timer].column
                   -TWO-i-((i+ONE)*getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].line-ONE-i<ONE || 
                        structMoveFeatureTArray[timer].column-ONE-i<ONE)
                        endTheBoard=ZERO;
                }

                if(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -TWO-i-((i+ONE)*getBoardWidth())].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }
            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;

            //BATI
            if(structMoveFeatureTArray[timer].bati)
            {
                while(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -TWO-i].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].column-ONE-i<ONE)
                        endTheBoard=ZERO;
                }

                if(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -TWO-i].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }
            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;

            //GUNEYBATI
            if(structMoveFeatureTArray[timer].guneybati)
            {
                while(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -TWO-i+((i+ONE)*getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].line+ONE+i>getBoardHeight() 
                    ||  structMoveFeatureTArray[timer].column-ONE-i<ONE)
                        endTheBoard=ZERO;
                }
                
                if(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -TWO-i+((i+ONE)*getBoardWidth())].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }
            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;

            //GUNEY
            if(structMoveFeatureTArray[timer].guney)
            {             
                while(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -ONE+((i+ONE)*getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].line+ONE+i>getBoardHeight())
                        endTheBoard=ZERO;
                }
                

                if(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                -ONE+((i+ONE)*getBoardWidth())].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }

            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;

            //GUNEYDOGU
            if(structMoveFeatureTArray[timer].guneydogu)
            {
                while(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                +i+((i+ONE)*getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].line+ONE+i>getBoardHeight() 
                    || structMoveFeatureTArray[timer].column+ONE+i>getBoardWidth())
                        endTheBoard=ZERO;
                }

                if(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                +i+((i+ONE)*getBoardWidth())].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }

            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;

            //DOGU
            if(structMoveFeatureTArray[timer].dogu)
            {              
                while(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                +i].getSembol()==counterSembol)
                {
                    ++i;
                    
                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].column+ONE+i>getBoardWidth())
                        endTheBoard=ZERO;
                }
                
                if(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                +i].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }
            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;

            //KUZEYDOGU
            if(structMoveFeatureTArray[timer].kuzeydogu)
            {
                while(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                +i-((i+ONE)*getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureTArray[timer].line-ONE-i<ONE || 
                        structMoveFeatureTArray[timer].column+ONE+i>getBoardWidth())
                        endTheBoard=ZERO;
                }

                if(endTheBoard==ONE && 
                gameCells[(structMoveFeatureTArray[timer].line-ONE)
                *getBoardWidth()+structMoveFeatureTArray[timer].column
                +i-((i+ONE)*getBoardWidth())].getSembol()==moveSembol)
                {   
                    structMoveFeatureTArray[timer].legal=ONE;
                    structMoveFeatureTArray[timer].total_gain+=i;
                }

            }

            //DEGERLER SIFIRLANIR
            i=ZERO; endTheBoard=ONE;
        }        
    }
    
    
    
    //En akilli hamle bulunur
    void Reversi::forComputerWhichOneIsSmartestMove(
    move_feature_t moveOfcomputer[], move_feature_t &bestMoveForComputer) const
    {
        int timer=ZERO;
        int check_corner=ZERO;//Koselerde hamle varsa 1 yoksa 0 olur;
        int corner_total_gain=ZERO;//Kosedeki noktanin toplam kazanci

        while(timer<getNumberOfComputerMove())
        {
            //EN COK KAZANCLI OLAN VE KOSEDE OLAN SECILIR

            //SOL UST KOSE UYGUNSA
            //SOL ALT KOSE UYGUNSA
            //SAG UST KOSE UYGUNSA
            //SAG ALT KOSE UYGUNSA
            if((moveOfcomputer[timer].line==ONE 
                && moveOfcomputer[timer].column==ONE) ||
               (moveOfcomputer[timer].line==(getBoardHeight()) && 
                moveOfcomputer[timer].column==ONE) ||
               (moveOfcomputer[timer].line==ONE && 
                moveOfcomputer[timer].column==(getBoardWidth())) ||
               (moveOfcomputer[timer].line==(getBoardHeight()) && 
                moveOfcomputer[timer].column==(getBoardWidth())))
            {      
                if((moveOfcomputer[timer].total_gain)>corner_total_gain)
                {
                    corner_total_gain=moveOfcomputer[timer].total_gain;
                    check_corner=ONE;

                    (bestMoveForComputer.legal)=moveOfcomputer[timer].legal;
                    (bestMoveForComputer.total_gain)
                                            =moveOfcomputer[timer].total_gain;
                    (bestMoveForComputer.line)=moveOfcomputer[timer].line;
                    (bestMoveForComputer.column)=moveOfcomputer[timer].column;
                    (bestMoveForComputer.kuzey)=moveOfcomputer[timer].kuzey;
                    (bestMoveForComputer.kuzeybati)
                                            =moveOfcomputer[timer].kuzeybati;
                    (bestMoveForComputer.bati)=moveOfcomputer[timer].bati;
                    (bestMoveForComputer.guneybati)
                                            =moveOfcomputer[timer].guneybati;
                    (bestMoveForComputer.guney)=moveOfcomputer[timer].guney;
                    (bestMoveForComputer.guneydogu)
                                            =moveOfcomputer[timer].guneydogu;
                    (bestMoveForComputer.dogu)=moveOfcomputer[timer].dogu;
                    (bestMoveForComputer.kuzeydogu)
                                            =moveOfcomputer[timer].kuzeydogu;
                }  
            }


            //EGER KOSEDE OLAN YOKSA
            //EN COK KAZANCLI OLAN SECILIR
            if(!check_corner)
            {
                if((moveOfcomputer[timer].total_gain)>
                                            (bestMoveForComputer.total_gain))
                {
                    (bestMoveForComputer.legal)=moveOfcomputer[timer].legal;
                    (bestMoveForComputer.total_gain)
                                            =moveOfcomputer[timer].total_gain;
                    (bestMoveForComputer.line)=moveOfcomputer[timer].line;
                    (bestMoveForComputer.column)=moveOfcomputer[timer].column;
                    (bestMoveForComputer.kuzey)=moveOfcomputer[timer].kuzey;
                    (bestMoveForComputer.kuzeybati)
                                            =moveOfcomputer[timer].kuzeybati;
                    (bestMoveForComputer.bati)=moveOfcomputer[timer].bati;
                    (bestMoveForComputer.guneybati)
                                            =moveOfcomputer[timer].guneybati;
                    (bestMoveForComputer.guney)=moveOfcomputer[timer].guney;
                    (bestMoveForComputer.guneydogu)
                                            =moveOfcomputer[timer].guneydogu;
                    (bestMoveForComputer.dogu)=moveOfcomputer[timer].dogu;
                    (bestMoveForComputer.kuzeydogu)
                                            =moveOfcomputer[timer].kuzeydogu;
                }
            }
            ++timer;
        }    
    }
    
    
    //Computerin yaptigi hamle ekrana yazilir
    void Reversi::forComputerPrintTheMove(move_feature_t &bestMoveForComputer)
    {      
        if(bestMoveForComputer.legal)
        {
            //SUTUN DEGERININ SAYI KARSILIGININ BULUNMASI
            vector<char> digitLetter;// sayilarin basamaklarinin harf karsiligini 
                                 // tutan vector
            char letter; // harfleri tutan degisken
            int number=bestMoveForComputer.column; // bestMoveForComputer.column 
                                                //degerini tutan gecici degisken
            int totalDigitsNumber=ZERO; //numberin digit sayisini tutan degisken
            int digit; // rakamlari tutan degisken

            int endTheBoard=ACTIVE; // Boardin bitip bitmedigini kontrol amacli

            while(number)
            {
                digit=number%TEN; //sayinin son basamagi bulunur.
                number=number/TEN; //sayi 10 a bolunur.
                letter=digitTranslateLetter(digit); // basamagin harf karsiligi
                                                        // bulunur.
                digitLetter.push_back(letter); // vektore bulunan harf eklenir.
                ++totalDigitsNumber; // Sayinin kac basamakli oldugu bulunur.
            }


            //Computerin yaptigi hamle
            cout << endl << "The computer's move is "
                 << bestMoveForComputer.line; // (row)
            for(int j=totalDigitsNumber-ONE; j>=ZERO ; --j)
                cout << digitLetter[j];//Sayinin harf karsiligi yazilir(columb)

            //vector sifirlanir
            digitLetter.clear();
        }
        
         else
        {
            cout << endl << "The computer does not have a legal move";
            setComputerCanMove(ZERO);
        }     
    }
    
    //Hamle uygulanilir
    void Reversi::DoMove(move_feature_t &structMoveFeatureT,
        const char &moveSembol, const char &counterSembol,const int &whoIsMove)
    {     
        if(structMoveFeatureT.legal)
        {
            //YASAYAN HUCRE SAYISI 1 ARTIRILIR
            setLivingCellsNumber(getLivingCellsNumber()+ONE_LIVING_CELLS);
            setLocalLiveCellsNumber(getLocalLiveCellsNumber()+ONE_LIVING_CELLS);

            int i=ONE, temp_i=ZERO, endTheBoard=ACTIVE;

            //ICONLARIN DEGISMESI

            //KUZEY
            if(structMoveFeatureT.kuzey)
            {    
                //BOARD SINIR KONTROL MERKEZI
                if(structMoveFeatureT.line-ONE-i<ONE)    
                            endTheBoard=PASSIVE;
                
                
                while(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-ONE-((i+ONE)
                        *getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line-ONE-i<ONE)    
                            endTheBoard=PASSIVE;
                }

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-ONE-((i+ONE)
                        *getBoardWidth())].getSembol()==moveSembol)
                {       
                    
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-ONE-((temp_i+ONE)
                        *getBoardWidth())].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }
            }


            //DEGERLER SIFIRLANIR
            i=ONE, temp_i=ZERO; endTheBoard=ACTIVE;

            //KUZEYBATI
            if(structMoveFeatureT.kuzeybati)
            {    
                //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line-ONE-i<ONE || 
                       structMoveFeatureT.column-ONE-i<ONE)
                            endTheBoard=PASSIVE;
                
                while(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-TWO-i-((i+ONE)
                        *getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line-ONE-i<ONE || 
                       structMoveFeatureT.column-ONE-i<ONE)
                            endTheBoard=PASSIVE;
                }

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-TWO-i-((i+ONE)
                        *getBoardWidth())].getSembol()==moveSembol)
                {       
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-TWO-temp_i-((temp_i+ONE)
                        *getBoardWidth())].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }
            }

            //DEGERLER SIFIRLANIR
            i=ONE, temp_i=ZERO; endTheBoard=ACTIVE;

            //BATI
            if(structMoveFeatureT.bati)
            {   
                //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.column-ONE-i<ONE)
                            endTheBoard=PASSIVE;
                
                while(endTheBoard==ACTIVE &&
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column
                        -TWO-i].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.column-ONE-i<ONE)
                            endTheBoard=PASSIVE;
                }       

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                    +structMoveFeatureT.column-TWO-i].getSembol()==moveSembol)
                {       
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                    +structMoveFeatureT.column-TWO-temp_i].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }
            }

            //DEGERLER SIFIRLANIR
            i=ONE, temp_i=ZERO; endTheBoard=ACTIVE;

            //GUNEYBATI
            if(structMoveFeatureT.guneybati)
            {
                //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line+ONE+i>getBoardHeight() || 
                       structMoveFeatureT.column-ONE-i<ONE)
                            endTheBoard=PASSIVE;
                
                while(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-TWO-i+((i+ONE)
                        *getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line+ONE+i>getBoardHeight() || 
                       structMoveFeatureT.column-ONE-i<ONE)
                            endTheBoard=PASSIVE;
                }

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-TWO-i+((i+ONE)
                        *getBoardWidth())].getSembol()==moveSembol)
                {       
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-TWO-temp_i+((temp_i+ONE)
                        *getBoardWidth())].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }
            }

            //DEGERLER SIFIRLANIR
            i=ONE, temp_i=ZERO; endTheBoard=ACTIVE;

            //GUNEY
            if(structMoveFeatureT.guney)
            {
                //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line+ONE+i>getBoardHeight())
                            endTheBoard=PASSIVE;
                
                while(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-ONE+((i+ONE)
                        *getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line+ONE+i>getBoardHeight())
                            endTheBoard=PASSIVE;
                }

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-ONE+((i+ONE)
                        *getBoardWidth())].getSembol()==moveSembol)
                {       
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column-ONE+((temp_i+ONE)
                        *getBoardWidth())].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }

            }

            //DEGERLER SIFIRLANIR
            i=ONE, temp_i=ZERO; endTheBoard=ACTIVE;

            //GUNEYDOGU
            if(structMoveFeatureT.guneydogu)
            {
                //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line+ONE+i>getBoardHeight() || 
                       structMoveFeatureT.column+ONE+i>getBoardWidth())
                            endTheBoard=PASSIVE;
                
                while(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+i+((i+ONE)
                        *getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line+ONE+i>getBoardHeight() || 
                       structMoveFeatureT.column+ONE+i>getBoardWidth())
                            endTheBoard=PASSIVE;
                }

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+i+((i+ONE)
                        *getBoardWidth())].getSembol()==moveSembol)
                {       
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+temp_i+((temp_i+ONE)
                        *getBoardWidth())].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }

            }

            //DEGERLER SIFIRLANIR
            i=ONE, temp_i=ZERO; endTheBoard=ACTIVE;

            //DOGU
            if(structMoveFeatureT.dogu)
            {
                //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.column+ONE+i>getBoardWidth())
                            endTheBoard=PASSIVE;
                
                while(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                       +structMoveFeatureT.column+i].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.column+ONE+i>getBoardWidth())
                            endTheBoard=PASSIVE;
                }

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+i].getSembol()==moveSembol)
                {       
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+temp_i].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }
            }

            //DEGERLER SIFIRLANIR
            i=ONE, temp_i=ZERO; endTheBoard=ACTIVE;

            //KUZEYDOGU
            if(structMoveFeatureT.kuzeydogu)
            {
                //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line-ONE-i<ONE || 
                       structMoveFeatureT.column+ONE+i>getBoardWidth())
                            endTheBoard=PASSIVE;
                        
                while(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+i-((i+ONE)
                        *getBoardWidth())].getSembol()==counterSembol)
                {
                    ++i;

                    //BOARD SINIR KONTROL MERKEZI
                    if(structMoveFeatureT.line-ONE-i<ONE || 
                       structMoveFeatureT.column+ONE+i>getBoardWidth())
                            endTheBoard=PASSIVE;
                }

                if(endTheBoard==ACTIVE && 
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+i-((i+ONE)
                        *getBoardWidth())].getSembol()==moveSembol)
                {       
                    gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                            +structMoveFeatureT.column-ONE].setSembol(whoIsMove);

                    while(temp_i<i)
                    {
                        gameCells[(structMoveFeatureT.line-ONE)*getBoardWidth()
                        +structMoveFeatureT.column+temp_i-((temp_i+ONE)
                        *getBoardWidth())].setSembol(whoIsMove);
                        ++temp_i;
                    }
                }

            }
        }
    }
    
    
    //Player yapacak hamleye sahip mi degil mi
    int Reversi::doesPlayerHaveMove()
    {
        setNumberOfPlayerMove(ZERO);
        move_feature_t playerMovetest[getBoardHeight()*getBoardWidth()+ONE];
        // player icin hamlelerin struct degerini tutan degisken
        
        //Struct degerleri sifirlanir
        ResetStructMoveFeatureTArray(playerMovetest, getBoardHeight()
                *getBoardWidth()+ONE);

        //Player'a ait olan iconlar bulunur
        WhichOnesIsGivenSembol(playerMovetest,PLAYER_SEMBOL,PLAYER_MOVE);
        
        //Player'a ait olan hucrelerin cevreleri kontrol edilir
        //cevresinde computer iconlari olanlar secilir
        WhichOnesHasGivenSembolOnAround(playerMovetest,
                COMPUTER_SEMBOL,PLAYER_MOVE);
        
        
        //computer iconu bittikten sonra sonunda nokta (empty) iconu olanlar 
        //varsa player hamle yapabilir anlamina gelmektedir
        IsItLegalMove(playerMovetest, EMPTY_SEMBOL,COMPUTER_SEMBOL,PLAYER_MOVE);

        
        setPlayerCanMove(ZERO);      
        
        for(int timer=ZERO; timer<getNumberOfPlayerMove(); ++timer)
            if(playerMovetest[timer].legal)
                setPlayerCanMove(ONE);
  
        //Eger player yapilabilir bir hamleye sahip ise playerCanMove 1 olarak
        //sahip degil ise playerCanMove 0 olarak return edilir.
        return getPlayerCanMove();
    }
    
    //Playerin hamlesinin nokta olup olmadini dondurur
    bool Reversi::forPlayerIsItEmptyIcon(const int &cellPositionX, 
                                             const int &cellPositionY) const
    {
        int isItEmptyIcon;      
        
        //EGER LEGAL OLMAYAN DEGER GIRILIRSE
        if(cellPositionX<ONE || cellPositionX>getBoardHeight() ||
              cellPositionY<ONE || cellPositionY>getBoardWidth() ||
              gameCells[(cellPositionX-ONE)*getBoardWidth()
                +cellPositionY-ONE].getSembol()!=EMPTY_SEMBOL)
        {  
            isItEmptyIcon=false;
        }

        else
        {
            isItEmptyIcon=true;
        }

        return isItEmptyIcon;
    }
    //
    //
    //FOR MOVES*************************************************************
    
    
    

    
    
    
    //OTHER STAFF***************************************************************
    //
    //
    //Girilen width ve height degerlerini kontrol amacli
    int Reversi::checkBoardSizes(int boardWidthorHeight) const
    {
        if(boardWidthorHeight<=ZERO)
        {
            cout << endl << "Illegal Board Size" << endl << "Game Over";
            exit(1);
        }

        else
            return boardWidthorHeight;
    }

    //SAYIYI HARFE CEVIRIR
    char Reversi::digitTranslateLetter(const int &digit) const
    {
        char letter;

        switch(digit)
        {
            case ONE:
               letter='A';
               break;
            case TWO:
                letter='B';
                break;
            case THREE:
               letter='C';
               break;
            case FOUR:
                letter='D';
                break;
            case FIVE:
               letter='E';
               break;
            case SIX:
                letter='F';
                break;
            case SEVEN:
               letter='G';
               break;
            case EIGHT:
                letter='H';
                break;
            case NINE:
               letter='I';
               break;
            case ZERO:
                letter='J';
                break;
            default:
                ;
        }
        return letter;
    }


    //HARFI SAYIYA CEVIRIR
    int Reversi::letterTranslateDigit (const char &letter) const
    {
        int digit;

        switch(letter)
        {
            case 'A':
               digit=ONE;
               break;
            case 'B':
                digit=TWO;
                break;
            case 'C':
               digit=THREE;
               break;
            case 'D':
                digit=FOUR;
                break;
            case 'E':
               digit=FIVE;
               break;
            case 'F':
                digit=SIX;
                break;
            case 'G':
               digit=SEVEN;
               break;
            case 'H':
                digit=EIGHT;
                break;
            case 'I':
               digit=NINE;
               break;
            case 'J':
                digit=ZERO;
                break;
            default:
                ;
        }

        return digit;

    }

    //STRINGI SAYIYA CEVIRIR
    int Reversi::stringTranslateNumber (string &cellPositionYString) const
    {
        int digit; // rakamlari tutan degisken
        int digitNumber=ONE; // basamagin degerini (birler, onlar vb.) tutar.
        int cellPositionYNumber=ZERO; // cell Position Y Stringinin sayi karsiligi

        for (string::iterator i=cellPositionYString.end()-ONE; 
                                i!=cellPositionYString.begin()-ONE; --i)
        {    
            digit=letterTranslateDigit(*i); // harfin sayi karsiligi bulunur.
            cellPositionYNumber+=digit*digitNumber; // bulunan sayi 
                                                    //cellPositionYNumber eklenir.
            digitNumber = digitNumber*TEN; // basamak degeri arttirilir
        }

        return cellPositionYNumber;
    }

    //SCOREBOARD
    void Reversi::scoreboard()
    {
        int newComputerScore=ZERO;
        int newPlayerScore=ZERO;

        //Butun hucreler kontrol edilir
        for(int i=ZERO; i<getBoardHeight()*getBoardWidth(); ++i)
        {
            //Player'a ait olan yerler icin
            //Player score 1 arttirilir
            if(gameCells[i].getSembol()==PLAYER_SEMBOL)
                ++newPlayerScore;

            //Computere ait olan yerler icin
            //Computer score 1 arttirilir
            else if(gameCells[i].getSembol()==COMPUTER_SEMBOL)
                ++newComputerScore;
        }

        setPlayerScore(newPlayerScore);
        setComputerScore(newComputerScore);
    }
    //
    //
    //OTHER STAFF***************************************************************
    
    
    //Destructor      
    Reversi::~Reversi()
    {
        delete [] gameCells;
    }
}