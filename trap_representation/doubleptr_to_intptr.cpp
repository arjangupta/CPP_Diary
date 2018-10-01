#include <iostream>
#include <cstdint>

int main()
{
    double d = 3.14159;
    uint8_t * p = (uint8_t*) &d;
    *p = 0;
    
    for (int i = 0; i < sizeof(double); i++)
    {
        std::cout << std::hex << (int)p[i] << "\t";
    }//output: 0       86      1b      f0      f9      21      9       40

    std::cout << std::endl;

    return 0;
}