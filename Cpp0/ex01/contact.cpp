#include <iostream>
#include "contact.hpp"

void	contact::setfirstname(std::string name)	{
	this->firstname = name;
}

void	contact::setlastname(std::string name) {
	this->lastname = name;
}

void	contact::setnickname(std::string name) {
	this->nickname = name;
}

void	contact::setphonenumber(std::string number) {
	this->phonenumber = number;
}

void	contact::setdarkestsecret(std::string secret) {
	this->darkestsecret = secret;
}

std::string	contact::getfirstname()const {
	return(this->firstname);
}
std::string	contact::getlastname()const {
	return(this->lastname);
}
std::string	contact::getnickname()const {
	return(this->nickname);
}
std::string	contact::getphonenumber()const {
	return(this->phonenumber);
}
std::string	contact::getdarkestsecret()const {
	return(this->darkestsecret);
}