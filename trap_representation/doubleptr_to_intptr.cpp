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
    }

    std::cout << std::endl;

    return 0;
}