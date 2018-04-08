#include <iomanip>
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream fin;
	fin.open("rawdata.txt");
	//std::cout << std::setw(12);
	int x = 0;
	while ( fin >> x)
	{
		std::cout << std::setw(12) << x << std::endl;
	}
	return 0;
}
