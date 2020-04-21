#include "thread_pool_interface.hpp"
#include "specific_thread_user.hpp"

#include <iostream>

using namespace thread_pool_example;

int main()
{
    // Create a single thread pool
    ThreadPoolInterface main_thread_pool_interface(4);
    std::string thread_user_name[] = {"Empress Xina", "Tigress Scout", "Valkyrie Bhavs"};

    SpecificThreadUser user_array[] = 
    {
        {thread_user_name[0], main_thread_pool_interface},
        {thread_user_name[1], main_thread_pool_interface},
        {thread_user_name[2], main_thread_pool_interface}
    };

    std::cout << std::endl;

    bool not_done = true;
    while ( not_done )
    {}

    return 0;
}