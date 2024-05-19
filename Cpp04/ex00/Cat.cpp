#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Constructor Has Been Executed." << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal()
{
	std::cout << "Cat: Copy Constructor Has Been Executed." << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat: Copy Assignment Operator Function Has Been Executed." << std::endl;
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor Has Been Executed." << std::endl;

}

void Cat::makeSound() const
{
	std::cout << PINK << "What Does The " << this->getType() << " Says? -MEOW.." << RESET << std::endl;
}
