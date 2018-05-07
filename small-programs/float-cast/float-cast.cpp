#include <iostream>

int main()
{
    uint8_t byte_a = 'a';
    float float_of_a = byte_a;
    float_of_a += 0.5;
    std::cout << "Assign 'a' to a float and add 0.5: " << float_of_a << "\n\n";

    uint8_t byte_arr[4];
    for (size_t i = 0; i < 4; ++i)
    {
        byte_arr[i] = 'a' + i;
    }
    float float_of_arr = *(byte_arr+2);
    float_of_arr += 0.5;
    std::cout << "Assign byte_array[2] to a float and add 0.5: " << float_of_arr << "\n\n";


    std::cout << "The size of a float is " << sizeof(float) << std::endl;

    return 0;
}