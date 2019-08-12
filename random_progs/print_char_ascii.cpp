#include <iostream>

int main()
{
    for (int i = -128; i <= 127; ++i)
    {
        std::cout << i << ": " << static_cast<char>(i) << std::endl;
    }
}