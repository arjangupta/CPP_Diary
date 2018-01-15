/* Author: Arjan Gupta
 * Purpose: Just trying out an enum class
 */

#include <iostream>

enum class Color { red, green, blue = 100 };

std::ostream& operator<<(std::ostream& os, Color c)
{
    switch (c)
    {
        case Color::red   : os << "red";    break;
        case Color::green : os << "green";  break;
        case Color::blue  : os << "blue";   break;
        default    : os.setstate(std::ios_base::failbit);
    }
    return os;
}

int main ()
{
	Color which_color = Color::green;
	std::cout << "Color is " << which_color << std::endl;
	std::cout << "Color value is " << static_cast<int>( which_color ) << std::endl;

	return 0;
}