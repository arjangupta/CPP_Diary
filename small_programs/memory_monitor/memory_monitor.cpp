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

void massAlloc()
{
    // Alloc pointers to hold 1 GB
    // 40 * 25 = 1 KB, 1 KB * 1000 = 1 MB, 1 MB * 1000 = 1 GB
    ArbitraryData** data_array = (ArbitraryData**) std::malloc(sizeof(ArbitraryData*) * 25 * 1000 * 1000);

    std::cout << " --------- Starting the mass allocs in 100 MB chunks ---------- " << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Batch number: " << i << std::endl;
        int one_gb_factor = (25 * 1000 * 100);
        for (int j = 0; j < (25 * 1000 * 100); ++j)
        {
            data_array[(i * one_gb_factor) + j] = new ArbitraryData(3, 23.5, "polar_bear");
        }
    }
}

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

    massAlloc();

    // Check the amount of available memory
    std::cout << "Checking the amount of free memory after all allocs" << std::endl;
    system("free --mega");

    std::cout << "Ending program...." << std::endl;

    return 0;
}