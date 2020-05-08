#include <iostream>
#include <unistd.h>
#include <fcntl.h>

class SomeObject final
{
public:
    SomeObject() {}

    ~SomeObject() {}
    
    void refreshWatchdog()
    {
        int fd = open("/dev/watchdog", O_WRONLY);
        
        if (fd == -1)
        {
            std::cout << "Failed to open watchdog file." << std::endl;
            return;
        }
        else
        {
            std::cout << "Successfully opened the watchdog file." << std::endl;
        }

        if (write(fd, "\0", 1) != 1)
        {
            std::cout << "Failed to write to watchdog file." << std::endl;
        }
        else
        {
            std::cout << "Wrote null char to watchdog file." << std::endl;
        }
        close(fd);
    }
};

int main()
{
    SomeObject watchdog_refresher;

    while(1)
    {
        watchdog_refresher.refreshWatchdog();
        sleep(10);
        // std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}