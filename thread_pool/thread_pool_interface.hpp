#ifndef _THREAD_POOL_INTERFACE_HPP_
#define _THREAD_POOL_INTERFACE_HPP_

#include "ThreadPool/ThreadPool.h"

namespace thread_pool_example
{

// typedef int 

class ThreadPoolInterface
{
public:
    ThreadPoolInterface() = delete;
    ThreadPoolInterface(int max_worker_threads);
    ~ThreadPoolInterface();
private:
    ::ThreadPool _thread_pool;
};

} // namespace thread_pool_example

#endif // _THREAD_POOL_INTERFACE_HPP_