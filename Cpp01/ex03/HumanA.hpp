#pragma once
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &type;

    public:
        void attack();
        HumanA(std::string name, Weapon &type);
        ~HumanA();
};