#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& copy);
        Ice& operator=(const Ice& copy);
        ~Ice();

        std::string getType() const;
        AMateria* clone() const;
        void use(ICharacter& target);
};