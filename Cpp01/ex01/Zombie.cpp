#include "Zombie.hpp"

void    Zombie::setzombiename(std::string name)
{
    this->name = name;
}

Zombie::Zombie()
{

}

Zombie::~Zombie(void)
{
    std::cout << this->name << " Has Been Deleted" << std::endl;
}