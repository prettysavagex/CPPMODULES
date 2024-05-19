#include "phonebook.hpp"
#include <string>
#include <iomanip>
#include <sstream>
#include "contact.hpp"
#include <cctype>

void phonebook::ADD(){
	std::string str;
	static int	i = 0;
	
	if (i > 7)
		i = 0;
	while (str.empty())
	{
		std::cout << "First Name: ";
		std::getline(std::cin, str);
		this->person[i].setfirstname(str);
	}
	str = "";

	while (str.empty())
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, str);
		this->person[i].setlastname(str);
	}
	str = "";

	while (str.empty())
	{
		std::cout << "Nick Name: ";
		std::getline(std::cin, str);
		this->person[i].setnickname(str);
	}
	str = "";

	while (str.empty())
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, str);
		this->person[i].setphonenumber(str);
	}
	str = "";

	while (str.empty())
	{
		std::cout << "Dark Secret: ";
		std::getline(std::cin, str);
		this->person[i].setdarkestsecret(str);
	}
	this->index++;
	i++;
}

std::string shortening(std::string str)
{
	int i = 0;
	std::string a;

	if (str.length() > 10)
	{
		while(i < 9)
			a += str[i++];
		a += ".";
	}
	else
		return(str);
	return (a);
}
int	ft_stoi(const std::string &str)
{
	std::istringstream iss(str);
	int result;
	if (!(iss >> result))
		std::cout << "Not an index" << std::endl;
	return result;
}

void phonebook::SEARCH(){
	int i = 0;
	int z = 1;
	int j = this->index;

	if (j > 7)
		j = 8;

	std::cout << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Name" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "=============================================" << std::endl;
		
	while(i < j) {
		std::cout << "|" << std::setw(10) << z << "|";
		std::cout << std::setw(10) << shortening(person[i].getfirstname()) << "|";
		std::cout << std::setw(10) << shortening(person[i].getlastname()) << "|";
		std::cout << std::setw(10) << shortening(person[i].getnickname()) << "|" << std::endl;
		i++;
		z++;
	}
	while (index)
	{
		std::string str;
		std::cout << "ENTER AN INDEX NUMBER: ";
		std::getline(std::cin, str);
		if (str == "exit" || str == "EXIT")
			return;

		if (std::isdigit(str[0]) && !str[1])
		{
			j = ft_stoi(str);
			if (j > index || j == 0 || j == 9)
			{
				std::cout << "OUT OF RANGE" << std::endl;
				continue;
			}
			j--;
		}
		else
		{
			std::cout << "WRONG INDEX" << std::endl;
			continue;
		}
		if (j <= 7 && j >= 0 && j < this->index)
		{
			std::cout << std::endl;
			std::cout << "=============================================" << std::endl;
			std::cout << "Name          : " << this->person[j].getfirstname() << std::endl;
			std::cout << "Last Name     : " << this->person[j].getlastname() << std::endl;
			std::cout << "Nickname      : " << this->person[j].getnickname() << std::endl;
			std::cout << "Phone Number  : " << this->person[j].getphonenumber() << std::endl;
			std::cout << "Darkest Secret: " << this->person[j].getdarkestsecret() << std::endl;
			std::cout << "=============================================" << std::endl;
		}
		else
			return ;
	}
}

phonebook::phonebook(){

}
phonebook::~phonebook(){

}