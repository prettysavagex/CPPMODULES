#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream> //istringstream
#include <string> //getline

class BitcoinExchange
{
	private:
		std::map<std::string, double> data;
		std::map<std::string, double> input;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
		void read_infile(std::string);
		void read_datafile();
		bool check_date(const std::string &date) const;
		bool check_date_format(const std::string &date) const;
		double compare_dates(std::string key, double value);
		bool isValidDouble(const std::string& str);
		int daysInMonth(int year, int month)
};

#endif