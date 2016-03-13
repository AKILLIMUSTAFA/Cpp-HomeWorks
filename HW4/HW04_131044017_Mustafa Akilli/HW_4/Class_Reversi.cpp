// HW04_131044017_Mustafa_Akilli
//
// File:   Class_Reversi.cpp
// Author: Mustafa_Akilli
//
// Created on 04 Kasim 2015 Carsamba, 10:58
//
// Description
//
// HW4 Reversi Class


#include "header.h"
#include <string>
#include <limits>
#include <fstream>

//Constructors******************************************************************
Reversi::Reversi(int newBoardWidth, int newBoardHeight):
                gameCells(checkBoardSizes(newBoardWidth),
                                vector<Cell> (checkBoardSizes(newBoardHeight)))
{
    setboardHeight(newBoardHeight);
    setboardWidth(newBoardWidth);
    setComputerCanMove(1);
    setPlayerCanMove(1);
    setFirstTime(1);
    setLocalLiveCellsNumber(0);
    setGameCells();
}

Reversi::Reversi(int newBoardSize):
             gameCells(checkBoardSizes(newBoardSize),
                                vector<Cell> (checkBoardSizes(newBoardSize)))
{
    setboardHeight(newBoardSize);
    setboardWidth(newBoardSize);
    setComputerCanMove(1);
    setPlayerCanMove(1);
    setFirstTime(1);
    setLocalLiveCellsNumber(0);
    setGameCells();
}
    
Reversi::Reversi():
            gameCells(checkBoardSizes(10),
                                vector<Cell> (checkBoardSizes(10)))
{
    setboardHeight(10);
    setboardWidth(10);
    setComputerCanMove(1);
    setPlayerCanMove(1);
    setFirstTime(1);
    setLocalLiveCellsNumber(0);
    setGameCells();
}




//A function that read from files
bool Reversi::readFromFile()
{
    ifstream inFile;
    
    inFile.open("Reversi.txt");
    
    if(inFile.fail())
    {
        cout << endl << "File can not open for read." << endl;
        return false;
    }

    char sembol;// cells sembolleri icin
    
    //Semboller dosyaya basilir
    for(int i=1; i<=getBoardWidth() ;++i)
    {  
        for(int j=1; j<=getBoardHeight() ;++j)
        {
            inFile >> sembol; 
            gameCells[i-1][j-1].setSembol(sembol);
        }      
    }
    
    inFile.close();
    
    return true;
}


//A function that write from files.
bool Reversi::writeFromFile() const
{
    ofstream outFile;
    
    outFile.open("Reversi.txt");
    
    if(outFile.fail())
    {
        cout << endl << "File can not open for write." << endl;
        return false;
    }
    
    //Semboller dosyaya basilir
    for(int i=1; i<=getBoardWidth() ;++i)
    {  
        for(int j=1; j<=getBoardHeight() ;++j)
            outFile << gameCells[i-1][j-1].getSembol() << " ";
                 
        outFile << endl;
    }

    outFile.close();
    
    return true;
}


//A function that displays the current board on the screen**********************
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
    
    int columbNumberDigits=0; // columb number sayisinin basamak 
                                  // sayisini tutan degisken
    int rowNumberDigits=0; //  row number sayisinin basamak 
                                  // sayisini tutan degisk.
    int tempRowNumber=getBoardHeight(); //row sayisinin degerinde gecici degisk.
    int tempColumbNumber=getBoardWidth(); //row sayisinin degerinde gecici deg.
    int checkRowNumber; //yazilan row sayilarinin digit degerini check eden deg.
    int controlRowNumber=0;//son yazilan row sayisinin digit sayisini tutan deg. 
    int digitRowNumber=-1; //yazilan row number sayisinin digit sayisi
    int digitColumbNumber=0; //yazilan columb number sayisinin digit sayisi
    
    //boardWidth (columb) sayisinin kac basamak oldugu bulunur.
    while (tempColumbNumber) {
        tempColumbNumber /= 10;
        ++rowNumberDigits;
    }
    
    // boardHeight (row) sayisinin kac basamak oldugu bulunur.
    while (tempRowNumber) {
        tempRowNumber /= 10;
        ++columbNumberDigits;
    }
    
    cout << endl;
    
    
    //sol ust kosede bosluk birakilir
    for(int i=0; i<=rowNumberDigits ;++i)
        cout << " ";
    
    
    vector<char> digitToLetter;// sayilarin basamaklarinin harf karsiligini 
                             // tutan vector
    char letter; // harfleri tutan degisken
    int number; // for dongusundeki i degerini tutan gecici degisken
    int totalDigitsNumber; //numberin digit sayisini tutan degisken
    int digit; // rakamlari tutan degisken
    
    //Ilk satira harfler yazilir
    for(int i=1; i<=getBoardHeight() ;++i)
    {
        number=i; // i  number' a atanir
        totalDigitsNumber=0; // totalDigitsNumber sifirlanir
        
        
        while(number)
        {
            digit=number%10; //sayinin son basamagi bulunur.
            number=number/10; //sayi 10 a bolunur.
            letter=digitTranslateLetter(digit); // basamagin harf karsiligi
                                                // bulunur.
            digitToLetter.push_back(letter); // vektore bulunan harf eklenir.
            ++totalDigitsNumber; // Sayinin kac basamakli oldugu bulunur.
        }
        
        //Sayinin harf karsiligi yazilir
        for(int j=totalDigitsNumber-1; j>=0 ; --j)
            cout << digitToLetter[j];
        
        //vector sifirlanir
        digitToLetter.clear();
        
        
        //Harfler yerlestirildikten sonra sonraki bosluk birakilir
        for(int t=totalDigitsNumber-1; t<columbNumberDigits; ++t)
                    cout << " ";
    }
    
    
    
    //Row numbers and Sembols
    cout << endl;
    for(int i=1; i<=getBoardWidth() ;++i)
    {
        number=i; // i  number' a atanir
        
        // Sayinin kac basamakli oldugu bulunur.
        while (number) {
            number /= 10;
            ++digitRowNumber;
        }
        
        //Basamak sayisi arttikca yazilan bosluk sayisini azaltma amacli
        if(digitRowNumber > controlRowNumber)
        {
            --rowNumberDigits;
            ++controlRowNumber;
        }
        
        //sifirlanir
        digitRowNumber=-1;
        
        //bosluklar ve semboller ekrana basilir
        cout << i;
        for(int space=0; space<rowNumberDigits; ++space)
            cout << " ";
        
            for(int j=1; j<=getBoardHeight() ;++j)
            {
                cout << gameCells[i-1][j-1].getSembol();
                for(int t=0; t<columbNumberDigits; ++t)
                    cout << " ";
            }
            cout << endl;
    }
    cout << endl;      
}




//A function that plays the computer move***************************************
void Reversi::playComputer()
{
    move_feature_t moveOfcomputer[getBoardHeight()*getBoardWidth()+1];
    setNumberOfComputerMove(0);
    
    //Struct degerleri sifirlanir
    forComputerResetStructs(moveOfcomputer);
    
    
    //Hangi hucrelerin bos oldugu bulunur.
    forComputerWhichOnesIsEmptyIcon(moveOfcomputer);
    
    //Bos olan hucrelerin cevreleri kontrol edilir
    //cevresinde player iconlari olanlar secilir
    forComputerWhichOnesHasPlayerIconOnAround(moveOfcomputer);
    
    
    //Player iconu bittikten sonra sonunda computer iconu olanlar secilir
    forComputerIsItLegalMove(moveOfcomputer);
    
    //En akilli hareket bulunur
    forComputerWhichOneIsSmartestMove(moveOfcomputer);
    
    //En akilli hareket uygulanilir
    forComputerDoBestMove();
    
    cout << endl << endl;  
}



//A function that plays the player move
void Reversi::playPlayer(int &cellPositionX, string &cellPositionYString) 
{ 
    //Girilen sutun harflerinin sayi karsiligi
    int cellPositionYNumber=stringTranslateNumber(cellPositionYString);
    int checkIsItLegalMove=0;
    
    
    while(!checkIsItLegalMove)
    {        
        //Cell empty icon ise 1 degilse 0 dondurur
        checkIsItLegalMove=forPlayerIsItEmptyIcon(cellPositionX-1, 
                                                        cellPositionYNumber-1); 

        if(checkIsItLegalMove)
        {
            //Cell legal icon ise 1 degilse 0 dondurur
            checkIsItLegalMove=forPlayerIsItLegalMove(cellPositionX-1, 
                                                        cellPositionYNumber-1);
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
int Reversi::endGame() const
{
    int result;
    
    if(getPlayerCanMove()==0 && getComputerCanMove()==0)
        result=1;
    
    else
        result=0;
    
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
        
        
        setboardHeight(sizeOfBoardX);
        setboardWidth(sizeOfBoardY);
        setGameCells();
        setFirstTime(0);
    }
    
    
    
    //Guncel board ekrana cizilir.
    displayBoard();   

    
            
    //Eger player veya computer hamle yapabiliyorsa oyun devam eder.
    if(!endGame())
    {
        setComputerCanMove(1); //Computerin hamlesi aktif hale gelir.
        
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

        //Computer Hareketi
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
            << endl <<"Computer score: "<< getComputerScore() << endl << endl; 
    
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
    
    
    
    
    
    
    
    
    






//FOR COMPUTER******************************************************************
//
//
//Struct degerleri sifirlanir
void Reversi::forComputerResetStructs(move_feature_t moveOfcomputer[])
{
    //DEGERLER SIFIRLANIR
    for(int timer=0; timer<=(getBoardHeight()*getBoardWidth()); ++timer)
    {
        moveOfcomputer[timer].legal=0;
        moveOfcomputer[timer].total_gain=0;
        moveOfcomputer[timer].column=0;
        moveOfcomputer[timer].line=0;
        moveOfcomputer[timer].kuzey=0;
        moveOfcomputer[timer].kuzeybati=0;
        moveOfcomputer[timer].bati=0;
        moveOfcomputer[timer].guneybati=0;
        moveOfcomputer[timer].guney=0;
        moveOfcomputer[timer].guneydogu=0;
        moveOfcomputer[timer].dogu=0;
        moveOfcomputer[timer].kuzeydogu=0;
    }
 
    //DEGERLER SIFIRLANIR
    bestMoveForComputer.legal=0;
    bestMoveForComputer.total_gain=0;
    bestMoveForComputer.column=0;
    bestMoveForComputer.line=0;
    bestMoveForComputer.kuzey=0;
    bestMoveForComputer.kuzeybati=0;
    bestMoveForComputer.bati=0;
    bestMoveForComputer.guneybati=0;
    bestMoveForComputer.guney=0;
    bestMoveForComputer.guneydogu=0;
    bestMoveForComputer.dogu=0;
    bestMoveForComputer.kuzeydogu=0;  
}

//Hangi hucrelerin bos oldugu bulunur.
void Reversi::forComputerWhichOnesIsEmptyIcon(move_feature_t moveOfcomputer[])
{
    int timer=0;
    
    for(int i=0; i<getBoardWidth();++i)
        for(int j=0; j<getBoardHeight(); ++j)
            if(gameCells[i][j].getSembol()==empty_sembol)
            {
               moveOfcomputer[timer].line=i;
               moveOfcomputer[timer].column=j;
               ++timer;
               ++numberOfComputerMove;
            } 
}

//Bos olan hucrelerin cevreleri kontrol edilir
//cevresinde player iconlari olanlar secilir
void Reversi::forComputerWhichOnesHasPlayerIconOnAround(
                                                move_feature_t moveOfcomputer[]) const
{   
    //GIRILEN HAMLENIN CEVRESI KONTROL EDILIR
    for(int timer=0; timer<getNumberOfComputerMove(); ++timer)
    {
        //KUZEY
        if(moveOfcomputer[timer].line!=0)
        {
            if(gameCells[moveOfcomputer[timer].line-1]
                    [moveOfcomputer[timer].column].getSembol()==player_sembol)
                moveOfcomputer[timer].kuzey=1;
        }

        //KUZEYBATI
        if(moveOfcomputer[timer].line!=0 && moveOfcomputer[timer].column!=0)
        {
            if(gameCells[moveOfcomputer[timer].line-1]
                    [moveOfcomputer[timer].column-1].getSembol()==player_sembol)
                moveOfcomputer[timer].kuzeybati=1;
        }

        //BATI
        if(moveOfcomputer[timer].column!=0)
        {
            if(gameCells[moveOfcomputer[timer].line]
                    [moveOfcomputer[timer].column-1].getSembol()==player_sembol)
                moveOfcomputer[timer].bati=1;
        }        

        //GUNEYBATI
        if(moveOfcomputer[timer].line<getBoardWidth()-1 && 
                moveOfcomputer[timer].column!=0 )
        {
            if(gameCells[moveOfcomputer[timer].line+1]
                    [moveOfcomputer[timer].column-1].getSembol()==player_sembol)
                moveOfcomputer[timer].guneybati=1;
        }

        //GUNEY
        if(moveOfcomputer[timer].line!=getBoardWidth()-1)
        {
            if(gameCells[moveOfcomputer[timer].line+1]
                    [moveOfcomputer[timer].column].getSembol()==player_sembol)
                moveOfcomputer[timer].guney=1;
        }

        //GUNEYDOGU
        if(moveOfcomputer[timer].line!=getBoardWidth()-1 && 
                moveOfcomputer[timer].column!=getBoardHeight()-1)
        {
            if(gameCells[moveOfcomputer[timer].line+1]
                    [moveOfcomputer[timer].column+1].getSembol()==player_sembol)
                moveOfcomputer[timer].guneydogu=1;
        }

        //DOGU
        if(moveOfcomputer[timer].column!=getBoardHeight()-1)
        {
            if(gameCells[moveOfcomputer[timer].line]
                    [moveOfcomputer[timer].column+1].getSembol()==player_sembol)
                moveOfcomputer[timer].dogu=1;
        }

        //KUZEYDOGU
        if(moveOfcomputer[timer].line!=0 && 
                moveOfcomputer[timer].column!=getBoardHeight()-1)
        {
            if(gameCells[moveOfcomputer[timer].line-1]
                    [moveOfcomputer[timer].column+1].getSembol()==player_sembol)
                moveOfcomputer[timer].kuzeydogu=1;
        }
    }
}    
    

//Player iconu bittikten sonra sonunda computer iconu olanlar secilir
void Reversi::forComputerIsItLegalMove(move_feature_t moveOfcomputer[]) const
{
    int i=0;
    int endTheBoard=1; // Boardin bitip bitmedigini kontrol amacli
    
    //CEVRESINDE PLAYER ICONU OLANLARDA ILERLENIR
    //EGER SONUNDA COMPUTER ICONUNA RASTLANIRSA
    //HAMLE LEGAL BIR HAMLEDIR
    
    for(int timer=0; timer<getNumberOfComputerMove(); ++timer)
    {
        //KUZEY
        if(moveOfcomputer[timer].kuzey)
        {         
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].line-1-i<0)    
                endTheBoard=0; 
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line-1-i]
                    [moveOfcomputer[timer].column].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].line-1-i<0)
                    endTheBoard=0;
            }
            
            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line-1-i]
                    [moveOfcomputer[timer].column].getSembol()==computer_sembol)
            {   
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //KUZEYBATI
        if(moveOfcomputer[timer].kuzeybati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].line-1-i<0 || 
               moveOfcomputer[timer].column-1-i<0)
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line-1-i]
                [moveOfcomputer[timer].column-1-i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].line-1-i<0 || 
                   moveOfcomputer[timer].column-1-i<0)
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line-1-i]
                [moveOfcomputer[timer].column-1-i].getSembol()==computer_sembol)
            {       
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //BATI
        if(moveOfcomputer[timer].bati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].column-1-i<0)
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line]
                [moveOfcomputer[timer].column-1-i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].column-1-i<0)
                    endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line]
                [moveOfcomputer[timer].column-1-i].getSembol()==computer_sembol)
            {       
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //GUNEYBATI
        if(moveOfcomputer[timer].guneybati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].line+1+i>=getBoardWidth() || 
               moveOfcomputer[timer].column-1-i<0)
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line+1+i]
                [moveOfcomputer[timer].column-1-i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].line+1+i>=getBoardWidth() || 
                   moveOfcomputer[timer].column-1-i<0)
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line+1+i]
                [moveOfcomputer[timer].column-1-i].getSembol()==computer_sembol)
            {       
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //GUNEY
        if(moveOfcomputer[timer].guney)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].line+1+i>=getBoardWidth())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line+1+i]
                    [moveOfcomputer[timer].column].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].line+1+i>=getBoardWidth())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line+1+i]
                    [moveOfcomputer[timer].column].getSembol()==computer_sembol)
            {       
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }

        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //GUNEYDOGU
        if(moveOfcomputer[timer].guneydogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].line+1+i>=getBoardWidth() || 
               moveOfcomputer[timer].column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line+1+i]
                  [moveOfcomputer[timer].column+1+i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].line+1+i>=getBoardWidth() || 
                   moveOfcomputer[timer].column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line+1+i]
                [moveOfcomputer[timer].column+1+i].getSembol()==computer_sembol)
            {       
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }

        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //DOGU
        if(moveOfcomputer[timer].dogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line]
                [moveOfcomputer[timer].column+1+i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line]
                [moveOfcomputer[timer].column+1+i].getSembol()==computer_sembol)
            {       
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //KUZEYDOGU
        if(moveOfcomputer[timer].kuzeydogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(moveOfcomputer[timer].line-1-i<0 || 
               moveOfcomputer[timer].column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[moveOfcomputer[timer].line-1-i]
                [moveOfcomputer[timer].column+1+i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(moveOfcomputer[timer].line-1-i<0 || 
                   moveOfcomputer[timer].column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[moveOfcomputer[timer].line-1-i]
                [moveOfcomputer[timer].column+1+i].getSembol()==computer_sembol)
            {       
                moveOfcomputer[timer].legal=1;
                moveOfcomputer[timer].total_gain+=i;
            }

        }
        
        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1; 
    }
}


//En akilli hareket bulunur
void Reversi::forComputerWhichOneIsSmartestMove(move_feature_t moveOfcomputer[])
{
    int timer=0;
    int check_corner=0;//Koselerde hamle varsa 1 yoksa 0 olur;
    int corner_total_gain=0;//Kosedeki noktanin toplam kazanci
    
    while(timer<getNumberOfComputerMove())
    {
        //EN COK KAZANCLI OLAN VE KOSEDE OLAN SECILIR
        
        //SOL UST KOSE UYGUNSA
        //SOL ALT KOSE UYGUNSA
        //SAG UST KOSE UYGUNSA
        //SAG ALT KOSE UYGUNSA
        if((moveOfcomputer[timer].line==0 && moveOfcomputer[timer].column==0) ||
           (moveOfcomputer[timer].line==(getBoardHeight()-1) && 
            moveOfcomputer[timer].column==0) ||
           (moveOfcomputer[timer].line==0 && 
            moveOfcomputer[timer].column==(getBoardWidth()-1)) ||
           (moveOfcomputer[timer].line==(getBoardHeight()-1) && 
            moveOfcomputer[timer].column==(getBoardWidth()-1)))
        {      
            if((moveOfcomputer[timer].total_gain)>corner_total_gain)
            {
                corner_total_gain=moveOfcomputer[timer].total_gain;
                check_corner=1;
                
                (bestMoveForComputer.legal)=moveOfcomputer[timer].legal;
                (bestMoveForComputer.total_gain)=moveOfcomputer[timer].total_gain;
                (bestMoveForComputer.line)=moveOfcomputer[timer].line;
                (bestMoveForComputer.column)=moveOfcomputer[timer].column;
                (bestMoveForComputer.kuzey)=moveOfcomputer[timer].kuzey;
                (bestMoveForComputer.kuzeybati)=moveOfcomputer[timer].kuzeybati;
                (bestMoveForComputer.bati)=moveOfcomputer[timer].bati;
                (bestMoveForComputer.guneybati)=moveOfcomputer[timer].guneybati;
                (bestMoveForComputer.guney)=moveOfcomputer[timer].guney;
                (bestMoveForComputer.guneydogu)=moveOfcomputer[timer].guneydogu;
                (bestMoveForComputer.dogu)=moveOfcomputer[timer].dogu;
                (bestMoveForComputer.kuzeydogu)=moveOfcomputer[timer].kuzeydogu;
            }  
        }
        
        
        //EGER KOSEDE OLAN YOKSA
        //EN COK KAZANCLI OLAN SECILIR
        if(!check_corner)
        {
            if((moveOfcomputer[timer].total_gain)>(bestMoveForComputer.total_gain))
            {
                (bestMoveForComputer.legal)=moveOfcomputer[timer].legal;
                (bestMoveForComputer.total_gain)=moveOfcomputer[timer].total_gain;
                (bestMoveForComputer.line)=moveOfcomputer[timer].line;
                (bestMoveForComputer.column)=moveOfcomputer[timer].column;
                (bestMoveForComputer.kuzey)=moveOfcomputer[timer].kuzey;
                (bestMoveForComputer.kuzeybati)=moveOfcomputer[timer].kuzeybati;
                (bestMoveForComputer.bati)=moveOfcomputer[timer].bati;
                (bestMoveForComputer.guneybati)=moveOfcomputer[timer].guneybati;
                (bestMoveForComputer.guney)=moveOfcomputer[timer].guney;
                (bestMoveForComputer.guneydogu)=moveOfcomputer[timer].guneydogu;
                (bestMoveForComputer.dogu)=moveOfcomputer[timer].dogu;
                (bestMoveForComputer.kuzeydogu)=moveOfcomputer[timer].kuzeydogu;
            }
        }
        ++timer;
    }
}
    
//En akilli hareket uygulanilir
void Reversi::forComputerDoBestMove()
{
    if(bestMoveForComputer.legal)
    {
        //YASAYAN HUCRE SAYISI 1 ARTIRILIR
        setLivingCellsNumber('+', 1);
        setLocalLiveCellsNumber('+',1);
        
        
        //SUTUN DEGERININ SAYI KARSILIGININ BULUNMASI
        vector<char> digitLetter;// sayilarin basamaklarinin harf karsiligini 
                             // tutan vector
        char letter; // harfleri tutan degisken
        int number=bestMoveForComputer.column+1; // bestMoveForComputer.column 
                                               //degerini tutan gecici degisken
        int totalDigitsNumber=0; //numberin digit sayisini tutan degisken
        int digit; // rakamlari tutan degisken
        
        int endTheBoard=1; // Boardin bitip bitmedigini kontrol amacli

        while(number)
        {
            digit=number%10; //sayinin son basamagi bulunur.
            number=number/10; //sayi 10 a bolunur.
            letter=digitTranslateLetter(digit); // basamagin harf karsiligi
                                                    // bulunur.
            digitLetter.push_back(letter); // vektore bulunan harf eklenir.
            ++totalDigitsNumber; // Sayinin kac basamakli oldugu bulunur.
        }

        
        //Computerin yaptigi hareket
        cout << endl << "The computer's move is "
             << bestMoveForComputer.line+1; // (row)
        for(int j=totalDigitsNumber-1; j>=0 ; --j)
            cout << digitLetter[j];//Sayinin harf karsiligi yazilir(columb)

        //vector sifirlanir
        digitLetter.clear();
        

        
        int i=1, temp_i=0;
        
        //ICONLARIN DEGISMESI
        
        //KUZEY
        if(bestMoveForComputer.kuzey)
        {     
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.line-1-i<0)    
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line-1-i]
                    [bestMoveForComputer.column].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.line-1-i<0)    
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line-1-i]
                    [bestMoveForComputer.column].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line-1-temp_i]
                         [bestMoveForComputer.column].setSembol(2);
                    ++temp_i;
                }
            }
        }

        
        //DEGERLER SIFIRLANIR
        i=1, temp_i=0; endTheBoard=1;

        //KUZEYBATI
        if(bestMoveForComputer.kuzeybati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.line-1-i<0 || 
               bestMoveForComputer.column-1-i<0)
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line-1-i]
                    [bestMoveForComputer.column-1-i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.line-1-i<0 || 
                   bestMoveForComputer.column-1-i<0)
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line-1-i]
                [bestMoveForComputer.column-1-i].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line-1-temp_i]
                         [bestMoveForComputer.column-1-temp_i].setSembol(2);
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0; endTheBoard=1;

        //BATI
        if(bestMoveForComputer.bati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.column-1-i<0)
                    endTheBoard=0;
            
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line]
                [bestMoveForComputer.column-1-i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.column-1-i<0)
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line]
                [bestMoveForComputer.column-1-i].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line]
                         [bestMoveForComputer.column-1-temp_i].setSembol(2);
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0; endTheBoard=1;

        //GUNEYBATI
        if(bestMoveForComputer.guneybati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.line+1+i>=getBoardWidth() || 
               bestMoveForComputer.column-1-i<0)
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line+1+i]
                    [bestMoveForComputer.column-1-i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.line+1+i>=getBoardWidth() || 
                   bestMoveForComputer.column-1-i<0)
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line+1+i]
                [bestMoveForComputer.column-1-i].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line+1+temp_i]
                         [bestMoveForComputer.column-1-temp_i].setSembol(2);
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0; endTheBoard=1;

        //GUNEY
        if(bestMoveForComputer.guney)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.line+1+i>=getBoardWidth())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line+1+i]
                    [bestMoveForComputer.column].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.line+1+i>=getBoardWidth())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line+1+i]
                    [bestMoveForComputer.column].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line+1+temp_i]
                         [bestMoveForComputer.column].setSembol(2);
                    ++temp_i;
                }
            }

        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0; endTheBoard=1;

        //GUNEYDOGU
        if(bestMoveForComputer.guneydogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.line+1+i>=getBoardWidth() || 
               bestMoveForComputer.column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line+1+i]
                    [bestMoveForComputer.column+1+i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.line+1+i>=getBoardWidth() || 
                   bestMoveForComputer.column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line+1+i]
                [bestMoveForComputer.column+1+i].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line+1+temp_i]
                         [bestMoveForComputer.column+1+temp_i].setSembol(2);
                    ++temp_i;
                }
            }

        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0; endTheBoard=1;

        //DOGU
        if(bestMoveForComputer.dogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line]
                [bestMoveForComputer.column+1+i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line]
                [bestMoveForComputer.column+1+i].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line]
                         [bestMoveForComputer.column+1+temp_i].setSembol(2);
                    ++temp_i;
                }
            }
        }

        //DEGERLER SIFIRLANIR
        i=1, temp_i=0; endTheBoard=1;

        //KUZEYDOGU
        if(bestMoveForComputer.kuzeydogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(bestMoveForComputer.line-1-i<0 || 
               bestMoveForComputer.column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[bestMoveForComputer.line-1-i]
                    [bestMoveForComputer.column+1+i].getSembol()==player_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(bestMoveForComputer.line-1-i<0 || 
                   bestMoveForComputer.column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[bestMoveForComputer.line-1-i]
                [bestMoveForComputer.column+1+i].getSembol()==computer_sembol)
            {       
                gameCells[bestMoveForComputer.line]
                     [bestMoveForComputer.column].setSembol(2);
            
                while(temp_i<i)
                {
                    gameCells[bestMoveForComputer.line-1-temp_i]
                         [bestMoveForComputer.column+1+temp_i].setSembol(2);
                    ++temp_i;
                }
            }

        }
    }
    
    else
    {
        cout << endl << "The computer does not have a legal move";
        setComputerCanMove(0);
    }

}

//
//
//FOR COMPUTER******************************************************************












//FOR PLAYER********************************************************************
//
//Playerdan mantikli hamle alan fonksiyon
//Nokta olan yerler kabul edilir
//Legal bir hamle ise 1 dondurur
//Legal bir hamle degilse 0 dondurur.
int Reversi::forPlayerIsItEmptyIcon(const int &cellPositionX, 
                                         const int &cellPositionY) const
{    
    int isItEmptyIcon;
    
    //EGER LEGAL OLMAYAN DEGER GIRILIRSE
    if(cellPositionX<0 || cellPositionX>=getBoardWidth() ||
          cellPositionY<0 || cellPositionY>=getBoardHeight() ||
          gameCells[cellPositionX][cellPositionY].getSembol()!=empty_sembol)
    {  
        isItEmptyIcon=0;
    }
    
    else
    {
        isItEmptyIcon=1;
    }
    
    return isItEmptyIcon;
}


//Playerin hareketinin uygunlugunu kontrol eden
//nokta olan yerlerin cevresi taranir ve legal olup olmadigi kontrol edilir
//Legal bir hamle ise uygulanilir.
//Legal bir hamle ise 1 dondurur
//Legal bir hamle degilse 0 dondurur.
int Reversi::forPlayerIsItLegalMove(const int &cellPositionX,
                                const int &cellPositionY)
{
    int check_legal=0; //EGER 1 RETURN EDILIRSE LEGAL HAMLEDIR
                       //EGER 0 RETURN EDILIRSE LEGAL OLMAYAN HAMLEDIR 
    
    int endTheBoard=1; // Boardin bitip bitmedigini kontrol amacli
    
    move_feature_t playerMove; // Hamlelerin yonunu tutan struct
    
    //STRUCT SIFIRLANIR
    playerMove.kuzey=0;
    playerMove.kuzeybati=0;
    playerMove.bati=0;
    playerMove.guneybati=0;
    playerMove.guney=0;
    playerMove.guneydogu=0;
    playerMove.dogu=0;
    playerMove.kuzeydogu=0;
    
    
    int i=1, temp_i=0;
    
    //GIRILEN HAMLENIN CEVRESI KONTROL EDILIR
    
    //KUZEY
    if(cellPositionX!=0)
    {
        if(gameCells[cellPositionX-1]
                    [cellPositionY].getSembol()==computer_sembol)
                        playerMove.kuzey=1;
    }

    //KUZEYBATI
    if(cellPositionX!=0 && cellPositionY!=0)
    {
        if(gameCells[cellPositionX-1]
                    [cellPositionY-1].getSembol()==computer_sembol)
                        playerMove.kuzeybati=1;
    }

    //BATI
    if(cellPositionY!=0)
    {
        if(gameCells[cellPositionX]
                    [cellPositionY-1].getSembol()==computer_sembol)
                        playerMove.bati=1;
    }        

    //GUNEYBATI
    if(cellPositionX<getBoardWidth()-1 && cellPositionY!=0 )
    {
        if(gameCells[cellPositionX+1]
                    [cellPositionY-1].getSembol()==computer_sembol)
                        playerMove.guneybati=1;
    }

    //GUNEY
    if(cellPositionX!=getBoardWidth()-1)
    {
        if(gameCells[cellPositionX+1]
                    [cellPositionY].getSembol()==computer_sembol)
                        playerMove.guney=1;
    }

    //GUNEYDOGU
    if(cellPositionX!=getBoardWidth()-1 && cellPositionY!=getBoardHeight()-1)
    {
        if(gameCells[cellPositionX+1]
                    [cellPositionY+1].getSembol()==computer_sembol)
                        playerMove.guneydogu=1;
    }

    //DOGU
    if(cellPositionY!=getBoardHeight()-1)
    {
        if(gameCells[cellPositionX]
                    [cellPositionY+1].getSembol()==computer_sembol)
                        playerMove.dogu=1;
    }

    //KUZEYDOGU
    if(cellPositionX!=0 && cellPositionY!=getBoardHeight()-1)
    {
        if(gameCells[cellPositionX-1]
                    [cellPositionY+1].getSembol()==computer_sembol)
                        playerMove.kuzeydogu=1;
    }
    
     
    //CEVRESINDE COMPUTER ICONU OLANLARDA ILERLENIR
    //EGER SONUNDA KENDINDEN OLAN ICONA RASTLANIRSA
    //HAMLE LEGAL BIR HAMLEDIR
    
    //KUZEY
    if(playerMove.kuzey)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionX-1-i<0)    
                endTheBoard=0;
        
        while(endTheBoard==1 && 
        gameCells[cellPositionX-1-i][cellPositionY].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionX-1-i<0)    
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
        gameCells[cellPositionX-1-i][cellPositionY].getSembol()==player_sembol)
        {       
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX-1-temp_i][cellPositionY].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0; endTheBoard=1;
    
    //KUZEYBATI
    if(playerMove.kuzeybati)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionX-1-i<0 || 
            cellPositionY-1-i<0)
                        endTheBoard=0;
        
        while(endTheBoard==1 && 
    gameCells[cellPositionX-1-i][cellPositionY-1-i].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionX-1-i<0 || 
               cellPositionY-1-i<0)
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
    gameCells[cellPositionX-1-i][cellPositionY-1-i].getSembol()==player_sembol)
        {       
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX-1-temp_i][cellPositionY-1-temp_i].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0; endTheBoard=1;
    
    //BATI
    if(playerMove.bati)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionY-1-i<0)
                endTheBoard=0;
        
        while(endTheBoard==1 && 
        gameCells[cellPositionX][cellPositionY-1-i].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionY-1-i<0)
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
        gameCells[cellPositionX][cellPositionY-1-i].getSembol()==player_sembol)
        {       
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX][cellPositionY-1-temp_i].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0; endTheBoard=1;
    
    //GUNEYBATI
    if(playerMove.guneybati)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionX+1+i>=getBoardWidth() || 
           cellPositionY-1-i<0)
                endTheBoard=0;
        
        while(endTheBoard==1 && 
    gameCells[cellPositionX+1+i][cellPositionY-1-i].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionX+1+i>=getBoardWidth() || 
               cellPositionY-1-i<0)
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
        gameCells[cellPositionX+1+i][cellPositionY-1-i].getSembol()==player_sembol)
        {       
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX+1+temp_i][cellPositionY-1-temp_i].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0; endTheBoard=1;
    
    //GUNEY
    if(playerMove.guney)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionX+1+i>=getBoardWidth())
                endTheBoard=0;
        
        while(endTheBoard==1 && 
        gameCells[cellPositionX+1+i][cellPositionY].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionX+1+i>=getBoardWidth())
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
        gameCells[cellPositionX+1+i][cellPositionY].getSembol()==player_sembol)
        {       
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX+1+temp_i][cellPositionY].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0; endTheBoard=1;
    
    //GUNEYDOGU
    if(playerMove.guneydogu)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionX+1+i>=getBoardWidth() || 
           cellPositionY+1+i>=getBoardHeight())
                endTheBoard=0;
        
        while(endTheBoard==1 && 
    gameCells[cellPositionX+1+i][cellPositionY+1+i].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionX+1+i>=getBoardWidth() || 
               cellPositionY+1+i>=getBoardHeight())
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
    gameCells[cellPositionX+1+i][cellPositionY+1+i].getSembol()==player_sembol)
        {       
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX+1+temp_i][cellPositionY+1+temp_i].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0; endTheBoard=1;
    
    //DOGU
    if(playerMove.dogu)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionY+1+i>=getBoardHeight())
                endTheBoard=0;
        
        while(endTheBoard==1 && 
        gameCells[cellPositionX][cellPositionY+1+i].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionY+1+i>=getBoardHeight())
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
        gameCells[cellPositionX][cellPositionY+1+i].getSembol()==player_sembol)
        {      
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX][cellPositionY+1+temp_i].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    }
    
    //DEGERLER SIFIRLANIR
    i=1, temp_i=0; endTheBoard=1;
    
    //KUZEYDOGU
    if(playerMove.kuzeydogu)
    {
        //BOARD SINIR KONTROL MERKEZI
        if(cellPositionX-1-i<0 || 
           cellPositionY+1+i>=getBoardHeight())
                endTheBoard=0;
        
        while(endTheBoard==1 && 
        gameCells[cellPositionX-1-i][cellPositionY+1+i].getSembol()==computer_sembol)
        {
            ++i;
            
            //BOARD SINIR KONTROL MERKEZI
            if(cellPositionX-1-i<0 || 
               cellPositionY+1+i>=getBoardHeight())
                    endTheBoard=0;
        }
        
        if(endTheBoard==1 && 
        gameCells[cellPositionX-1-i][cellPositionY+1+i].getSembol()==player_sembol)
        {       
            gameCells[cellPositionX][cellPositionY].setSembol(1);
            
            while(temp_i<i)
            {
                gameCells[cellPositionX-1-temp_i][cellPositionY+1+temp_i].setSembol(1);
                ++temp_i;
            }
            
            check_legal=1;
        }
    
    }
    
    //HAMLE YAPILDIYSA LIVECELLSNUMBER 1 ARTTIRILIR
    if(check_legal)
    {
        setLivingCellsNumber('+', 1);
        setLocalLiveCellsNumber('+',1);
    }

    return check_legal;

}

//
//
//FOR PLAYER********************************************************************

















//DOES PLAYER HAVE MOVE*****************************************************
//
//
//Player yapacak hamleye sahip mi degil mi
int Reversi::doesPlayerHaveMove()
{
    setNumberOfPlayerMove(0);
    setPlayerCanMove(0);
    move_feature_t playerMovetest[getBoardHeight()*getBoardWidth()+1];
    
    //Struct degerleri sifirlanir
    doesPlayerHaveMoveResetStructs(playerMovetest);

    //Player'a ait olan iconlar bulunur
    doesPlayerHaveMoveWhichOnesIsPlayerIcon(playerMovetest);

    //Player'a ait olan hucrelerin cevreleri kontrol edilir
    //cevresinde computer iconlari olanlar secilir
    doesPlayerHaveMoveWhichOnesHasComputerIconOnAround(playerMovetest);

    //computer iconu bittikten sonra sonunda nokta (empty) iconu olanlar varsa
    //player hamle yapabilir anlamina gelmektedir
    doesPlayerHaveMoveIsItLegalMove(playerMovetest);
  
    //Eger player yapilabilir bir hamleye sahip ise playerCanMove 1 olarak
    //sahip degil ise playerCanMove 0 olarak return edilir.
    return getPlayerCanMove();


}

//Struct degerleri sifirlanir
void Reversi::doesPlayerHaveMoveResetStructs(
                                                move_feature_t playerMovetest[]) const
{
    //DEGERLER SIFIRLANIR
    for(int timer=0; timer<=(getBoardHeight()*getBoardWidth()); ++timer)
    {
        playerMovetest[timer].legal=0;
        playerMovetest[timer].total_gain=0;
        playerMovetest[timer].column=0;
        playerMovetest[timer].line=0;
        playerMovetest[timer].kuzey=0;
        playerMovetest[timer].kuzeybati=0;
        playerMovetest[timer].bati=0;
        playerMovetest[timer].guneybati=0;
        playerMovetest[timer].guney=0;
        playerMovetest[timer].guneydogu=0;
        playerMovetest[timer].dogu=0;
        playerMovetest[timer].kuzeydogu=0;
    }
}

//Player'a ait olan iconlar bulunur
void Reversi::doesPlayerHaveMoveWhichOnesIsPlayerIcon(
                                                move_feature_t playerMovetest[])
{
    int timer=0;
    
    for(int i=0; i<getBoardWidth();++i)
        for(int j=0; j<getBoardHeight(); ++j)
            if(gameCells[i][j].getSembol()==player_sembol)
            {
               playerMovetest[timer].line=i;
               playerMovetest[timer].column=j;
               ++timer;
               ++numberOfPlayerMove;
            }
}

//Player'a ait olan hucrelerin cevreleri kontrol edilir
//cevresinde computer iconlari olanlar secilir
void Reversi::doesPlayerHaveMoveWhichOnesHasComputerIconOnAround(
                                            move_feature_t playerMovetest[]) const
{
    //GIRILEN HAMLENIN CEVRESI KONTROL EDILIR
    for(int timer=0; timer<getNumberOfPlayerMove(); ++timer)
    {
        //KUZEY
        if(playerMovetest[timer].line!=0)
        {
            if(gameCells[playerMovetest[timer].line-1]
                    [playerMovetest[timer].column].getSembol()==computer_sembol)
                playerMovetest[timer].kuzey=1;
        }

        //KUZEYBATI
        if(playerMovetest[timer].line!=0 && playerMovetest[timer].column!=0)
        {
            if(gameCells[playerMovetest[timer].line-1]
                [playerMovetest[timer].column-1].getSembol()==computer_sembol)
                playerMovetest[timer].kuzeybati=1;
        }

        //BATI
        if(playerMovetest[timer].column!=0)
        {
            if(gameCells[playerMovetest[timer].line]
                [playerMovetest[timer].column-1].getSembol()==computer_sembol)
                playerMovetest[timer].bati=1;
        }        

        //GUNEYBATI
        if(playerMovetest[timer].line<getBoardWidth()-1 && 
                playerMovetest[timer].column!=0 )
        {
            if(gameCells[playerMovetest[timer].line+1]
                [playerMovetest[timer].column-1].getSembol()==computer_sembol)
                playerMovetest[timer].guneybati=1;
        }

        //GUNEY
        if(playerMovetest[timer].line!=getBoardWidth()-1)
        {
            if(gameCells[playerMovetest[timer].line+1]
                [playerMovetest[timer].column].getSembol()==computer_sembol)
                playerMovetest[timer].guney=1;
        }

        //GUNEYDOGU
        if(playerMovetest[timer].line!=getBoardWidth()-1 && 
                playerMovetest[timer].column!=getBoardHeight()-1)
        {
            if(gameCells[playerMovetest[timer].line+1]
                [playerMovetest[timer].column+1].getSembol()==computer_sembol)
                playerMovetest[timer].guneydogu=1;
        }

        //DOGU
        if(playerMovetest[timer].column!=getBoardHeight()-1)
        {
            if(gameCells[playerMovetest[timer].line]
                [playerMovetest[timer].column+1].getSembol()==computer_sembol)
                playerMovetest[timer].dogu=1;
        }

        //KUZEYDOGU
        if(playerMovetest[timer].line!=0 && 
                playerMovetest[timer].column!=getBoardHeight()-1)
        {
            if(gameCells[playerMovetest[timer].line-1]
                [playerMovetest[timer].column+1].getSembol()==computer_sembol)
                playerMovetest[timer].kuzeydogu=1;
        }
    }
}

//computer iconu bittikten sonra sonunda nokta (empty) iconu olanlar varsa
//player hamle yapabilir anlamina gelmektedir
void Reversi::doesPlayerHaveMoveIsItLegalMove(
                                            move_feature_t playerMovetest[])
{
    int i=0;
    int endTheBoard=1; // Boardin bitip bitmedigini kontrol amacli
      
    //CEVRESINDE COMPUTER ICONU OLANLARDA ILERLENIR
    //EGER SONUNDA EMPTY ICONUNA RASTLANIRSA
    //HAMLE LEGAL BIR HAMLEDIR
    
    for(int timer=0; timer<getNumberOfPlayerMove(); ++timer)
    {
        //KUZEY
        if(playerMovetest[timer].kuzey)
        {   
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].line-1-i<0)    
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[playerMovetest[timer].line-1-i]
                    [playerMovetest[timer].column].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].line-1-i<0)    
                       endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line-1-i]
                    [playerMovetest[timer].column].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //KUZEYBATI
        if(playerMovetest[timer].kuzeybati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].line-1-i<0 || 
               playerMovetest[timer].column-1-i<0)
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[playerMovetest[timer].line-1-i]
            [playerMovetest[timer].column-1-i].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].line-1-i<0 || 
                   playerMovetest[timer].column-1-i<0)
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line-1-i]
            [playerMovetest[timer].column-1-i].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //BATI
        if(playerMovetest[timer].bati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].column-1-i<0)
                    endTheBoard=0;

            while(endTheBoard==1 && gameCells[playerMovetest[timer].line]
            [playerMovetest[timer].column-1-i].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].column-1-i<0)
                    endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line]
            [playerMovetest[timer].column-1-i].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //GUNEYBATI
        if(playerMovetest[timer].guneybati)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].line+1+i>=getBoardWidth() || 
               playerMovetest[timer].column-1-i<0)
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[playerMovetest[timer].line+1+i]
            [playerMovetest[timer].column-1-i].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].line+1+i>=getBoardWidth() || 
                   playerMovetest[timer].column-1-i<0)
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line+1+i]
            [playerMovetest[timer].column-1-i].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //GUNEY
        if(playerMovetest[timer].guney)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].line+1+i>=getBoardWidth())
                    endTheBoard=0;

            
            while(endTheBoard==1 && gameCells[playerMovetest[timer].line+1+i]
            [playerMovetest[timer].column].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].line+1+i>=getBoardWidth())
                    endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line+1+i]
            [playerMovetest[timer].column].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }

        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //GUNEYDOGU
        if(playerMovetest[timer].guneydogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].line+1+i>=getBoardWidth() || 
               playerMovetest[timer].column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[playerMovetest[timer].line+1+i]
            [playerMovetest[timer].column+1+i].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].line+1+i>=getBoardWidth() || 
                   playerMovetest[timer].column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line+1+i]
            [playerMovetest[timer].column+1+i].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }

        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //DOGU
        if(playerMovetest[timer].dogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[playerMovetest[timer].line]
            [playerMovetest[timer].column+1+i].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line]
            [playerMovetest[timer].column+1+i].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }
        }

        //DEGERLER SIFIRLANIR
        i=0; endTheBoard=1;

        //KUZEYDOGU
        if(playerMovetest[timer].kuzeydogu)
        {
            //BOARD SINIR KONTROL MERKEZI
            if(playerMovetest[timer].line-1-i<0 || 
               playerMovetest[timer].column+1+i>=getBoardHeight())
                    endTheBoard=0;
            
            while(endTheBoard==1 && gameCells[playerMovetest[timer].line-1-i]
            [playerMovetest[timer].column+1+i].getSembol()==computer_sembol)
            {
                ++i;
                
                //BOARD SINIR KONTROL MERKEZI
                if(playerMovetest[timer].line-1-i<0 || 
                   playerMovetest[timer].column+1+i>=getBoardHeight())
                        endTheBoard=0;
            }

            if(endTheBoard==1 && gameCells[playerMovetest[timer].line-1-i]
            [playerMovetest[timer].column+1+i].getSembol()==empty_sembol)
            {       
                setPlayerCanMove(1);
            }

        }
        
        i=0; endTheBoard=1;
    }
}
//
//
//DOES PLAYER HAVE MOVE*****************************************************















//MATADORS**********************************************************************
//
//
void Reversi::setGameCells()
{
    for(int i=0; i<getBoardWidth() ;++i)
            for(int j=0; j<getBoardHeight() ;++j)
            {
                gameCells[i][j].setX(i);
                gameCells[i][j].setY(j);
                gameCells[i][j].setSembol(0);
            }
            
    //OYUN BASI "X" VE "O" YERLESTIRILIR
    int computerSembolLocationX=getBoardWidth()/2-1;
    int computerSembolLocationY=getBoardHeight()/2-1;
    
    if(getBoardWidth()>1 && getBoardHeight()>1)
    {
        liveCellsNumber -= getLocalLiveCellsNumber();
        setLocalLiveCellsNumber(0);
        setLivingCellsNumber('+', 4);
        setLocalLiveCellsNumber('+',4);
       
        gameCells[computerSembolLocationX][computerSembolLocationY].setSembol(2);
        gameCells[computerSembolLocationX][computerSembolLocationY+1].setSembol(1);
        gameCells[computerSembolLocationX+1][computerSembolLocationY+1].setSembol(2);
        gameCells[computerSembolLocationX+1][computerSembolLocationY].setSembol(1);
        setPlayerScore(2);
        setComputerScore(2);
    }
    
    else
    {
        if(getBoardWidth()==1 && getBoardHeight()>1 )
        {
            liveCellsNumber -= getLocalLiveCellsNumber();
            setLocalLiveCellsNumber(0);
            setLivingCellsNumber('+', 2);
            setLocalLiveCellsNumber('+',2);
            gameCells[0][computerSembolLocationY].setSembol(2);
            gameCells[0][computerSembolLocationY+1].setSembol(1);
            setPlayerScore(1);
            setComputerScore(1);
        }
        else if(getBoardHeight()==1 && getBoardWidth()>1)
        {
            liveCellsNumber -= getLocalLiveCellsNumber();
            setLocalLiveCellsNumber(0);
            setLivingCellsNumber('+', 2);
            setLocalLiveCellsNumber('+',2);
            gameCells[computerSembolLocationX][0].setSembol(2);
            gameCells[computerSembolLocationX+1][0].setSembol(1); 
            setPlayerScore(1);
            setComputerScore(1);
        }
        else
        {
            gameCells[0][0].setSembol(2);
            
            liveCellsNumber -= getLocalLiveCellsNumber();
            setLocalLiveCellsNumber(0);
            setLivingCellsNumber('+', 1);
            setLocalLiveCellsNumber('+',2);
            setPlayerScore(0);
            setComputerScore(1);
        }
    }
}


void Reversi::setboardHeight(const int &newBoardHeight)
{
    if(newBoardHeight<=0)
    {
        cout << endl << "Illegal Height Size" << endl << "Game Over";
        exit(1);
    }
    
    else
        boardHeight=newBoardHeight;
}


void Reversi::setboardWidth(const int &newBoardWidth)
{
    if(newBoardWidth<=0)
    {
        cout << endl << "Illegal Widht Size" << endl << "Game Over";
        exit(1);
    }
    
    else
        boardWidth=newBoardWidth;
}

// set localLiveCellsNumber
void Reversi::setLocalLiveCellsNumber(const char &sembol, const int &number)
{
    if(sembol=='+')
        localLiveCellsNumber+=number;
    
    else if(sembol=='-')
        localLiveCellsNumber-=number;
}

//A static function that set the number of living cells in all the games
int Reversi::setLivingCellsNumber(const char &sembol, const int &number)
{
    if(sembol=='+')
        liveCellsNumber+=number;
    
    else if(sembol=='-')
        liveCellsNumber-=number;
}

//
//
//SETTERS***********************************************************************




















//OTHER STAFF***************************************************************
//
//
//Girilen width ve height degerlerini kontrol amacli
int Reversi::checkBoardSizes(int boardWidthorHeight) const
{
    if(boardWidthorHeight<=0)
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
        case 1:
           letter='A';
           break;
        case 2:
            letter='B';
            break;
        case 3:
           letter='C';
           break;
        case 4:
            letter='D';
            break;
        case 5:
           letter='E';
           break;
        case 6:
            letter='F';
            break;
        case 7:
           letter='G';
           break;
        case 8:
            letter='H';
            break;
        case 9:
           letter='I';
           break;
        case 0:
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
           digit=1;
           break;
        case 'B':
            digit=2;
            break;
        case 'C':
           digit=3;
           break;
        case 'D':
            digit=4;
            break;
        case 'E':
           digit=5;
           break;
        case 'F':
            digit=6;
            break;
        case 'G':
           digit=7;
           break;
        case 'H':
            digit=8;
            break;
        case 'I':
           digit=9;
           break;
        case 'J':
            digit=0;
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
    int digitNumber=1; // basamagin degerini (birler, onlar vb.) tutar.
    int cellPositionYNumber=0; // cell Position Y Stringinin sayi karsiligi
    
    for (string::iterator i=cellPositionYString.end()-1; 
                            i!=cellPositionYString.begin()-1; --i)
    {    
        digit=letterTranslateDigit(*i); // harfin sayi karsiligi bulunur.
        cellPositionYNumber+=digit*digitNumber; // bulunan sayi 
                                                //cellPositionYNumber eklenir.
        digitNumber = digitNumber*10; // basamak degeri arttirilir
    }

    return cellPositionYNumber;
}

//SCOREBOARD
void Reversi::scoreboard()
{
    int newComputerScore=0;
    int newPlayerScore=0;
    
    //Butun hucreler kontrol edilir
    for(int i=0;i<(getBoardWidth());++i)
    {
        for(int j=0;j<(getBoardHeight());++j)
        {
            //Player'a ait olan yerler icin
            //Player score 1 arttirilir
            if(gameCells[i][j].getSembol()==player_sembol)
                ++newPlayerScore;
            
            //Computere ait olan yerler icin
            //Computer score 1 arttirilir
            else if(gameCells[i][j].getSembol()==computer_sembol)
                ++newComputerScore;
        }
    }
    
    setPlayerScore(newPlayerScore);
    setComputerScore(newComputerScore);
}
//
//
//OTHER STAFF***************************************************************