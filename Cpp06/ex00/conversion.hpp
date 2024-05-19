#pragma once
#include <iostream>
#define Int_Range(value) ((value >= -2147483647 - 1) && (value <= 2147483647))

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();

		static void convert(const std::string& str);
		static void convert_char(const std::string& str);
		static void convert_int(const std::string& str);
		static void convert_pseudo(const std::string& str);
};