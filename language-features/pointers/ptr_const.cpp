#include <iostream>

int main()
{
    int a = 9;
    int * const b = &a;
    int * const * c = &b;
    int * const ** q = &c;

    std::cout << "***q is: " << ***q << std::endl; //Output: "***q is: 9"

    //Commenting in the following lines leads 
    //to a compiler error because **q is read-only.
    // int x = 6;
    // **q = &x;
}