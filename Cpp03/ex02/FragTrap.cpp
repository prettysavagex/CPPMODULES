#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "#FRAGTRAP DEFAULT CONSTRUCTOR HAS BEEN CALLED#" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "#THE FRAGTRAP CONSTRUCTOR HAS BEEN EXECUTED#" << std::endl;
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "#THE FRAGTRAP COPY CONSTRUCTOR HAS BEEN EXECUTED#" << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "#THE FRAGTRAP COPY ASSIGNMENT OPERATOR HAS BEEN EXECUTED#" << std::endl;
    if(this != &copy)
    {
        this->name = copy.name;
        this->hitPoint = copy.hitPoint;
        this->energyPoint = copy.energyPoint;
        this->attackDamage = copy.attackDamage;    
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "#THE FRAGTRAP DESTRUCTOR HAS BEEN EXECUTED#" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << PURPLE << "FragTrap: " << RESET << LBLUE << name << RESET << " Wanna High Five, Guys? ;)" << std::endl;
}