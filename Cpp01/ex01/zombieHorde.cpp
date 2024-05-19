#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zHorde;
    zHorde = new Zombie[N];

    int i = 0;
    while (i < N)
    {
        zHorde[i].setzombiename(name);
        i++;
    }
    return zHorde;
}