// Program adapted from ModernesCpp.com
// https://www.modernescpp.com/index.php/the-atomic-boolean

#include <vector>
#include <thread>
#include <condition_variable>
#include <iostream>

std::vector<int> _shared_work;
std::mutex _main_mutex;
std::condition_variable _cond_var;

bool _data_ready;

void waitingForWork()
{
    std::cout << "Waiting..." << std::endl;
    
    std::unique_lock<std::mutex> work_lock(_main_mutex);
    _cond_var.wait(work_lock, []{return _data_ready;});

    _shared_work[1] = 2;

    std::cout << "Work done." << std::endl;
}

void setDataReady()
{
    _shared_work = {1, 0, 3};

    {
        std::lock_guard<std::mutex> data_lock(_main_mutex);
        _data_ready = true;
    }

    std::cout << "Data prepared, ready to notify." << std::endl;
    _cond_var.notify_one();
}

int main()
{
    std::cout << std::endl;

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();

    std::cout << "The vector elements are as follows." << std::endl;
    for ( auto v : _shared_work )
    {
        std::cout << v << " ";
    }

    std::cout << std::endl << std::endl;
}