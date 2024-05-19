#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor Has Been Executed." << std::endl;
    for(int i = 0; i < 100; i++)
        ideas[i] = "Brain is not brainin..";
}

Brain::Brain(const Brain& copy)
{
    std::cout << "Brain Copy Constructor Has Been Executed." << std::endl;
    *this = copy;   
}

Brain& Brain::operator=(const Brain& copy)
{
    std::cout << "Brain Copy Assignment Operator Function Has Been Executed." << std::endl;
    for(size_t i = 0; i < copy.ideas->size(); i++)
        this->ideas[i] = copy.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Has Been Executed." << std::endl;
}

