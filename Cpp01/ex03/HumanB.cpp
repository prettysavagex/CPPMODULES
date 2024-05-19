#include "Weapon.hpp"
#include "HumanB.hpp"

void HumanB::attack()
{
    if (type)
        std::cout << name << " attacks with their " << type->getType() << std::endl;
    else
        std::cout << name << " is unarmed" << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
    this->type = &type;

}

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{

}