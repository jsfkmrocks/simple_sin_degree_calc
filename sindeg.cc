#include "sindeg.h"
#include <cmath>

const double PI = 2 * asin(1.0);

//
//   Function sindeg returns the sine of an angle
//   Input:   the angel in degress 
//   Output:  the sine of the input angle
//
//   Usage:    x = sindeg(input_angle)
//


//  helper function to compute the factorial.  Used in the power series evaluation of the sine of the given angle
int factorial (int n)
{
    int fact = 1;

    while (n >= 2)
	{
	fact *= n;
	n--;
	}
    return fact;
}




double sindeg(double angle_degrees)
{

    double angle;   // in radians
    double newTerm;
    double result;
    int    termNumber;

    angle = angle_degrees * PI/ 180.0;

    result = angle;
    termNumber = 2;
    do
        {
        newTerm = pow(angle, 2 * termNumber - 1) / factorial(2*termNumber-1);
	if (termNumber % 2)
	    {  // odd termNumber implies add
	    result += newTerm;
	    }
	 else
	    {
	    result -= newTerm;
	    }
	termNumber ++;
	} while (fabs(newTerm/result) > 0.0001 
					&& termNumber < 15);
    return result;
}

