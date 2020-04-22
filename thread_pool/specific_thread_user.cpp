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
    _thread_pool_interface.sendSpecificThreadUserJob(this, &SpecificThreadUser::_waitForFood);
    _thread_pool_interface.sendSpecificThreadUserJob(this, &SpecificThreadUser::_decideToExercise);
}

void SpecificThreadUser::_waitForFood()
{
    {
    std::lock_guard<std::mutex> user_name_lock_guard(_mutex_user_name);
    std::cout << _user_name << " is waiting for food..." << std::endl;
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    {
    std::lock_guard<std::mutex> user_name_lock_guard(_mutex_user_name);
    std::cout << _user_name << " now requires food!" << std::endl;
    }
}

void SpecificThreadUser::_decideToExercise()
{
    {
    std::lock_guard<std::mutex> user_name_lock_guard(_mutex_user_name);
    std::cout << _user_name << " is thinking of exercising..." << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    {
    std::lock_guard<std::mutex> user_name_lock_guard(_mutex_user_name);
    std::cout << _user_name << " has decided to do " << rand() % 10 << " x 100 meter sprints!" << std::endl;
    }
}

} // namespace thread_pool_example