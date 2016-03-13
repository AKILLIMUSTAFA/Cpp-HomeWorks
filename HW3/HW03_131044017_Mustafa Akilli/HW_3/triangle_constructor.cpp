#include "header.h"


Triangle::Triangle(double firstSide, double secondSide, double thirdSide):
                   A(firstSide), B(secondSide), C(thirdSide)
{/*Body intentionally empty.*/}


Triangle::Triangle(double firstSide, double secondSide):
                   A(firstSide), B(secondSide), C(1.0)
{/*Body intentionally empty.*/}


Triangle::Triangle(double allSide):
                   A(allSide), B(allSide), C(allSide)
{/*Body intentionally empty.*/}

Triangle::Triangle():
            A(1.0), B(1.0), C(1.0)
{/*Body intentionally empty.*/}