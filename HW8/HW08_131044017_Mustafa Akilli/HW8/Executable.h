// HW08_131044017_Mustafa_Akilli
// 
// File:   Executable.h
// Author: Mustafa_Akilli
//
// Created on 21 Aralik 2015 Cumartesi, 12:58 by Mustafa_Akilli
//
// Description
//
// The class Executable is a File that can be executed. 
// It has members for storing the compiler that created the executable.
//
// HW8 Executable Header

#ifndef EXECUTABLE_H
#define	EXECUTABLE_H

#include "File.h"

namespace mustafaAkilli
{
    class Executable: public File
    {
    public:
        //Default Contructor
        Executable(const string &newName,const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission, 
                const string &newCompilerName);
        
        //No Parameter Contructor
        Executable();
        
        //Copy Contructor
        Executable(File* otherExecutable);
        
        
        //Setters
        void setCompilerName(const string &newCompilerName); // set Compiler Name
        
         //Getters
        string getCompilerName()const{return compilerName;} //get Compiler Name
        
        //Function ls that prints the file on the screen similar to 
        //what “ls file” does. Function ls also takes
        //parameters similar to Linux ls paramerts -l, -R, -a.
        void ls(string &lsParameters);
   
        //Function cd that returns a File reference if the operation is successful.
        File& cd(File &otherFile);
                      
        //Function cp, copies the given file to the current file and 
        //returns true if sucessful. Otherwise, it returns false.
        bool cp(File &otherFile);

    private:
        string compilerName; // Compiler Name
    };
}    
    
#endif	/* EXECUTABLE_H */



