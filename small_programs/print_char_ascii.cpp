#include <iostream>

int main()
{
    for (int i = -128; i <= 127; ++i)
    {
        std::cout << i << ": " << static_cast<char>(i) << std::endl;
    }

    std::string random_word = "NAKE";
    random_word = static_cast<char>(83) + random_word;
    std::cout << random_word << std::endl;
}