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

void show_mesh ( int** total_mesh, size_t height, size_t width )
{
	for ( size_t i = 0; i < height; ++i )
	{
		for ( size_t j = 0; j < width; ++j )
		{
			std::cout << total_mesh[i][j] << " ";
		}
		std::cout << std::endl;
	}	
}

void reduce_mesh ( int** total_mesh, size_t height, size_t width )
{
	
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
			total_mesh[i][j]  = 1 + i + j;
		}
	}

	show_mesh( total_mesh, total_mesh_height, total_mesh_width );

	std::cout << std::endl;

	return 0;
}