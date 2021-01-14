#include <iostream>
#include <cstdlib>
#include <fstream>

int main()
{
    // Execute the command to get the memory
    system("free -m | grep Mem: > mem.txt");

    // Read the output file
    std::ifstream filstream("./mem.txt");
    std::string file_contents((std::istreambuf_iterator<char>(filstream)), std::istreambuf_iterator<char>());

    // Look for the first number at the end of the line
    std::cout << "At pos 79, the file reads: " << file_contents[78] << std::endl;

    // Print out available memory

    return 0;
}