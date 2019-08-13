#include <iostream>
#include <map>

int main()
{
    std::map<std::string, unsigned long> people_net_worth;
    people_net_worth["Bill Gates"] = 103700000000;
    people_net_worth["Jeff Bezos"] = 112500000000;
    people_net_worth["Elon Musk"]  = 19900000000;

    for (auto const& big_guy : people_net_worth)
    {
        std::cout << big_guy.first << ": " << big_guy.second << std::endl;
    }

    return 0;
}