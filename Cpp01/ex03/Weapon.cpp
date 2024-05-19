#include "Weapon.hpp"

void    Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType()
{
    const std::string &t = this->type;
    return t;
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{

}
