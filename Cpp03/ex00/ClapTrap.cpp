#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "#THE DEFAULT CONSTRUCTOR HAS BEEN EXECUTED#" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "#THE CONSTRUCTOR HAS BEEN EXECUTED#" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "#THE COPY CONSTRUCTER HAS BEEN EXECUTED#" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "#THE COPY ASSIGNMENT OPERATOR HAS BEEN EXECUTED#" << std::endl;
	if(this != &copy)
	{
		this->name = copy.name;
		this->hitPoint = copy.hitPoint;
		this->energyPoint = copy.energyPoint;
		this->attackDamage = copy.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "#THE DESTRUCTOR HAS BEEN EXECUTED#" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->hitPoint <= 0)
	{
		std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  "Dont Have Enough Hit Points To Attack.." << std::endl;
		return;
	}
	if(this->energyPoint <= 0)
	{
		std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  " Dont Have Enough Energy Points To Attack.." << std::endl;
		return;
	}
	this->energyPoint--;
	std::cout << LYELLOW << "ClapTrap: " << RESET << LBLUE << name << RESET << " Attacks " << PINK << target << RESET << " Causing " << attackDamage << " Points Of Damage! " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->hitPoint <= 0)
	{
		std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  hitPoint << " No More Damage, Already Lost The Game!" << std::endl;
		return;
	}
	if(this->hitPoint <= (int)amount)
	{
		this->hitPoint -= amount;
		std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  " Too Much Damage Detected! Got Attacked " << amount << " Points, Game Over.." << std::endl;
		return;
	}
	this->hitPoint -= amount;
	std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  " Took " << amount << " Points Of Damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->energyPoint <= 0)
	{
		std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  " Unsufficient Energy Points To Be Repaired! Game Over.." << std::endl;
		return;
	}
	if(this->hitPoint <= 0)
	{
		std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  " No Hit Points Left, Cant Be Repaired! Game Over.." << std::endl;
		return;
	}
	this->hitPoint += amount;
	this->energyPoint--;
	std::cout << LYELLOW << "ClapTrap: " << LBLUE << name << RESET <<  " Repaired Succesfully! Total: " << hitPoint << " Hit Points ^^ Continue.." << std::endl;
}

int ClapTrap::checkStatus()
{
	if(this->hitPoint <= 0 || this->energyPoint <= 0)
		return 0;
	return 1;
}