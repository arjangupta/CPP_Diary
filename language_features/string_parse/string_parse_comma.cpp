#include <vector>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
    //Declarations
    std::string str = "0, 1";//,5,6,7";
    std::vector<int> int_vect;
    std::stringstream ss(str);

    //Iterate over string stream
    int i = 0;
    int count = 0;
    while (ss >> i)
    {
        int_vect.push_back(i);
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
        ++count;    
    }

    int first = 0;
    int second = 0;
    bool is_pair = false; 

    //Only need first two vals
    if (count >= 2)
    {
        is_pair = true;
        first  = int_vect[0];
        second = int_vect[1];
    }
    
    //Display vals if they were a pair
    if (is_pair)
    {
        std::cout << "First val is: " << first << std::endl;
        std::cout << "Second val is: " << second << std::endl;  
    }
    else
    {
        std::cout << "String didn't have a pair." << std::endl;
    }

    return 0;
}