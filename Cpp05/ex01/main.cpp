#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define PINK  "\033[38;5;206m"
#define GREEN  "\033[92m"
#define YELLOW "\033[93m"

int main()
{
	std::cout << std::endl;
	Bureaucrat x("Thomas");
	try
	{
		Form a("None", 1, 182);
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << GREEN << "*******************************" << RESET << "\n""\n";

	try
	{
		Bureaucrat y("Grace", 15);
		Form b("Participation Form", 15, 15);
		Form c(b);

		std::cout << b;
		y.signForm(b);
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << PINK << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat z("Arthur", 50);
		Form b("Capability Form", 40, 20);

		std::cout << b;

		z.signForm(b);

		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}
