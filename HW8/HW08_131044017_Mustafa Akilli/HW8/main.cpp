// HW08_131044017_Mustafa_Akilli
// 
// File:   main.cpp
// Author: Mustafa_Akilli
//
// Created on 19 Aralik 2015 Cumartesi, 12:45 by Mustafa_Akilli
//
// Description
//
// Test each of my classes and my functions with several examples 
// and attach my test results.
//
// HW8 main Cpp


#include "Executable.h"
#include "Directory.h"
#include "TextFile.h"

using namespace mustafaAkilli;

using std::endl;


int main(int argc, char** argv) 
{    
    
    Directory firstSimple("myFolder", "mustafa", 1453, "12.10.2002", "-rw" );
    Directory secondSimple("secondFolder", "mustafa", 100, "18.18.2004", "-r" );
    Directory thirdSimple("thirdFolder", "mustafa", 200, "11.11.2015", "-rwx" );
    Directory secretSimple(".secretFolder", "mustafa", 300, "01.01.2001", "-rw" );
    Directory king("kingoftheworld", "mustafa", 4064, "01.01.2003", "-rwx" );
    
    
    //String command
    string l ="l";
    string ls =" ";
    string a ="a";
    string la ="la";
    string Rla ="Rla";
    
    
    //Copy in firstSimple
    firstSimple.cp(secondSimple);
    firstSimple.cp(thirdSimple);
    firstSimple.cp(secretSimple);
    
    cout << endl << "First Simple Begin************************" << endl;
    
    //cout patch
    cout << endl << "secondSimple Path: "
         << firstSimple.cd(secondSimple).path() << endl
         << "thirdSimple Path: "
         << firstSimple.cd(thirdSimple).path() << endl
         << "secretSimple Path: "
         << firstSimple.cd(secretSimple).path() << endl;
    
    //ls
    cout << endl << endl << "firstSimple ls: " << endl;
    firstSimple.ls(ls);
    
    //ls -l
    cout << endl << "firstSimple ls -l: " << endl;
    firstSimple.ls(l);
    
    //ls -l -a
    cout << endl << "firstSimple ls -l -a: " << endl;
    firstSimple.ls(la);
    
    //ls -R -l -a
    cout << endl << endl << "firstSimple ls -R -l -a: " << endl;
    firstSimple.ls(Rla);
    
    cout << endl << "First Simple End************************" << endl; 
    
    
    //For King
    
    //firstSimple
    king.cp(firstSimple);
    
    //Executable
    Executable exesimple("exesimple", "mustafa", 30, "12.10.2003", "-rw" , "g++");
    king.cp(exesimple);
    
    //TextFile
    TextFile textsimple("textsimple", "mustafa", 12, "18.10.2004", "-rw" , "Unicode");
    king.cp(textsimple);
    
    cout << endl << endl << "King Begin************************" << endl;
    
    //cout patch
    cout << endl << "secondSimple Path: "
         << (king.cd(firstSimple)).cd(secondSimple).path() << endl << endl
         << "thirdSimple Path: "
         << (king.cd(firstSimple)).cd(thirdSimple).path() << endl << endl
         << "secretSimple Path: "
         << (king.cd(firstSimple)).cd(secretSimple).path() << endl;

    //ls
    cout << endl << endl << "king ls: " << endl;
    king.ls(ls);
    
    //ls -l
    cout << endl << "king ls -l: " << endl;
    king.ls(l);
    
    //ls -l -a
    cout << endl << "king ls -l -a: " << endl;
    king.ls(la);
    
    //ls -R -l -a
    cout << endl << endl << "king ls -R -l -a: " << endl;
    king.ls(Rla);
    
    cout << endl << "King End************************" << endl; 
    
    
    
    
    return 0;
}

