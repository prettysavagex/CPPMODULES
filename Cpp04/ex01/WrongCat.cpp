#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "Wrong Cat";
    std::cout << "Wrong Cat: Constructor Has Been Executed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal()
{
    std::cout << "Wrong Cat: Copy Constructor Has Been Executed." << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    std::cout << "Wrong Cat: Copy Assignment Operator Function Has Been Executed." << std::endl;
    if(this != &copy)
        this->type = copy.getType();
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong Cat: Destructor Has Been Executed." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << this->getType() << " meows..." << std::endl;
}