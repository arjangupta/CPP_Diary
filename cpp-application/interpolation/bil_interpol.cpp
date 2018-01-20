/* Author: Arjan Gupta
 * Purpose: A program to calculate bilinear interpolation for any 4 given points
 */

#include <iostream>
 
/* Preconditions:
 * 1) x1 and x2 are the locations of the points between which interpolation is
 *	  to be performed
 * 2) q1 is the value at x1 and q2 is the value at x2
 * 3) x_interpol is the distance from the first x_val where you want to find a 
 *	  weighted value
 * 
 * Returns:
 * A double that is the calculated interpolated value ( q_interpol )
 */
double linear_interpolate ( double x1, double x2, double q1, double q2, double x_interpol )
{
	return ( ( q1 * ( ( x2 - x_interpol ) / ( x2 - x1 ) ) ) + 
			 ( q2 * ( ( x_interpol - x1 ) / ( x2 - x1 ) ) ) );
}

int bilinear_interpolate ( const int *x_vals, const int *q_vals )
{
	return 0;
}

int main ()
{
	std::cout << "Calculated linear interpolation for data set 1: " 
			  << linear_interpolate ( 0, 1, 180, 109, ( 2.0/5.0 ) ) << std::endl;
	return 0;
}