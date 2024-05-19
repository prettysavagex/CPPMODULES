#include "Weapon.hpp"
#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with their " << type.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &type) : type(type)
{
    this->name = name;
}

HumanA::~HumanA()
{
    
}