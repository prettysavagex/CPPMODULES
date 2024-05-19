#include <iostream>

int	main(int ac, char **av)
{
	if(ac > 1)
	{
		int i = 1;
		int j = 0;
		std::string str;

		while(av[i])
		{
			j = 0;
			while(av[i][j])
			{
				str = (char)std::toupper(av[i][j]);
				std::cout << str;
				j++;
			}
			if(i < ac - 1)
				std::cout << ' ';
			i++;
		}
			std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}