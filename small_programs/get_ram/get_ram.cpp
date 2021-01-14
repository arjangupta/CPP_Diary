#include <iostream>
#include <cstdlib>

int main()
{
    // Execute the command to get the memory
    system("free -m | grep Mem: > mem.txt");
    return 0;
}