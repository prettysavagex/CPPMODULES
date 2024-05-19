#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << std::endl << BROWN << "GET READY TO FLY IN 3.. 2.. 1.. " << RESET << std::endl << "\n";

	ScavTrap obj("YODA");
	FragTrap obj2("HAN SOLO");
	
	std::cout << std::endl << LRED << "***********************STAR WARS***********************" << RESET << std::endl << std::endl;
	
	std::cout << RED << "               \\\\\\\\\\ YODA X SITH /////" << RESET << std::endl << std::endl;

	for(int i = 0; i < 11; i++)
		obj.attack("SITH");
	obj.takeDamage(7);
	obj.beRepaired(5);

	std::cout << std::endl << RED << "          \\\\\\\\\\ HAN SOLO X DARTH VADER /////" << RESET << std::endl << std::endl;

	obj2.attack("DARTH VADER");
	obj2.takeDamage(30);
	obj2.beRepaired(21);
	obj2.takeDamage(400);
	obj2.beRepaired(2);
	obj2.highFivesGuys();

	std::cout << std::endl << LRED << "________________________THE END________________________" << RESET << std::endl << "\n";

	return 0;
}