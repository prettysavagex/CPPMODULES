#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

class RPN
{
	private:
		std::stack<double> stack;
	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
		void operate(std::string);
		void calculate(std::string);
		int strToInt(const std::string& str);
};

#endif