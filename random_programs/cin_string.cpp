#include <iostream>
#include <string>

int main()
{
    std::string input = "";

    while(input != "q")
    {
        std::getline(std::cin, input);

        if (std::cin.fail())
        {
            std::cout << "cin has failed" << std::endl;
            break;
        }

        std::cout << input << std::endl;
    }

    return 0;
}