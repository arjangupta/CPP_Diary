### Watchdog Usage

The watchdog.cpp is the c-style approach, it is very similar to what is given in samples/watchdog/watchdog-simple.c of the linux kernel repo. It works.

The watchdog_ineffective_approach.cpp tries to use the C++ fstream to write to the watchdog, but this doesn't work. TODO: Find out why.

The watchdog_object.cpp also works, but only if you keep the file descriptor int within the same scope of the member function that opens and writes to the watchdog. If you try to use a member variable int for the file descriptor, it doesn't work. TODO: Find out why.

Another interesting thing - on the armhf debian OS, when I run the watchdog.cpp, there are no messages in the main terminal. However, when I run watchdog_object.cpp, I continuously see the "[  xxx.xxxxxx] watchdog: watchdog0: watchdog did not stop!" message every time a char is written. TODO: Find out why.