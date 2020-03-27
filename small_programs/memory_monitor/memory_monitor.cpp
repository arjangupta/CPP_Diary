#include <iostream>
#include <string>

struct ArbitraryData
{
    ArbitraryData(int given_int, float given_float, std::string const& given_name)
    {
        int_val = given_int;
        float_val = given_float;
        name = given_name;
    }

    int int_val;
    float float_val;
    std::string name;
};

int main()
{
    std::cout << "Some type information -" << std::endl
    << "Size of int is " << sizeof(int) << " bytes." << std::endl
    << "Size of float is " << sizeof(float) << " bytes." << std::endl
    << "Size of std::string is " << sizeof(std::string) << " bytes." << std::endl
    << "Size of ArbitraryData is " << sizeof(ArbitraryData) << " bytes." << std::endl << std::endl;

    // Check the amount of available memory
    std::cout << "Checking the amount of free memory before any allocs" << std::endl;
    system("free --mega");

    // TODO: Write loop for mass allocs

    //ArbitraryData* data_point1 = new ArbitraryData(3, 23.5, "polar_bear");

    std::cout << "Ending program...." << std::endl;

    return 0;
}