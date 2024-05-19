#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;

	if (ac == 2)
	{
		btc.read_datafile();
		btc.read_infile(av[1]);
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		return -1;
	}
	return 0;
}