#include <iostream>
#include <unistd.h>
#include <fcntl.h>

class WatchdogRefresher final
{
public:
    WatchdogRefresher() : _watchdog_file_descriptor(0)
    {
        _watchdog_file_descriptor = open("/dev/watchdog/", O_WRONLY);
        if ( _watchdog_file_descriptor == -1 )
        {
            std::cout << "Failed to open watchdog file." << std::endl;
        }
    }

    ~WatchdogRefresher()
    {
        if ( _watchdog_file_descriptor != -1 )
        {
            close(_watchdog_file_descriptor);
        }
    }
    
    void refresh()
    {
        if ( _watchdog_file_descriptor == -1 )
        {
            _watchdog_file_descriptor = open("/dev/watchdog/", O_WRONLY);
            if ( _watchdog_file_descriptor == -1 )
            {
                std::cout << "Failed to open watchdog file." << std::endl;
                return;
            }
        }

        if ( write(_watchdog_file_descriptor, "x", 1) != 1 )
        {
            std::cout << "Writing to watchdog file failed!" << std::endl;
        }
        else
        {
            std::cout << "Wrote 1 character to watchdog file." << std::endl;
        }

        return;
    }

private:
    int _watchdog_file_descriptor;
};

int main()
{
    WatchdogRefresher watchdog_refresher;

    while(1)
    {
        watchdog_refresher.refresh();
        sleep(10);
        // std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    return 0;
}