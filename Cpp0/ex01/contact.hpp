#pragma once
#include <iostream>

class contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkestsecret;

	public:
		
		void	setfirstname(std::string);
		void	setlastname(std::string);
		void	setnickname(std::string);
		void	setphonenumber(std::string);
		void	setdarkestsecret(std::string);

		std::string	getfirstname()const;
		std::string getlastname()const;
		std::string	getnickname()const;
		std::string	getphonenumber()const;
		std::string	getdarkestsecret()const;
};
