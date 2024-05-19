#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
}

Ice::Ice(const Ice& copy) : AMateria()
{
    *this = copy;
}

Ice& Ice::operator=(const Ice& copy)
{
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

Ice::~Ice()
{

}

std::string Ice::getType()const
{
    return this->type;
}

AMateria* Ice::clone() const
{
    Ice* clone = new Ice();
    return clone;
}

void Ice::use(ICharacter& target)
{
     std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
}