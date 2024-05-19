#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if(this != &copy)
	{
		data = copy.data;
		input = copy.input;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDouble(const std::string& str)
{
	std::istringstream iss(str);
	double value;
	iss >> value;
	return !iss.fail() && iss.eof(); // If it can be convertd to a valid double and has read entirely, returns true.
}

double BitcoinExchange::compare_dates(std::string key, double value)
{
	std::map<std::string, double>::iterator iter = data.upper_bound(key);
	if (iter != data.begin())
	{
		--iter;
		if (iter->second * value > 0 && iter->second * value < 1000)
			return (iter->second * value);
	}
	return (0.0);
}

int BitcoinExchange::daysInMonth(int year, int month) const
{
	if (month == 02)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29; // if leap year, February has 29 days
		}
		else
		{
			return 28; // if not leap year, February has 28 days
		}
	}
	else if (month == 04 || month == 06 || month == 9 || month == 11)
	{
		return 30;
	}
	else
	{
		return 31;
	}
}

bool BitcoinExchange::check_date(const std::string &date) const
{
	std::istringstream iss(date);
	char dash1, dash2;
	int year, month, day;
	
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	if (dash1 != '-' || dash2 != '-' || year < 2000 || year > 2022 || month < 01 || month > 12 || day < 01 || day > this->daysInMonth(year, month))
		return false;
	return true;
}

bool BitcoinExchange::check_date_format(const std::string &date) const
{
	if (date.empty())
	{
		return false;
	}
	if (date.length() != 10)
	{
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		return false;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	if (!check_date(date))
		return false;
	return true;
}

void BitcoinExchange::read_datafile()
{
	std::ifstream file("data.csv");

	if (!file)
	{
		std::cerr << "Error: Failed To Find The Data File!" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;

	std::getline(file, line);
	while (std::getline(file, line)) //theres no 3rd parameter(delimiter) so by default delimiter is \n
	{
		std::istringstream iss(line);
		std::string key;
		double value;

		if (std::getline(iss, key, ',') && (iss >> value))
		{
			data[key] = value;
		}
		else
			std::cerr << "Failed to get the line: " << line << std::endl;
	}
	file.close();
}

void BitcoinExchange::read_infile(std::string infile)
{
	std::ifstream file(infile.c_str());

	if (file.fail() || !file.is_open())
	{
		std::cerr << "Error: Failed To Find The Input File!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;

	std::getline(file, line); //skip the first line
	while (std::getline(file, line)) //theres no 3rd parameter(delimiter) so by default delimiter is \n
	{
		if (line.size() == 0)
		{
			std::cerr << "Error: Empty line found!" << std::endl;
			continue;
		}

		std::istringstream iss(line);
		std::string date;
		std::string rateStr;

		if (line.find('|') == std::string::npos)
		{
			date = line;
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if(std::getline(iss, date, '|'))
		{
			if (!date[0])
			{
				std::cerr << "Error: There's no such date!" << std::endl;
				continue;
			}

			date.erase(0, date.find_first_not_of(" \t\r\n"));
			date.erase(date.find_last_not_of(" \t\r\n") + 1);

			if (date[0] && !check_date_format(date))
			{
				std::cerr << "Error: Wrong Date => " << date << std::endl;
				continue;
			}

			std::string rateStr;
			if (!std::getline(iss, rateStr))
			{
				std::cerr << "Error: Missing rate value." << std::endl;
				continue;
			}
			/* if(input.find(date) != input.end())
			{
				std::cerr << "Error: Duplicate date." << std::endl;
				continue;
			} */
			if (!isValidDouble(rateStr))
			{
				std::cerr << "Error: not a valid number." << std::endl;
				continue;
			}

			double rate = atof(rateStr.c_str());

			if (rate < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (rate > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			input[date] = rate;
			std::cout << date << " => " << rate << " = " << compare_dates(date, rate) << std::endl;
		}
		else
		{
			std::cerr << "Failed to get the line: " << line << std::endl;
		}
	}
	file.close();
}
