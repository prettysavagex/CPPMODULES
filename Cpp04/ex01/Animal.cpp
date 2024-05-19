#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: Constructor Has Been Executed." << std::endl;
	this->type = "An Animal";
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal: Copy Constructor Has Been Executed." << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Animal: Copy Assignment Operator Function Has Been Executed." << std::endl;
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor Has Been Executed." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << GREEN << this->getType() << "? -Sounds Like Some Kind Of An Animal.." << RESET << std::endl;
}

void Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType()const
{
	return this->type;
}