#include <vector>
#include <thread>
#include <condition_variable>
#include <iostream>

std::vector<int> _shared_work;
std::mutex _main_mutex;
std::condition_variable _cond_var;

bool _data_ready;

void waitingForWork(int id)
{
    std::cout << "T" << id << ": Waiting..." << std::endl;
    
    std::unique_lock<std::mutex> work_lock(_main_mutex);
    _cond_var.wait(work_lock, []{return _data_ready;});

    _shared_work[1] = 2;

    std::cout << "T" << id << ": Work done." << std::endl;
}

void setDataReady(int id)
{
    std::cout << "T" << id << ": Create the vector." << std::endl;
    _shared_work = {1, 0, 3};

    {
        std::lock_guard<std::mutex> data_lock(_main_mutex);
        _data_ready = true;
    }

    std::cout << "T" << id << ": Data prepared, notifying..." << std::endl;
    _cond_var.notify_all();
}

int main()
{
    std::cout << std::endl;
    _data_ready = false;

    std::thread t1(waitingForWork, 1);
    std::thread t2(waitingForWork, 2);
    std::thread t3(setDataReady, 3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "The vector elements are as follows." << std::endl;
    for ( auto v : _shared_work )
    {
        std::cout << v << " ";
    }

    std::cout << std::endl << std::endl;
}