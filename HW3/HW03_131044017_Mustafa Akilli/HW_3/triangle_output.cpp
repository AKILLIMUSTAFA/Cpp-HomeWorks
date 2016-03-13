#include "header.h"
#include <iostream>
using namespace std;

void Triangle::output() const
{
    cout << endl << "First Side Value (A): " << getFirstValue()<< endl
         << "First Second Value (B): " << getSecondValue() << endl
         << "First Third Value (C): " << getThirdValue() << endl << endl;
}
