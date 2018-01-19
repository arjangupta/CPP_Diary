#include <iostream>
#include <cstring>
#include <iterator>

void printUCA(unsigned char *arr, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
    {
        printf("%u ", arr[i]);
    }   
}

int main()
{
    std::string comp = "abcxyz[w";
    //unsigned char q[4];
    unsigned char comp2[comp.size()];
    std::memcpy(&comp2[0], &comp.c_str()[0], comp.size());
    printUCA(comp2, comp.size());
    std::cout << std::endl;
    printf("%u", std::begin(comp2));
    //std::cout << comp2 << std::endl;
    //std::cout << sizeof(comp) << " " << sizeof(q) << std::endl;
    /*
    std::memcpy(q, &comp.c_str()[comp.size() - 3], 3);
    q[3] = '\0';
    std::string hello(q);
    std::cout << hello << std::endl;
    char r[(comp.size() - 3) + 1];
    std::memcpy(r, &comp.c_str()[0], comp.size() - 3);
    r[comp.size() - 3] = '\0';
    std::string hello1(r);
    std::cout << hello1 << std::endl;
    */
}
