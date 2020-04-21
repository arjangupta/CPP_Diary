#include "generic_thread_user.hpp"

namespace thread_pool_example
{

GenericThreadUser::GenericThreadUser(std::string& user_name, ThreadPoolInterface& thread_pool_interface) :
    _user_name(user_name),
    _thread_pool_interface(thread_pool_interface)
{}

GenericThreadUser::~GenericThreadUser()
{
}

} // namespace thread_pool_example
