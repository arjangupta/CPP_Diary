#include "generic_thread_user.hpp"

#include <iostream>

namespace thread_pool_example
{

GenericThreadUser::GenericThreadUser(std::string& user_name, ThreadPoolInterface& thread_pool_interface) :
    _user_name(user_name),
    _thread_pool_interface(thread_pool_interface)
{
    std::cout << "GenericThreadUser constructor has been called." << std::endl;
}

GenericThreadUser::~GenericThreadUser()
{}

void GenericThreadUser::generateMessages()
{
    _createJobs();
}

void GenericThreadUser::_createJobs()
{
    // Needs to be overidden and custom implemented by dervied class
}

} // namespace thread_pool_example
