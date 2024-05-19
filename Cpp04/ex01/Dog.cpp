#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Constructor Has Been Executed." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal()
{
	std::cout << "Dog: Copy Constructor Has Been Executed." << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog: Copy Assignment Operator Function Has Been Executed." << std::endl;
	Animal::type = copy.type;
	*this->brain = *copy.brain;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor Has Been Executed." << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << BLUE << "What Does The " << this->getType() << " Says? -WOOF.." << RESET << std::endl;
}

Brain *Dog::brainin() const
{
	return this->brain;
}