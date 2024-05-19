#pragma once
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource 
{
    private:
        AMateria    *equipment[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource &operator=(const MateriaSource& copy);
        ~MateriaSource();
        
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};
