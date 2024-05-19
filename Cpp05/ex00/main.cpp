#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define BLUE  "\033[94m"
#define PINK  "\033[38;5;206m"
#define GREEN  "\033[92m"
#define YELLOW "\033[93m"

int main()
{
	Bureaucrat x("Thomas");
	std::cout << x << std::endl;
	try
	{
		x.decreaser();
	} 
	catch (std::exception &e)
	{
		std::cout << BLUE << e.what() << RESET << std::endl;
	}
	std::cout << x << std::endl;

	std::cout << "\n" << GREEN << "*******************************" << RESET << "\n""\n";

	try
	{
		Bureaucrat y("Grace", 3);
			for (size_t i = 0; i < 3; ++i)
			{
				std::cout << y << std::endl;
				y.increaser();
			}
		std::cout << y << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << PINK << e.what() << RESET << std::endl;
	}
}
