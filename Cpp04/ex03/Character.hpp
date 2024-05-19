#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    protected:
        std::string name;
        AMateria *equipment[4];
    public:
        Character();
        Character(std::string name);
        Character(const Character& copy);
        Character& operator=(const Character& copy);
        ~Character();

        std::string const & getName() const;

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};