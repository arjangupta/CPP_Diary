// Compare this program to ../condition_variable/condition_variable.cpp
// Inspired by https://www.modernescpp.com/index.php/the-atomic-boolean

#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>

std::vector<int> _shared_work;
std::atomic<bool> _is_data_ready(false);

void waitingForWork(int thread_id)
{
    std::cout << "Waiting..." << std::endl;
    
    while ( ! _is_data_ready.load() )
    {
        std::cout << "About to sleep" << std::endl; 
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    _shared_work[1] = 2;
    std::cout << "Work done." << std::endl;
}

void setDataReady()
{

}

int main()
{
    return 0;
}