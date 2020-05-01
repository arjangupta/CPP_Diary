#include "thread_pool_interface.hpp"

namespace thread_pool_example
{

ThreadPoolInterface::ThreadPoolInterface(int max_worker_threads) :
    _thread_pool(max_worker_threads)
{}

ThreadPoolInterface::~ThreadPoolInterface()
{}

void ThreadPoolInterface::sendGenericThreadUserJob(GenericThreadUser* user_ptr, 
                         generic_thread_user_function_ptr_t async_function_ptr)
{
    _thread_pool.enqueue(async_function_ptr, user_ptr);
}

void ThreadPoolInterface::sendSpecificThreadUserJob(SpecificThreadUser* user_ptr,
                          specific_thread_user_function_ptr_t async_function_ptr)
{
    _thread_pool.enqueue(async_function_ptr, user_ptr);
}

} // namepace thread_pool_example