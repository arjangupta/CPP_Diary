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

    
    uint8_t byte = 127;
    uint16_t* data = reinterpret_cast<uint16_t*>(&byte);
    std::cout << "The data uint16_t pointer points to " << *data << std::endl;
    std::cout << "The data casted to uint8_t* and deref'd is " << (int)*((uint8_t*) data) << std::endl;
    // & out the 8th bit
    uint16_t right_shift_result = (*((uint8_t*) data) & (1 << 8)) >> 8;
    std::cout << "The right shift result is " << right_shift_result << std::endl;

    return 0; 
}