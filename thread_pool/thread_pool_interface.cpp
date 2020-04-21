#include "thread_pool_interface.hpp"

namespace thread_pool_example
{

ThreadPoolInterface::ThreadPoolInterface(int max_worker_threads) :
    _thread_pool(max_worker_threads)
{}

ThreadPoolInterface::~ThreadPoolInterface()
{}

// ThreadPoolInterface::sendJob()

} // namepace thread_pool_example