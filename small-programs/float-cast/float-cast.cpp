#include <iostream>

int main()
{
    uint8_t byte_a = 'a';
    float float_of_a = static_cast<float>(byte_a);
    float_of_a += 0.5;
    std::cout << "Cast 'a' to a float and add 0.5: " << float_of_a << std::endl;

    uint8_t byte_arr[4];
    for (size_t i = 0; i < 4; ++i)
    {
        byte_arr[i] = 'a' + i;
    }
    float float_of_arr = static_cast<float>(*(byte_arr+2));
    float_of_arr += 0.5;
    std::cout << "Cast byte_array[2] to a float and add 0.5: " << float_of_arr << std::endl;

    std::cout << "The size of a float is " << sizeof(float) << std::endl;

    return 0;
}