// HW08_131044017_Mustafa_Akilli
// 
// File:   File.h
// Author: Mustafa_Akilli
//
// Created on 19 Aralik 2015 Cumartesi, 12:50 by Mustafa_Akilli
//
// Description
//
// Base Class for computer files
//
// HW8 File Header

#ifndef FILE_H
#define	FILE_H

#include <iostream>

//For vector
#include <vector>
using std::vector;

//For cout
using std::cout;

//For string
#include <string>
using std::string;


namespace mustafaAkilli
{
    class File
    {
    public:
        //Default Contructor
        File(const string &newName,const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission);
        
        //No Parameter Contructor
        File();
        
        //Copy Contructor
        File(const File &otherFile);
        
        //Setters
        void setName(const string &newName); //set Name
        void setOwner(const string &newOwner); // set Owner
        void setSize(const double &newSize); // set Size
        void setLastModificaiton(const string &newLastModificaiton); // Set
                                                            //Last Modificaiton
        void setPermission(const string &newPermission);//set Permission
        void setPath(const string &newPath);// set Path
        void addPath(const string &upperPath);// add element to Path
        
        
        //Getters
        string getName()const{return name;} //get Name
        string getOwner()const{return owner;} //get Owner
        double getSize()const{return size;} //get Size
        string getLastModificaiton()const{return lastModificaiton;} // Get
                                                            //Last Modificaiton
        string getPermission()const{return permission;} //get Permission
    
        //Function path that returns the path of the file as string
        string path() const{return pathOfFile;}  
        
        //Function ls that prints the file on the screen similar 
        //to what “ls file” does. Function ls also takes
        //parameters similar to Linux ls paramerts -l, -R, -a.
        virtual void ls(string &lsParameters){;}
   
        //Function cd that returns a File reference if the operation is successful.
        virtual File& cd(File &otherFile){;}
                
                
        //Function cp, copies the given file to the current file and 
        //returns true if sucessful. Otherwise, it returns false.
        virtual bool cp(File &otherFile){;}
        
        virtual ~File() { }
        
    private:
        string name; //Name of the file
        string owner; //owner of the file
        double size; //size of the file
        string lastModificaiton; //Last modificaiton time of the file
        string permission; //permission of the file
        string pathOfFile; //path of the file
    };
}

#endif	/* FILE_H */