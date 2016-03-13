// HW08_131044017_Mustafa_Akilli
// 
// File:   TextFile.h
// Author: Mustafa_Akilli
//
// Created on 21 Aralik 2015 Cumartesi, 14:43 by Mustafa_Akilli
//
// Description
//
// The class TextFile is a File that contains text. 
// It has members for stroring the text type.
//
// HW8 TextFile Header

#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include "File.h"

namespace mustafaAkilli
{
    class TextFile: public File
    {
    public:
        //Default Contructor
        TextFile(const string &newName,const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission, 
                const string &newTextType);
        
        //No Parameter Contructor
        TextFile();
        
        //Copy Contructor
        TextFile(File* otherTextFile);
        
        
        //Setters
        void setTextType(const string &newTextType); // set Text Type
        
         //Getters
        string getTextType()const{return textType;} //get Text Type
        
        
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
        string textType; // Text Type
    };
}    


#endif	/* TEXTFILE_H */

