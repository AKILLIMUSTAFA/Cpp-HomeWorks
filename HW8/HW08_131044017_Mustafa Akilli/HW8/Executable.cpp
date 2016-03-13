// HW08_131044017_Mustafa_Akilli
// 
// File:   Executable.cpp
// Author: Mustafa_Akilli
//
// Created on 21 Aralik 2015 Cumartesi, 12:59 by Mustafa_Akilli
//
// Description
//
// The class Executable is a File that can be executed. 
// It has members for storing the compiler that created the executable.
//
// HW8 Executable Cpp

#include "Executable.h"

using std::endl;

namespace
{
    const static string DEFAULT_COMPILER_NAME="defaultCompiler";  
}

namespace mustafaAkilli
{ 
    //Default Contructor
    Executable::Executable(const string &newName,
                const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission, 
                const string &newCompilerName):
                File(newName,newOwner,newSize,newLastModificaiton,newPermission)
    {
        setCompilerName(newCompilerName);
    }
        
    //No Parameter Contructor
    Executable::Executable():
                File()
    {
        setCompilerName(DEFAULT_COMPILER_NAME);
    }
        
    //Copy Contructor
    Executable::Executable(File* otherExecutable):
                File(otherExecutable->getName(),otherExecutable->getOwner(),
                otherExecutable->getSize(),otherExecutable->getLastModificaiton(),
                otherExecutable->getPermission())
    {
        Executable* temp= dynamic_cast<Executable* >(otherExecutable);
                
        if(NULL!=dynamic_cast<Executable* >(otherExecutable))
        {
            setCompilerName(temp->getCompilerName());
        }
    }
    
    // set Compiler Name
    void Executable::setCompilerName(const string &newCompilerName)
    {
        compilerName=newCompilerName;
    }
        
    //Function ls that prints the file on the screen similar to 
    //what “ls file” does. Function ls also takes
    //parameters similar to Linux ls paramerts -l, -R, -a.
    void Executable::ls(string &lsParameters)
    {
        cout << endl << "bash:cd: " 
             << ": Not a directory " << endl; 
    }
   
    //Function cd that returns a File reference if the operation is successful.
    File& Executable::cd(File &otherFile)
    {
        cout << endl << "bash:cd: " 
             << ": Not a directory " << endl; 
        return *this;
    }
                
                
    //Function cp, copies the given file to the current file and 
    //returns true if sucessful. Otherwise, it returns false.
    bool Executable::cp(File &otherFile)
    {
        cout << endl << "bash:cd: " 
             << ": Not a directory " << endl; 
        return false;
    } 
}

