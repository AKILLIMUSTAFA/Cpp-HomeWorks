// HW08_131044017_Mustafa_Akilli
// 
// File:   Directory.h
// Author: Mustafa_Akilli
//
// Created on 19 Aralik 2015 Cumartesi, 21:07 by Mustafa_Akilli
//
// Description
//
// The class Directory is a special File that can hold a number of Files in it.
//
// HW8 Directory Header


#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include "File.h"

namespace mustafaAkilli
{
    class Directory: public File
    {
    public:
        //Default Contructor
        Directory(const string &newName,const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission);
        
        //No Parameter Contructor
        Directory();
        
        //Copy Contructor
        Directory(File* otherDirectory);
           
        //Setters
        void setNumberOfFiles(const int &newNumberOfFiles); // set NumberOfFiles
        void setHereFiles(); // set Here Files
        void setHereFilesSize(const int &newHereFilesSize); // set Here Files Size
        void setHereFilesCapacity(const int &newHereFilesCapacity); // set Here Files Capacity
        void increaseHereFilesCapacity(); // increase Here Files Capacity
        
        //Getters
        int getNumberOfFiles()const{return numberOfFiles;} //get Number Of Files
        File** getHereFiles()const{return hereFiles;} //get Here Files
        int getHereFilesSize()const{return hereFilesSize;} //set Here Files Size
        int getHereFilesCapacity()const{return hereFilesCapacity;} //set Here Files Capacity
        
        //Function ls that prints the file on the screen similar 
        //to what “ls file” does. Function ls also takes
        //parameters similar to Linux ls paramerts -l, -R, -a.
        void ls(string &lsParameters);
   
        //Function cd that returns a File reference if the operation is successful.
        File& cd(File &otherFile);
      
        //Function cp, copies the given file to the current file and 
        //returns true if sucessful. Otherwise, it returns false.
        bool cp(File &otherFile);
        
        //Adds the beginning of the patch of the parent folder.
        bool addParentPatch(File &otherFile);
        
        //Destructor
        virtual ~Directory() { delete [] hereFiles;}
        
    private:
        int numberOfFiles; //Number of the files
        File**  hereFiles; // Here Files
        int hereFilesSize; // Here Files Size
        int hereFilesCapacity; // Here Files Capacity
    }; 
}



#endif	/* DIRECTORY_H */

