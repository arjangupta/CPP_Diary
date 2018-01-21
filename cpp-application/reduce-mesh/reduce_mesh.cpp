/* Author: Arjan Gupta
 * Purpose: Reduce a given mesh of points to one point. For the sake of
 *          demonstration, we will multiply values at the points
 */

// Std lib includes
#include <iostream>
#include <cstddef>

// global consts (instead of macros)
const size_t total_mesh_height = 3; 
const size_t total_mesh_width = 3;

void show_mesh ( int** total_mesh, size_t x_start, size_t y_start )
{
	for ( size_t i = y_start; i < total_mesh_height; ++i )
	{
		for ( size_t j = x_start; j < total_mesh_width; ++j )
		{
			std::cout << *( *(total_mesh + i) + j) << " ";
		}		
		std::cout << std::endl;
	}

	std::cout << std::endl;	
}

void reduce_mesh ( int** total_mesh, size_t x_start, size_t y_start )
{
	std::cout << "x_start is " << x_start << " and y_start is " << y_start << std::endl;
	show_mesh( total_mesh, x_start, y_start );

	if ( x_start < total_mesh_width - 2 )
	{
		reduce_mesh( total_mesh, x_start + 1, y_start );
	} else if ( y_start < total_mesh_height - 2 ) {
		reduce_mesh( total_mesh, x_start, y_start + 1 );
	}

	total_mesh[y_start][x_start] = total_mesh [y_start] [x_start] *
	                               total_mesh [y_start + 1] [x_start] *
	                               total_mesh [y_start] [x_start + 1] *
	                               total_mesh [y_start + 1] [x_start + 1];

	return;
}

int main ()
{
	std::cout << "\nReduce a given mesh to one point!\n\n";

	int** total_mesh = new int* [total_mesh_height];

	for ( size_t i = 0; i < total_mesh_height; ++i )
	{
		total_mesh[i] = new int [total_mesh_width]; 

		for ( size_t j = 0; j < total_mesh_width; ++j )
		{
			total_mesh[i][j] = 2;
		}
	}

	reduce_mesh( total_mesh, 0, 0 );

	show_mesh( total_mesh, 0, 0 );

	return 0;
}