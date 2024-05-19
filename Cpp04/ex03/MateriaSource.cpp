#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i <= 3; i++)
        this->equipment[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& copy)
{
    for (int i = 0; i <= 3; i++)
        this->equipment[i] = copy.equipment[i];
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->equipment[i])
            delete this->equipment[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    
    if (!m) 
    {
        std::cout << "Cannot learn, the inventory is empty!" << std::endl;
        return;
    }
    while (this->equipment[i] != 0)
        i++;
    if (i > 3)
    {
        std::cout << "Overrange index to learn!" << std::endl;
        return ;
    }
    if(m && equipment[i] == NULL)
        this->equipment[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i <= 3; i++)
    {
        if (this->equipment[i] && this->equipment[i]->getType() == type)
            return this->equipment[i]->clone();
    }
    return NULL;
}
