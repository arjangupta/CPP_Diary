#include <iostream>
#include <type_traits>

// This program gives info about a type being trivially copyable

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_trivially_copyable<float>::value << '\n';
}