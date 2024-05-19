#pragma once
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        void    setzombiename(std::string name);
        void    announce(void);
        Zombie();
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );