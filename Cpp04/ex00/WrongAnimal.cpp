#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "Wrong Animal";
    std::cout << "Wrong Animal: Constructor Has Been Executed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << "Wrong Animal: Copy Constructor Has Been Executed." << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    std::cout << "Wrong Animal: Copy Assignment Operator Function Has Been Executed." << std::endl;
    if(this != &copy)
        this->type = copy.getType();
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong Animal: Destructor Has Been Executed." << std::endl;
}

void WrongAnimal::setType(std::string name)
{
    this->type = name;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << PURPLE << this->type << " Sounds Like A Wrong Animal.." << RESET << std::endl;
}