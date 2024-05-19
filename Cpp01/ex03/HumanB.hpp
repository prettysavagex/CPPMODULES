#pragma once
#include "HumanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *type;

    public:
        void attack();
        void setWeapon(Weapon &type);
        HumanB(std::string name);
        ~HumanB();
};