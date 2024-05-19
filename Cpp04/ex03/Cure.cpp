#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
}

Cure::Cure(const Cure& copy) : AMateria()
{
    *this = copy;
}

Cure& Cure::operator=(const Cure& copy)
{
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

Cure::~Cure()
{

}

std::string Cure::getType()const
{
    return this->type;
}

AMateria* Cure::clone() const
{
    Cure* clone = new Cure();
    return clone;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() <<"'s wounds *"<< std::endl;
}