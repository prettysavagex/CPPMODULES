#include "AbstractAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Abstract Animal: Constructor Has Been Executed." << std::endl;
	this->type = "An AAnimal";
}

AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout << "AAnimal: Copy Constructor Has Been Executed." << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	std::cout << "AAnimal: Copy Assignment Operator Function Has Been Executed." << std::endl;
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor Has Been Executed." << std::endl;
}

void AAnimal::setType(std::string type)
{
	this->type = type;
}

std::string AAnimal::getType()const
{
	return this->type;
}