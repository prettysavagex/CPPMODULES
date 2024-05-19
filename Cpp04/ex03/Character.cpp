#include "Character.hpp"

Character::Character()
{

}

Character::Character(std::string name) : name(name)
{
    for(int i = 0; i < 4; i++)
        this->equipment[i] = 0;
}

Character::Character(const Character& copy)
{
    *this = copy;
}

Character& Character::operator=(const Character& copy)
{
    if(this != &copy)
        this->name = copy.name;
    for(int i = 0; i < 4; i++)
        this->equipment[i] = copy.equipment[i]->clone();
    return *this;
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
        if(this->equipment[i])
            delete this->equipment[i];
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    int i = 0;
    
    if (!m)
    {
        std::cout << "Empty Inventory." << std::endl;
        return;
    }
    while (this->equipment[i])
        i++;
    if (i > 3)
    {
        std::cout << "The Inventory Is Full!" << std::endl;
        return ;
    }
    if(m && equipment[i] == NULL)
        this->equipment[i] = m;
}
        

void Character::unequip(int idx)
{
    if (!this->equipment[idx]) 
    {
        std::cout << "Already an empty inventory!";
        return ;
    }
    if (idx < 0 || idx > 3) 
    {
        std::cout << "Wrong index, does not exist in the inventory!" << std::endl;
        return;
    }
    if(idx && equipment[idx] != NULL)
        this->equipment[idx] = 0;
}


void Character::use(int idx, ICharacter& target)
{
    if (!this->equipment[idx])
    {
        std::cout << "There isnt any equipment in the inventory!" << std::endl;
        return;
    }
    if (idx < 0 || idx > 3) 
    {
        std::cout << "Theres no equipment like this to use in the inventory." << std::endl;
        return;
    }
    this->equipment[idx]->use(target);
}