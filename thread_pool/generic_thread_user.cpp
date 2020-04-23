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

bool GenericThreadUser::hasOutboundMessages()
{
    std::lock_guard<std::mutex> lock_outbound_queue(_mutex_outbound_queue);
    return ! _outbound_queue.empty();
}

void GenericThreadUser::getOldestMessage(ThreadUserMessage& message)
{
    if ( ! hasOutboundMessages() )
    {
        message._is_empty = true;
        return;
    }
    std::lock_guard<std::mutex> lock_outbound_queue(_mutex_outbound_queue);
    message = _outbound_queue.front();
    return;
}

void GenericThreadUser::notifyUsageOfOldestMessage()
{
    std::lock_guard<std::mutex> lock_outbound_queue(_mutex_outbound_queue);
    _outbound_queue.pop();
}

void GenericThreadUser::_createJobs()
{
    // Needs to be overidden and custom implemented by dervied class
}

} // namespace thread_pool_example
