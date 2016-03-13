#include "header.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void is_it_legal_trilange(const double &firstSide, const double &secondSide, 
                          const double &thirdSide)
{
    if( firstSide>=secondSide+thirdSide || 
        firstSide<=secondSide-thirdSide ||     
        firstSide<=thirdSide-secondSide ||
            
        secondSide>=firstSide+thirdSide || 
        secondSide<=firstSide-thirdSide ||     
        secondSide<=thirdSide-firstSide ||
            
        thirdSide>=secondSide+firstSide || 
        thirdSide<=secondSide-firstSide ||     
        thirdSide<=firstSide-secondSide ||
            
        firstSide<=0 || secondSide<=0 || thirdSide<=0)
        {
            cerr << endl << "("<< firstSide << ")" 
                 << "(" << secondSide << ")"
                 << "(" << thirdSide << ")"
                 << " İt is not legal triangle" << endl
                 << "Error. Program is end"; //Error message
            exit(1);
        }
        





}
