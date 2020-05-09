#include <iostream>
#include <string>
#include <set>

int main()
{
    std::set<std::string> names;
    names.insert("Andrew");
    names.insert("Simon");
    names.insert("Emily");
    names.insert("Chloe");

    std::cout << "Sorted names: ";

    for (auto const& name : names)
    {
        std::cout << name << " ";
    }

    std::cout << std::endl;

    return 0;
}
