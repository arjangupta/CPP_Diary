#include "specific_thread_user.hpp"

#include <iostream>

namespace thread_pool_example
{

SpecificThreadUser::SpecificThreadUser( std::string& user_name, ThreadPoolInterface& thread_interface) :
    GenericThreadUser::GenericThreadUser(user_name, thread_interface)
{
    std::cout << "SpecificThreadUser constructor has been called: " << _user_name << std::endl;
}

SpecificThreadUser::~SpecificThreadUser()
{}

void SpecificThreadUser::_createSomeJob()
{
    // custom impl
}

} // namespace thread_pool_example