#include "Zombie.hpp"

int main()
{
    Zombie firstzombie("Rogers");
    Zombie secondzombie("Stark");
    std::cout << "Rogers Has Been Created" << std::endl;
    std::cout << "Stark Has Been Created" << std::endl;
    firstzombie.announce();
    secondzombie.announce();
    Zombie *thirdzombie = newZombie("Parker");
    std::cout << "Parker Has Been Created" << std::endl;
    thirdzombie->announce();
    delete thirdzombie;
    std::cout << "Romanoff Has Been Created" << std::endl;
    randomChump("Romanoff");
    return 0;
}

