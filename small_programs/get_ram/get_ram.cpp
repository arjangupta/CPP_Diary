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
    int available_ram = std::stoi(file_contents.substr(last_space + 1));
    std::cout << "Last space to end of file, converted to int (available RAM): " << available_ram << std::endl;

    // From the beginning of the file, find the first colon
    std::size_t first_colon = file_contents.find(":");
    // From here, find first non-space
    std::size_t first_number = file_contents.find_first_not_of(" ", first_colon + 1);
    // Get full number
    std::size_t end_of_first_num = file_contents.find_first_of(" ", first_number);
    int total_ram = std::stoi(file_contents.substr(first_number, end_of_first_num));
    std::cout << "Total memory in int: " << total_ram << std::endl;

    // Print out memory usage
    float available_percent = float(available_ram) / float( total_ram );
    float used_percent = (float(1.0) - available_percent) * float(100.0);
    std::cout << "Used ram percent is: " << used_percent << std::endl;

    return 0;
}