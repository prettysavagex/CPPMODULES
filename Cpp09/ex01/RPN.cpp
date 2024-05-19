#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	this->stack = copy.stack;
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(std::string input)
{
	if (stack.size() < 2)
	{
		std::cerr << "Error: Not Enough Operands for Operation!" << std::endl;
		exit(-1);
	}
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();

	if (input == "+")
	{
		stack.push(a + b);
	}
	if (input == "-")
	{
		stack.push(b - a);
	}
	if (input == "*")
	{
		stack.push(a * b);
	}
	if (input == "/")
	{
		if (a == 0)
		{
			std::cout << "Error: Division by Zero!" << std::endl;
			exit(-1);
		}
		stack.push(b / a);
	}
}

int RPN::strToInt(const std::string& str)
{
	std::istringstream iss(str);
	int num;
	iss >> num;
	return num;
}

void RPN::operate(std::string str)
{
	std::string operators;

	if (str.size() == 0)
	{
		std::cout << "Error: Empty or Missing Input!" << std::endl;
		exit (-1);
	}

	std::string tmp;

	for (size_t i = 0; i < str.size(); i++)
	{
		tmp += str[i];
		if (str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/')
		{
			tmp += ' ';
			i++;
			tmp += str[i];
			tmp += ' ';
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			operators += str[i];
			str[i] = ' ';
		}
	}

	std::istringstream iss(tmp);
	std::string input;

	while (iss >> input)
	{
		if (input != "+" && input != "-" && input != "*" && input != "/" && input != "%")
		{
			for (size_t i = 0; i < input.size(); ++i) // size t because of the size() accepts type size t
			{
				if (!(isdigit(input[i])))
				{
					std::cout << "Error: Invalid Input!" << std::endl;
					exit(-1);
				}
				int num = strToInt(input);
				stack.push(num);
			}
		}
		else if (input == "+" || input == "-" || input == "*" || input == "/")
		{
			calculate(input);
		}
	}

	if (stack.size() == 0 || stack.size() > 1 || isdigit(stack.top()))
	{
		std::cout << "Error: Invalid RPN Expression!" << std::endl;
		exit(-1);
	}
	else
	{
		std::cout << stack.top() << std::endl;
	}
}