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

    // From the end of the file, rfind the first space
    std::size_t last_space = file_contents.rfind(" ", (file_contents.size() - 1));
    std::cout << "Last space to end of file, converted to int (available RAM): " << std::stoi(file_contents.substr(last_space + 1)) << std::endl;

    // From the beginning of the file, find the first colon
    std::size_t first_colon = file_contents.find(":");
    // From here, find first non-space
    std::size_t first_number = file_contents.find_first_not_of(" ");
    std::cout << "First not space after colon is: " << file_contents[first_number] << std::endl;

    return 0;
}