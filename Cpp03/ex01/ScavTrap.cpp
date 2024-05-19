#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "SCAVTRAP DEFAULT CONSTRUCTOR HAS BEEN CALLED." << "\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "#THE SCAVTRAP CONSTRUCTOR HAS BEEN EXECUTED#" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "#THE SCAVTRAP COPY CONSTRUCTER HAS BEEN EXECUTED#" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "#THE SCAVTRAP COPY ASSIGNMENT OPERATOR HAS BEEN EXECUTED#" << std::endl;
    
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoint = copy.hitPoint;
        this->energyPoint = copy.energyPoint;
        this->attackDamage = copy.attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "#THE SCAVTRAP DESTRUCTOR HAS BEEN EXECUTED#" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->hitPoint <= 0)
	{
		std::cout << GREEN << "ScavTrap: " << LBLUE << name << RESET <<  "Dont Have Enough Hit Points To Attack.." << std::endl;
		return;
	}
	if(this->energyPoint <= 0)
	{
		std::cout << GREEN << "ScavTrap: " << LBLUE << name << RESET <<  " Dont Have Enough Energy Points To Attack.." << std::endl;
		return;
	}
	this->energyPoint--;
	std::cout << GREEN << "ScavTrap: " << RESET << LBLUE << name << RESET << " Attacks " << PINK << target << RESET << " Causing " << attackDamage << " Points Of Damage! " << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << GREEN << "ScavTrap: " << RESET << LBLUE << name << RESET << " is in Gate Keeper Mode Right Now..." << std::endl;
}
