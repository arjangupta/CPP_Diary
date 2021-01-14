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

    // From the end of the file, rfind the first space
    std::size_t last_space = file_contents.rfind(" ", (file_contents.size() - 1));
    std::cout << "Last space to the end of file: " << file_contents.substr(last_space + 1) << std::endl;
    std::cout << "And, converted to int: " << std::stoi(file_contents.substr(last_space + 1)) << std::endl;

    return 0;
}