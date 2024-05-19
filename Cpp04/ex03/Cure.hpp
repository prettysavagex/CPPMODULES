#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& copy);
        Cure& operator=(const Cure& copy);
        ~Cure();

        std::string getType() const;
        AMateria* clone() const;
        void use(ICharacter& target);
};