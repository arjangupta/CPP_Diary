#include "thread_pool_interface.hpp"
#include "generic_thread_user.hpp"

using namespace thread_pool_example;

int main()
{
    ThreadPoolInterface main_thread_pool_interface(4);
    std::string generic_user_name = "Christina";
    GenericThreadUser xina(generic_user_name, main_thread_pool_interface);
    return 0;
}