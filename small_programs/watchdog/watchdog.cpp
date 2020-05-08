#include <iostream>
#include <fstream>
#include <thread>

int main()
{
    std::ofstream watchdog_file("/dev/watchdog");
	
    if ( ! watchdog_file.is_open() )
    {
		std::cout << "Failed to open watchdog file." << std::endl;
		return -1;
	}

    int return_value = 0;
    int i = 0;
	while(1)
    {
        watchdog_file << "\0";
	    if ( watchdog_file.fail() )
        {
            std::cout << "Failed to write to the watchdog file." << std::endl;
			return_value = -2;
			break;
		}
        std::cout << i++ << ": wrote null char to watchdog file." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}
    
    watchdog_file.close();
	
    return return_value;
}