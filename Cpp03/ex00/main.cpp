#include "ClapTrap.hpp"

int main()
{
	std::cout << std::endl << BROWN << "GET READY TO FLY IN 3.. 2.. 1.. " << RESET << std::endl << "\n";

	ClapTrap obj("JEDI");
	ClapTrap obj2("SKYWALKER");
	
	std::cout << std::endl << LRED << "***********************STAR WARS***********************" << RESET << std::endl << std::endl;
	
	std::cout << RED << "               \\\\\\\\\\ JEDI X SITH /////" << RESET << std::endl << std::endl;

	while(obj.checkStatus())
		obj.attack("SITH");
	obj.takeDamage(7);
	obj.beRepaired(5);
	obj.attack("DARTH VADER");

	std::cout << std::endl << RED << "          \\\\\\\\\\ SKYWALKER X DARTH VADER /////" << RESET << std::endl << std::endl;

	obj2.attack("DARTH VADER");
	obj2.takeDamage(3);
	obj2.beRepaired(6);
	obj2.takeDamage(13);
	obj2.beRepaired(2);

	std::cout << std::endl << LRED << "________________________THE END________________________" << RESET << std::endl << "\n";

	return 0;
}