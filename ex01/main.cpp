#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn;
		rpn.operate(av[1]);
		return 0;
	}
	std::cerr << "Error: Please Enter 1 Argument! \"INSTANCE: Digit Digit Operator Digit Operator...\"" << std::endl;
	return 1;
}