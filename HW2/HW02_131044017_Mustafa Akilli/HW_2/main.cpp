// HW02_131044017_Mustafa_Akıllı
// 
//
// Created on 24 Ekim 2015 Cumartesi, 17:15 by Mustafa_Akıllı
//
// Description
//
// Returns the array index of the first mode element of a given array 

#include <iostream>
#include <cstdlib>

using namespace std;

class DayOfYear
{
public:
    DayOfYear(int newMonth,int newDay);
    //Initializes the month and day to arguments.
    
    DayOfYear(int newMonth);
    //Initializes the date to the first of the given month.
    
    DayOfYear();
    //Initializes the date to January 1.
    
    // Mutators
    int setMonthNumber(int newMonth);
    //Set 1 for January, 2 for February, etc.
    int setDay(int newDay);
    
    int month;
    int day;
};

class Person
{
public:
    Person();    
    
    // Mutators
    int setAge(int newAge);
   
    int age;
    int weight;
    double height;

};

int return_mode (const void * base, size_t num, size_t size,
                bool (* equals) (const void *, const void *));
//Returns the array index of the first mode element of a given array.
//İf not be mode in the array, return first index.
//for example, for (1,2,3) return 0.
//for example, for (1,2,2,3,3) return 1.

bool compare_int(const void * firstValue, const void * secondValue); 
//For integer bool function
//When they are equal to each other return true, other times return false

bool compare_double(const void * firstValue, const void * secondValue);
//For double bool function
//When they are equal to each other return true, other times return false

bool compare_char(const void * firstValue, const void * secondValue);
//For char bool function
//When they are equal to each other return true, other times return false

bool compare_dayOfYear(const void * firstValue, const void * secondValue);
//For DayOfYear bool function
//When they are equal to each other return true, other times return false

bool compare_person(const void * firstValue, const void * secondValue);
//For Person bool function
//When they are equal to each other return true, other times return false

int main() {

    //**************************************//
    //TEST FOR INTEGER
    int intArray[] = {1,0,2,1,4,5,6,9,9,9}; //Integer Array
    int intArrayNumber=10; // Integer Array Number
    int intArrayMode; // Mode in the integer Array Number 
    
    //Print the Array
    cout << "İnteger array:" << " (";
    for(int z=0; z<10; ++z)
        cout << intArray[z] << ",";
    cout << ")" << endl;
    
    //Call the function
    intArrayMode = return_mode (&intArray, intArrayNumber, sizeof (int), 
                                compare_int);
    
    //Print the screen "mode index"
    cout << "Integer Array Mode İndex: "<< intArrayMode << endl << endl;
    
    
    
    
    
    //**************************************//
    //TEST FOR DOUBLE
    double doubleArray[] = {(5.2),(5.4),(5.4),(6.1),(4.8),(5.2),(4.8),(4.8)};
    //Double Array
    int doubleArrayNumber=8; // Double Array Number
    int doubleArrayMode; // Mode in the Double Array Number
    
    //Print the Array
    cout << "Double array:" << " (";
    for(int z=0; z<8; ++z)
        cout << "(" << doubleArray[z] << ") " << ",";
    cout << ")" << endl;
    
    //Call the function
    doubleArrayMode = return_mode (&doubleArray, doubleArrayNumber, 
                                sizeof (double), compare_double);
    
    //Print the screen "mode index"
    cout << "Double Array Mode İndex: "<< doubleArrayMode << endl << endl;
    
    
    
    
    
    //**************************************//
    //TEST FOR CHAR
    char charArray[] = {'a','b','c','c','e','f','r','z','t','y'};
    //Char Array
    int charArrayNumber=10; // Char Array Number
    int charArrayMode; // Mode in the Char Array Number
    
    //Print the Array
    cout << "Char array:" << " (";
    for(int z=0; z<10; ++z)
        cout << charArray[z] << ",";
    cout << ")" << endl;
    
    //Call the function
    charArrayMode = return_mode (&charArray, charArrayNumber, 
                                sizeof (char), compare_char);
    
    //Print the screen "mode index"
    cout << "Char Array Mode İndex: "<< charArrayMode << endl << endl;
    
    
    
    
    
    //**************************************//
    //TEST FOR DAYOFYEAR CLASS
    DayOfYear dayOfYearArray[6]; //DayOfYear Array
    int dayOfYearArrayNumber=6; //DayOfYear Array Number
    int dayOfYearArrayMode; // Mode in the DayOfYear Array Number
    
    //Fill the DayOfYear Array
    for(int i=0; i<3; ++i)
    {
        dayOfYearArray[i].setMonthNumber(i+2);
        dayOfYearArray[i].setDay(i+5);
    }
    
    //Print the Array
    cout << "DayOfYear array:";
    for(int t=0; t<6; ++t)
    {
        cout << " ("
             << dayOfYearArray[t].month << ","
             << dayOfYearArray[t].day << ")";
    }
    cout << endl;
    
    //Call the function
    dayOfYearArrayMode = return_mode (&dayOfYearArray,dayOfYearArrayNumber, 
                                    sizeof (DayOfYear), compare_dayOfYear);
    
    //Print the screen "mode index"
    cout << "DayOfYear Array Mode İndex: "<< dayOfYearArrayMode << endl << endl;
    
    
    
    
    
    
    //**************************************//
    //TEST FOR PERSON CLASS
    Person personArray[6]; //DayOfYear Array
    int personArrayNumber=6; //DayOfYear Array Number
    int personArrayMode; // Mode in the DayOfYear Array Number
    
    //Fill the DayOfYear Array
    for(int j=0; j<2; ++j)
    {
        personArray[j].setAge(j+40);
    }
    
    //Print the Array
    cout << "Person array:";
    for(int k=0; k<6; ++k)
    {
        cout << " ("
             << personArray[k].age << ","
             << personArray[k].weight << ","
             << personArray[k].height << ")";
    }
    cout << endl;
    
    //Call the function
    personArrayMode = return_mode (&personArray,personArrayNumber, 
                                    sizeof (Person), compare_person);
    
    //Print the screen "mode index"
    cout << "Person Array Mode İndex: "<< personArrayMode << endl;
    
    
    return 0;
}

DayOfYear::DayOfYear(int newMonth,int newDay):
                    month(newMonth), day(newDay)
{/*Body intentionally empty.*/}

DayOfYear::DayOfYear(int newMonth):
                    month(newMonth), day(1)
{/*Body intentionally empty.*/}

DayOfYear::DayOfYear():
                month(1), day(1)
{/*Body intentionally empty.*/}

int DayOfYear::setMonthNumber(int newMonth)
{
    month=newMonth;
}

int DayOfYear::setDay(int newDay)
{
    day=newDay;
}

Person::Person():
              age(20), weight(80), height(1.55)
{/*Body intentionally empty.*/}


int Person::setAge(int newAge)
{
    age=newAge;
}

int return_mode (const void * base, size_t num, size_t size,
                bool (* equals) (const void *, const void *))
{
    int mode=0; //Mode in the array
    int indexOfArrayElement=0; //index of the element
    int howManyTimesUsed=0;// how many times used element in the array
    int mostUsedElement=0;// Most used element is How Many Times Used.
    unsigned char* arrayElement = (unsigned char*) base; 
    //beginning of the array
    unsigned char* arrayOtherElements = (unsigned char*) base;
    //beginning of the array
    unsigned char* arrayEnd = (unsigned char*) base + (num * size);
    //end of the array
    
    //Select element
    for (; arrayElement < arrayEnd; arrayElement += size) 
    {
        //Comparison with other elements
        //When *equals function return true , then incrase the howManyTimesUsed.
        for(;arrayOtherElements < arrayEnd; arrayOtherElements += size)
            if ((*equals)(arrayElement, arrayOtherElements) == true)
                ++howManyTimesUsed;
        
        //İf this element more used in the array, then make the mode.
        if(howManyTimesUsed>mostUsedElement)
        {
            mostUsedElement=howManyTimesUsed;
            mode=indexOfArrayElement;
        }
            
        //Reset
        arrayOtherElements=(unsigned char*) base;
        howManyTimesUsed=0;
        ++indexOfArrayElement;
    }
    
    //Return mode
    return mode;
}

bool compare_int(const void * firstValue, const void * secondValue) 
{
    //When they are equal to each other, return true
    if ( *(int*)firstValue == *(int*)secondValue )
        return true;
    
    //When they are not equal to each other, return false
    else
        return false;
}

bool compare_double(const void * firstValue, const void * secondValue) 
{
    //When they are equal to each other, return true
    if ( *(double*)firstValue == *(double*)secondValue )
        return true;
    
    //When they are not equal to each other, return false
    else
        return false;
}

bool compare_char(const void * firstValue, const void * secondValue)
{
    //When they are equal to each other, return true
    if ( *(char*)firstValue == *(char*)secondValue )
        return true;
    
    //When they are not equal to each other, return false
    else
        return false;
}

bool compare_dayOfYear(const void * firstValue, const void * secondValue)
{
    const DayOfYear* firstDayOfYear = static_cast<const DayOfYear*> (firstValue);
    const DayOfYear* secondDayOfYear = static_cast<const DayOfYear*>(secondValue);
    
    //When they are equal to each other, return true
    if (firstDayOfYear->day == secondDayOfYear->day &&
        firstDayOfYear->month == secondDayOfYear->month)
    {
        return true;
    }
        
    //When they are not equal to each other, return false
    else
    {
        return false;
    }
}

bool compare_person(const void * firstValue, const void * secondValue)
{
    const Person* firstPerson = static_cast<const Person*> (firstValue);
    const Person* secondPerson = static_cast<const Person*>(secondValue);
    
    //When they are equal to each other, return true
    if (firstPerson->age == secondPerson->age &&
        firstPerson->weight == secondPerson->weight &&
        firstPerson->height == secondPerson->height) 
    {
        return true;
    }
        
    //When they are not equal to each other, return false
    else
    {
        return false;
    }
}