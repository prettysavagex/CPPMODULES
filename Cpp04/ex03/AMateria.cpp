#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const & type) : type(type)
{

}

AMateria::AMateria(const AMateria& copy)
{
    *this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy)
{
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

AMateria::~AMateria()
{

}

std::string const& AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}