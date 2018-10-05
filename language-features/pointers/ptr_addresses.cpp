#include <iostream>

int main()
{
    int i = 9;
    int *p = &i;
    int *q = p;
    int j = 9;
    int *r = &j;
    
    bool b = p == q;
    std::cout << "Are p and q pointing at the same address? " << b << std::endl;
    
    b = p == r;
    std::cout << "Are p and r pointing at the same address? " << b << std::endl;
    
    b = *p == *q;
    std::cout << "Are the values at the addresses of p and q the same? " << b << std::endl;
    
    b = *p == *r;
    std::cout << "Are the values at the addresses of p and r the same? " << b << std::endl;
}