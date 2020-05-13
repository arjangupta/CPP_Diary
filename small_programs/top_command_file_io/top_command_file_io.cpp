#include <iostream>
#include <fstream>

#include <stdlib.h>

int main()
{
    system("top -Ek -b -n 1 | head -n 4 > ./top_output.txt");

    // Read the output file
    std::ifstream top_output_file("./top_output.txt");
    std::string file_contents((std::istreambuf_iterator<char>(top_output_file)), std::istreambuf_iterator<char>());

    std::cout << file_contents << std::endl;

    return 0;
}