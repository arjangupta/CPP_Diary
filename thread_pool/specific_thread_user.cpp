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

void SpecificThreadUser::_createJobs()
{
    thread_user_function_ptr_t wait_for_food = this->_waitForFood;
    _thread_pool_interface.sendJob(this, wait_for_food);
}

void SpecificThreadUser::_waitForFood()
{
    // make this thread sleep
    // "Name" is ready for food
}

} // namespace thread_pool_example