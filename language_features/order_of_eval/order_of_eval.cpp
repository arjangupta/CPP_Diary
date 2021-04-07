#include <iostream>

bool funcA(bool val)
{
    std::cout << "Function A!" << std::endl;
    return val;
}

bool funcB(bool val)
{
    std::cout << "Function B!" << std::endl;
    return val;
}

bool funcC(bool val)
{
    std::cout << "Function C!" << std::endl;
    return val;
}

bool funcD(bool val)
{
    std::cout << "Function D!" << std::endl;
    return val;
}

bool funcE(bool val)
{
    std::cout << "Function E!" << std::endl;
    return val;
}

bool funcF(bool val)
{
    std::cout << "Function F!" << std::endl;
    return val;
}

int main()
{
    // Chain up conditionals
    if ( funcA(false) 
        || funcB(false)
        || (funcC(false) && funcD(true))
        || funcE(true) )
    {
        std::cout << "Eval 1 TRUE!" << std::endl;
    }
    else
    {
        std::cout << "Eval 1 FALSE!" << std::endl;
    }

    // Chain up conditionals, experiment 2
    if ( funcA(false) 
        || funcB(false)
        || funcC(false) && funcD(true)
        || funcE(true) )
    {
        std::cout << "Eval 2: TRUE!" << std::endl;
    }
    else
    {
        std::cout << "Eval 2: FALSE!" << std::endl;
    }

    return 0;
}