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
    // Check the amount of available memory
    std::cout << "Checking the amount of free memory before any allocs" << std::endl;
    system("free --mega");

    // Alloc pointers to hold 0.5 GB
    // 40 * 25 = 1 KB, 1 KB * 1000 = 1 MB, 1 MB * 500 = 0.5 GB
    ArbitraryData** data_array = (ArbitraryData**) std::malloc(sizeof(ArbitraryData*) * 25 * 1000 * 500);

    std::cout << " --------- Starting the mass allocs in 100 MB chunks ---------- " << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Alloc batch number: " << i << std::endl;
        int hundred_MB_factor = (25 * 1000 * 100);
        for (int j = 0; j < hundred_MB_factor; ++j)
        {
            data_array[(i * hundred_MB_factor) + j] = new ArbitraryData(3, 23.5, "polar_bear");
        }
    }

    // Mass delete
    std::cout << "--------- Starting the mass deletes ---------------" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Delete batch number: " << i << std::endl;
        int hundred_MB_factor = (25 * 1000 * 100);
        for (int j = 0; j < hundred_MB_factor; ++j)
        {
            delete data_array[(i * hundred_MB_factor) + j];
        }
    }

    // Check the amount of available memory
    std::cout << "Checking the amount of free memory after all allocs" << std::endl;
    system("free --mega");

    return;
}

int main()
{
    std::cout << "Some type information -" << std::endl
    << "Size of int is " << sizeof(int) << " bytes." << std::endl
    << "Size of float is " << sizeof(float) << " bytes." << std::endl
    << "Size of std::string is " << sizeof(std::string) << " bytes." << std::endl
    << "Size of ArbitraryData is " << sizeof(ArbitraryData) << " bytes." << std::endl << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        massAlloc();
    }

    std::cout << "Ending program...." << std::endl;

    return 0;
}