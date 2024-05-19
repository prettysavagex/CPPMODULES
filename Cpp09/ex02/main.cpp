#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Error: Needed A Positive Integer Sequence As An Argument!" << std::endl;
		return -1;
	}
	PmergeMe pmerge;
	return pmerge.Pmerge(argc, argv);
	return 0;
}
