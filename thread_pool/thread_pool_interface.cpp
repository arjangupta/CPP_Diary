#include "thread_pool_interface.hpp"

#include <functional>

namespace thread_pool_example
{

ThreadPoolInterface::ThreadPoolInterface(int max_worker_threads) :
    _thread_pool(max_worker_threads)
{}

ThreadPoolInterface::~ThreadPoolInterface()
{}

void ThreadPoolInterface::sendJob(GenericThreadUser* user, thread_user_function_ptr_t async_function)
{
    _thread_pool.enqueue(async_function, user);
}

} // namepace thread_pool_example