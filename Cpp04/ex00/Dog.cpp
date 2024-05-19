#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Constructor Has Been Executed." << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal()
{
	std::cout << "Dog: Copy Constructor Has Been Executed." << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog: Copy Assignment Operator Function Has Been Executed." << std::endl;
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor Has Been Executed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << BLUE << "What Does The " << this->getType() << " Says? -WOOF.." << RESET << std::endl;
}