#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("/dev/watchdog", O_WRONLY);
	
    if (fd == -1)
    {
		std::cout << "Failed to open watchdog file." << std::endl;
		return -1;
	}

    int return_value = 0;
    int i = 0;
	while(1)
    {
	    if (write(fd, "\0", 1) != 1)
        {
			return_value = -2;
			break;
		}
        std::cout << i++ << ": wrote null char to watchdog file." << std::endl;
		sleep(10);
	}
	close(fd);
	return return_value;
}