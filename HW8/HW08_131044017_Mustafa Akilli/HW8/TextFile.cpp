// HW08_131044017_Mustafa_Akilli
// 
// File:   TextFile.cpp
// Author: Mustafa_Akilli
//
// Created on 21 Aralik 2015 Cumartesi, 14:45 by Mustafa_Akilli
//
// Description
//
// The class TextFile is a File that contains text. 
// It has members for stroring the text type.
//
// HW8 TextFile Cpp

#include "TextFile.h"

using std::endl;

namespace
{
    const static string DEFAULT_TEXT_TYPE="Ascii";  
}

namespace mustafaAkilli
{ 
    //Default Contructor
    TextFile::TextFile(const string &newName,
                const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission, 
                const string &newTextType):
                File(newName,newOwner,newSize,newLastModificaiton,newPermission)
    {
        setTextType(newTextType);
    }
        
    //No Parameter Contructor
    TextFile::TextFile():
                File()
    {
        setTextType(DEFAULT_TEXT_TYPE);
    }
        
    //Copy Contructor
    TextFile::TextFile(File* otherTextFile):
                File(otherTextFile->getName(),otherTextFile->getOwner(),
                otherTextFile->getSize(),otherTextFile->getLastModificaiton(),
                otherTextFile->getPermission())
    {
        TextFile* temp= dynamic_cast<TextFile* >(otherTextFile);
                
        if(NULL!=dynamic_cast<TextFile* >(otherTextFile))
        {
            setTextType(temp->getTextType());
        }
    }
    
    // set Text Type
    void TextFile::setTextType(const string &newTextType)
    {
        textType=newTextType;
    }
        
    //Function ls that prints the file on the screen similar to 
    //what “ls file” does. Function ls also takes
    //parameters similar to Linux ls paramerts -l, -R, -a.
    void TextFile::ls(string &lsParameters)
    {
        cout << endl << "bash:cd: " 
             << ": Not a directory " << endl; 
    }
   
    //Function cd that returns a File reference if the operation is successful.
    File& TextFile::cd(File &otherFile)
    {
        cout << endl << "bash:cd: " 
             << ": Not a directory " << endl ;
        return *this;
    }
                
                
    //Function cp, copies the given file to the current file and 
    //returns true if sucessful. Otherwise, it returns false.
    bool TextFile::cp(File &otherFile)
    {
        cout << endl << "bash:cd: " 
             << ": Not a directory " << endl; 
        
        return false;
    } 
}
