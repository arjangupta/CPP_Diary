#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, long> people_net_worth;
    people_net_worth["Bill Gates"] = 103700000000;
    people_net_worth["Jeff Bezos"] = 112500000000;
    people_net_worth["Elon Musk"]  = 19900000000;
    people_net_worth["John Doe"]   = 55000;

    std::map<long, std::string, std::greater<long>> net_worth_people;

    std::cout << "UNORDERED MAP -" << std::endl;

    for (auto const& big_guy : people_net_worth)
    {
        std::cout << big_guy.first << ": " << big_guy.second << std::endl;
        net_worth_people.insert(std::make_pair(big_guy.second, big_guy.first));
    }

    std::cout << std::endl
              << "ORDERED MAP -" << std::endl;

    for (auto const& big_money : net_worth_people)
    {
        std::cout << big_money.second << ": " << big_money.first << std::endl;
    }

    return 0;
}