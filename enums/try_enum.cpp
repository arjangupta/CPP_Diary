/* Purpose: Just trying out an enum class
 */

#include <iostream>

enum class Color { red, green, blue = 100 };

int main ()
{
	Color which_color = Color::green;
	std::cout << "Color is " << static_cast<int>( which_color ) << std::endl;
}