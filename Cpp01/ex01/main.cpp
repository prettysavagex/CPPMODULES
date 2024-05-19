#include "Zombie.hpp"

int main()
{
    Zombie *obj = zombieHorde(8, "Doctor Strange");
    for (int i = 0; i < 8; i++)
        obj[i].announce();
    delete[] obj;
    return 0;
}