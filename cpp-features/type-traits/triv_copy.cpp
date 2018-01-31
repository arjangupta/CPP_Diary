#include <iostream>
#include <type_traits>

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_trivially_copyable<float>::value << '\n';
}