/* Author: Arjan Gupta
 * Purpose: A program to calculate bilinear interpolation for any 4 given points
 */

#include <iostream>
 
/* Preconditions:
 * 1) x1 and x2 are the locations of the points between which interpolation is
 *	  to be performed, so x1 < x2
 * 2) q1 is the value at x1 and q2 is the value at x2
 * 3) x_interpol is the distance from the first x_val where you want to find a 
 *	  weighted value, so x1 < x_interpol < x2
 * 
 * Returns:
 * A double that is the calculated interpolated value ( q_interpol )
 *
 * Unit tested with this online calculator:
 * https://www.ajdesigner.com/phpinterpolation/linear_interpolation_equation.php
 */
double linear_interpolate ( double x1, double x2, double q1, double q2, double x_interpol )
{
	// Ascending order check 1 
	if ( x1 > x2 )
	{
		// Maybe you meant to swap the values, so I'll do it for you
		double tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	// Ascending order check 2
	if ( x_interpol < x1 || x_interpol > x2 )
	{
		std::cout << "x_interpol cannot be smaller than x1 or larger than x2. Please rectify." << std::endl; 
		return 0.0;
	}

	// Check if the values actually the same,
	// in which case, there's nothing to interpoloate
	if ( x1 == x2 )
	{
		return q1;
	}

	// Rest assured, apply the formula
	return ( ( q1 * ( ( x2 - x_interpol ) / ( x2 - x1 ) ) ) + 
             ( q2 * ( ( x_interpol - x1 ) / ( x2 - x1 ) ) ) );
}

/* Preconditions:
 * 1) (x1, y1) is the location of the NW point, (x2, y1) is the location of the
 *	  NE point, and so on
 * 2) q11 corresponds to the value at (x1, y1), q22 corresponds to the value at
 *	  (x2, y2), and so on
 * 3) (x_interpol, y_interpol) is the location of the point at which we want the
 *	  interpolation done
 *
 * Visual:
 *  q11---q21
 *   |     |
 *  q12---q22
 *
 * Returns:
 * A double which is the value at (x_interpol, y_interpol)
 *
 * Unit tested with this online calculator:
 * https://www.ajdesigner.com/phpinterpolation/bilinear_interpolation_equation.php
 */
double bilinear_interpolate ( double x1, double x2, double y1, double y2, double q11, double q21,
                              double q12, double q22, double x_interpol, double y_interpol )
{
	// Linear interpolate on the top row
	double top_row_interpol = linear_interpolate( x1, x2, q11, q21, x_interpol );

	// Linear interpolate on the bottom row
	double bottom_row_interpol = linear_interpolate( x1, x2, q12, q22, x_interpol );

	// Linear interpolate on vertically between the two new values
	return linear_interpolate( y1, y2, top_row_interpol, bottom_row_interpol, y_interpol );
}

int main ()
{
	std::cout << "Calculated linear interpolation for data set 1: "
			  << linear_interpolate( 0.0, 1.0, 180.0, 109.0, (2.0/5.0) ) << std::endl;

	std::cout << "Calculated linear interpolation for data set 2: "
			  << linear_interpolate( 9.0, 10.0, 249.0, 218.0, (9.0 + (2.0/5.0)) ) << std::endl;

	std::cout << "Calculated linear interpolation for data set 3: "
	          << linear_interpolate( 10.0, 10.0, 249.0, 218.0, (9.0 + (2.0/5.0)) ) << std::endl;

	std::cout << "Calculated linear interpolation for data set 4: "
	          << linear_interpolate( 9.0, 10.0, 249.0, 218.0, (8.0 + (2.0/5.0)) ) << std::endl;

	std::cout << "Calculated bilinear interpolation for data set 5: "
			  << bilinear_interpolate( 3.0, 4.0, 3.0, 4.0, 135.0, 70.0, 183.0, 154.0, (3.0 + (2.0/5.0)), (3.0 + (2.0/5.0)) )
			  << std::endl;

	std::cout << "Calculated bilinear interpolation for data set 6: "
			  << bilinear_interpolate( 5.0, 4.0, 4.0, 3.0, 135.0, 70.0, 183.0, 154.0, (4.0 + (2.0/5.0)), (3.0 + (2.0/5.0)) )
			  << std::endl;

	std::cout << "Calculated bilinear interpolation for data set 7: "
			  << bilinear_interpolate( 3.0, 4.0, 3.0, 4.0, 135.0, 0.0, 183.0, 154.0, (3.0 + (2.0/5.0)), (3.0 + (2.0/5.0)) )
			  << std::endl;

	std::cout << "Calculated bilinear interpolation for data set 8 (should be same as set 2): "
			  << bilinear_interpolate( 9.0, 10.0, 20.0, 20.0, 249.0, 218.0, 249.0, 218.0, (9.0 + (2.0/5.0)), 20.0 ) 
			  << std::endl;

	return 0;
}