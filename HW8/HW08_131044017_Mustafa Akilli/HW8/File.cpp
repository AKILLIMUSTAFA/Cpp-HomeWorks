// HW08_131044017_Mustafa_Akilli
// 
// File:   File.cpp
// Author: Mustafa_Akilli
//
// Created on 19 Aralik 2015 Cumartesi, 12:52 by Mustafa_Akilli
//
// Description
//
// Base Class for computer files
//
// HW8 File Cpp

#include "File.h"

namespace
{
    const static int DEFAULT_SIZE = 1;
}

namespace mustafaAkilli
{
    //Default Contructor
    File::File(const string &newName,const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission)
    {
        setName(newName);
        setOwner(newOwner);
        setSize(newSize);
        setLastModificaiton(newLastModificaiton);
        setPermission(newPermission);
        setPath(newName);
    }
        
    //No Parameter Contructor
    File::File()
    {
        setName("Untitled Folder");
        setOwner("User");
        setSize(DEFAULT_SIZE);
        setLastModificaiton("20 Aralik 2015");
        setPermission("-rwx");
        setPath("Untitled Folder");
    }
        
    //copy Contructor
    File::File(const File &otherFile)
    {
        setName(otherFile.getName());
        setOwner(otherFile.getOwner());
        setSize(otherFile.getSize());
        setLastModificaiton(otherFile.getLastModificaiton());
        setPermission(otherFile.getPermission());
        setPath(otherFile.getName());
    }
    
    //Setters
    
    //set Name
    void File::setName(const string &newName)
    {
        name=newName;
    }
    
    // set Owner
    void File::setOwner(const string &newOwner)
    {
        owner=newOwner;
    }
    
    // set Size
    void File::setSize(const double &newSize)
    {
        size=newSize;
    }
    
    // Set Last Modificaiton
    void File::setLastModificaiton(const string &newLastModificaiton)
    {
        lastModificaiton=newLastModificaiton;
    }
    
    //set Permission
    void File::setPermission(const string &newPermission)
    {
        permission=newPermission;
    }
    
    // set Path
    void File::setPath(const string &newPath)
    {
        pathOfFile=newPath;
    }

    // add element to Path
    void File::addPath(const string &upperPath)
    {
        pathOfFile=upperPath+" / "+pathOfFile;
    }
    
}