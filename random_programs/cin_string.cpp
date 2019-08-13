#include <iostream>
#include <string>

int main()
{
    std::string input = "";

    while(input != "q")
    {
        getline(std::cin, input);

        std::cout << input << std::endl;
    }

    return 0;
}