#include <iostream>
#include <string>

int main()
{
    std::string str = "E103";
    std::cout << str << std::endl;
    str = str.substr(1, (str.length() - 1));
    std::cout << str << std::endl;
}