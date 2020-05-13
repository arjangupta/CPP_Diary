#include <iostream>
#include <fstream>

#include <stdlib.h>

int main()
{
    system("top -Ek -b -n 1 | head -n 4 > ./top_output.txt");

    // Read the output file
    std::ifstream top_output_file("./top_output.txt");
    std::string file_contents((std::istreambuf_iterator<char>(top_output_file)), std::istreambuf_iterator<char>());

    system("rm ./top_output.txt");

    const char* file_contents_cstr = file_contents.c_str();
    int file_contents_len = file_contents.length();

    for (int i = 0; i < file_contents_len; ++i)
    {
        if ( file_contents_cstr[i] == '\n')
        {
            std::cout << " <---- ONE WHOLE LINE";
        }
        std::cout << file_contents_cstr[i];
    }

    return 0;
}