#include <iostream>
#include <string>

std::string yesOrNo(bool expression)
{
    return ( (expression) ? ("Yes.") : ("No.") );
}

int main()
{
    int i  = 9;
    int *p = &i;
    int *q = p;
    int j  = 9;
    int *r = &j;

    std::cout << std::endl
              << "Are p and q pointing to the same address? " << yesOrNo(p == q) << std::endl
              << "Are p and r pointing to the same address? " << yesOrNo(p == r) << std::endl
              << std::endl
              << "Are p and q pointing to addresses at which there are ints of the same value? " << yesOrNo(*p == *q) << std::endl
              << "Are p and r pointing to addresses at which there are ints of the same value? " << yesOrNo(*p == *r) << std::endl
              << std::endl;
}