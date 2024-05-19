#include "conversion.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert_char(const std::string& str)
{
	char c = str[0];
	std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int:" << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convert_int(const std::string& str)
{
	int i = atol(str.c_str());
	if (Int_Range(i))
	{
		if ((i < 32 || i >= 126))
			std::cout << "Char: Non displayable" << std::endl;
		else
			std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "Int: " << i << std::endl;
		std::cout << "Float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(i) << ".0" << std::endl;
	}
}

void ScalarConverter::convert_pseudo(const std::string& str)
{
	if (str == "nanf" || str == "nan")
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	else if (str == "inf" || str == "inff")
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: inff" << std::endl;
		std::cout << "Double: inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: -inff" << std::endl;
		std::cout << "Double: -inf" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: +inff" << std::endl;
		std::cout << "Double: +inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	if (str == "nanf" || str == "nan" || str == "inf" || str == "inff"
			|| str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
		convert_pseudo(str);
	else if ((str.length() == 1) && ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')))
		convert_char(str);
	else if ((str.length() != 1) && ((!Int_Range(atol(str.c_str()))) || ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))))
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
	}
	else
		convert_int(str);
}
