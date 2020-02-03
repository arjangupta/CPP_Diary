#include <iostream>

int main()
{
    std::cout << "The bitwise AND of " << 7 
              << " and " << 3 << " is "
              << (7 & 3) << std::endl;

    int bit_shift = 1;
    int resultant_number = 1 << bit_shift;
    std::cout << "The bitwise AND of " << 4
              << " and " << resultant_number << " is "
              << (4 & resultant_number) << std::endl;
    return 0; 
}