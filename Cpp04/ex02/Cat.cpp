#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Constructor Has Been Executed." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : AAnimal()
{
	std::cout << "Cat: Copy Constructor Has Been Executed." << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat: Copy Assignment Operator Function Has Been Executed." << std::endl;
	AAnimal::type = copy.type;
	if(!this->brain)
    	this->brain = new Brain();
    *this->brain = *copy.brain;
	return(*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor Has Been Executed." << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << PINK << "What Does The " << this->getType() << " Says? -MEOW.." << RESET << std::endl;
}

Brain* Cat::brainin() const
{
	return this->brain;
}
