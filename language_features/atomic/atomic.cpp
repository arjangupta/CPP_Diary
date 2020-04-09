// Compare this program to ../condition_variable/condition_variable.cpp
// Inspired by https://www.modernescpp.com/index.php/the-atomic-boolean

#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>

std::vector<int> _shared_work;
std::atomic_bool _is_data_ready(false);

void waitingForWork(int thread_id)
{
    std::cout << "T" << thread_id << ": Waiting..." << std::endl;
    
    while ( ! _is_data_ready.load() )
    {
        std::cout << "T" << thread_id << ": About to sleep" << std::endl; 
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    _shared_work[1] = 2;
    std::cout << "T" << thread_id << ": Work done." << std::endl;
}

void setDataReady(int thread_id)
{
    _shared_work   = {1, 0, 3};
    _is_data_ready = true;

    std::cout << "T" << thread_id << ": Data has been made ready." << std::endl;
}

int main()
{
    std::cout << std::endl;

    std::thread t1(waitingForWork, 1);
    std::thread t2(waitingForWork, 2);
    std::thread t3(setDataReady,   3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "The vector is as follows:" << std::endl;
    for ( auto v: _shared_work )
    {
        std::cout << v << " ";
    }

    std::cout << std::endl << std::endl;

    return 0;
}