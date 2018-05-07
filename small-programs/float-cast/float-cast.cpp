#include <iostream>

int main()
{
    uint8_t byte_a = 'a';
    float float_of_a = static_cast<float>(byte_a);
    float_of_a += 0.5;
    std::cout << float_of_a << std::endl; 
    return 0;
}