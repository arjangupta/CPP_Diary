#ifndef _THREAD_POOL_INTERFACE_HPP_
#define _THREAD_POOL_INTERFACE_HPP_

#include "ThreadPool/ThreadPool.h"

namespace thread_pool_example
{

class GenericThreadUser;
typedef void (GenericThreadUser::*generic_thread_user_function_ptr_t)();

class SpecificThreadUser;
typedef void (SpecificThreadUser::*specific_thread_user_function_ptr_t)();

class ThreadPoolInterface final
{
public:
    ThreadPoolInterface() = delete;
    ThreadPoolInterface(int);
    ~ThreadPoolInterface();
    void sendGenericThreadUserJob(GenericThreadUser*, generic_thread_user_function_ptr_t);
    void sendSpecificThreadUserJob(SpecificThreadUser*, specific_thread_user_function_ptr_t);
private:
    ::ThreadPool _thread_pool;
};

} // namespace thread_pool_example

#endif // _THREAD_POOL_INTERFACE_HPP_