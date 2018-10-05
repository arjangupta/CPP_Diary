#include <iostream>
#include <string>

std::string yesOrNo(bool expression)
{
    return ( (expression) ? ("Yes.") : ("No.") );
}

int main()
{
    int i = 9;
    int *p = &i;
    int *q = p;
    int j = 9;
    int *r = &j;

    std::cout << "Are p and q pointing at the same address? " << yesOrNo(p == q) << std::endl;
    
    std::cout << "Are p and r pointing at the same address? " << yesOrNo(p == r) << std::endl;
    
    std::cout << "Are p and q pointing to an int of the same value? " << yesOrNo(*p == *q) << std::endl;
    
    std::cout << "Are p and r pointing to an int of the same value? " << yesOrNo(*p == *r) << std::endl;
}