// HW08_131044017_Mustafa_Akilli
// 
// File:   Directory.cpp
// Author: Mustafa_Akilli
//
// Created on 19 Aralik 2015 Cumartesi, 21:08 by Mustafa_Akilli
//
// Description
//
// The class Directory is a special File that can hold a number of Files in it.
//
// HW8 Directory Cpp
#include "Directory.h"

//for endl
using std::endl;

namespace
{
    const static int DEFAULT_LS = 0;
    const static int NONE = 0;
    const static int ONE = 1;
    const static int HEREFILESCAPACITY=5;
    const static int PASSIVE = 0;
    const static int AKTIVE = 1;
    
    const static char COMMAND_a = 'a';
    const static char COMMAND_R = 'R';
    const static char COMMAND_l = 'l';
    
    const static char SECRET_FILE_BEGIN = '.';
}



namespace mustafaAkilli
{        
    //Default Contructor
    Directory::Directory(const string &newName,const string &newOwner,const double &newSize,
                const string &newLastModificaiton, const string &newPermission):
                File(newName,newOwner,newSize,newLastModificaiton,newPermission)
    {
        setNumberOfFiles(NONE);
        setHereFilesSize(NONE);
        setHereFilesCapacity(HEREFILESCAPACITY);
        setHereFiles();
    }
        
    //No Parameter Contructor
    Directory::Directory():
                File()
    {
        setNumberOfFiles(NONE);
        setHereFilesSize(NONE);
        setHereFilesCapacity(HEREFILESCAPACITY);
        setHereFiles();
    }
            
    //Copy Contructor
    Directory::Directory(File* otherDirectory):
                File(otherDirectory->getName(),otherDirectory->getOwner(),
                otherDirectory->getSize(),otherDirectory->getLastModificaiton(),
                otherDirectory->getPermission())
    {
        Directory* temp= dynamic_cast<Directory* >(otherDirectory);

        if(NULL!=temp->getHereFiles())
        {
            setNumberOfFiles(temp->getNumberOfFiles()); 
            setHereFilesSize(temp->getHereFilesSize());
            setHereFilesCapacity(temp->hereFilesCapacity);
            setHereFiles();
        }
    }
        
    
    // set Number Of Files
    void Directory::setNumberOfFiles(const int &newNumberOfFiles)
    {
        numberOfFiles=newNumberOfFiles;
    }
    
    // set Here Files
    void Directory::setHereFiles()
    { 
        hereFiles= new File*[getHereFilesCapacity()];    
    }
    
    // set Here Files Size
    void Directory::setHereFilesSize(const int &newHereFilesSize)
    {
        hereFilesSize=newHereFilesSize;
    }
    
    // set Here Files Capacity
    void Directory::setHereFilesCapacity(const int &newHereFilesCapacity)
    {
        hereFilesCapacity=newHereFilesCapacity;
    }
    
    // increase Here Files Capacity
    void Directory::increaseHereFilesCapacity()
    {
        hereFilesCapacity=hereFilesCapacity*2;
    }
    
    //Function ls that prints the file on the screen similar to what “ls file” does. 
    //Function ls also takes parameters similar to Linux ls paramerts -l, -R, -a.
    void Directory::ls(string &lsParameters)
    {
        int a_Check=PASSIVE;
        int R_Check=PASSIVE;
        int l_Check=PASSIVE;
        
        //Which command is want
        for (string::iterator i=lsParameters.begin(); 
                i!=lsParameters.end(); 
                ++i)
        {     
            if((*i)==COMMAND_a)
                a_Check=AKTIVE;
                
            else if((*i)==COMMAND_R)
                R_Check=AKTIVE;
                    
            else if((*i)==COMMAND_l)
                l_Check=AKTIVE;
        }
        
        //endl
        cout << endl;

        for(int i=0; i<getHereFilesSize(); ++i)
        {
            string fileName=hereFiles[i]->getName();
            string::iterator isItSecretFile=fileName.begin();
            
            // if file is not secret file, than write
            // but file is secret file, than if a_Check is aktive than write
            if(*isItSecretFile!=SECRET_FILE_BEGIN ||
               (*isItSecretFile==SECRET_FILE_BEGIN && a_Check==AKTIVE) )
            {
                cout << hereFiles[i]->getName();
                
                //if -l then write
                if(l_Check)
                {
                    cout << " " << hereFiles[i]->getPermission()
                         << " " << hereFiles[i]->getOwner()
                         << " " << hereFiles[i]->getSize()
                         << " " << hereFiles[i]->getLastModificaiton();
                }
                
                //if -R then write
                if(R_Check)
                {
                    if(NULL!=dynamic_cast<Directory*> (hereFiles[i]))
                    {   
                        hereFiles[i]->ls(lsParameters);
                    }
                }
            }
            cout << endl;  
        } 
    }
   
    
    //Function cd that returns a File reference if the operation is successful.
    File& Directory::cd(File &otherFile)
    {   
        //if the same name file then return it
        for(int i=0; i<getHereFilesSize(); ++i)
        {
            if(hereFiles[i]->getName()==otherFile.getName() && 
                NULL!=dynamic_cast<Directory*> (&otherFile))
                return *hereFiles[i];
        }

        cout << endl << "bash:cd: " 
             << otherFile.getName() << ": No such file or directory ";
        
        //if the not same name file then return this
        return *this;
    }
                
                
    //Function cp, copies the given file to the current file and 
    //returns true if sucessful. Otherwise, it returns false.
    bool Directory::cp(File &otherFile)
    {
        //add Patch
        addParentPatch(otherFile);
        
        //if capacity is not enough
        if(getHereFilesSize()+1>=getHereFilesCapacity())
        {
            File* temp = new File[getHereFilesCapacity()];
            
            for(int i=NONE; i<getHereFilesSize(); ++i)
                temp[i]=*hereFiles[i];
            
            delete [] hereFiles;
            
            increaseHereFilesCapacity();
            
            setHereFiles();
            
            for(int i=NONE; i<getHereFilesSize(); ++i)
                *hereFiles[i]=temp[i];

            delete [] temp;
        }
     
        //add the in hereFiles
        hereFiles[getHereFilesSize()]=&otherFile;
        //increase the size of here files 
        setHereFilesSize(getHereFilesSize()+ONE); 
        
        return true; 
    }
    
    //Adds the beginning of the patch of the parent folder.
    bool Directory::addParentPatch(File &otherFile)
    {   
        //Base case
        if(NULL==dynamic_cast<Directory*> (&otherFile))
        {   
            otherFile.addPath((*this).path());
            return false;
        }
        
        Directory* temp = dynamic_cast<Directory*> (&otherFile);
        
        otherFile.addPath((*this).path());
        
        //İf Files in files, then call them
        for(int i=NONE; i<temp->getHereFilesSize() ; ++i)
                addParentPatch(*(temp->hereFiles[i]));
        
        return true;
    }
}