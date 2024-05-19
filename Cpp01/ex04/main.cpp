#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Please enter at least 3 arguments: Filename, String to place, String to be replaced" << std::endl;
        return(EXIT_FAILURE);
    }
    else
    {
        Replacer file(av[1]);
        file.replacer(av[2], av[3]);
    }
    return (EXIT_SUCCESS);
}