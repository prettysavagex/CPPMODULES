#pragma once
#include <iostream>
#include "contact.hpp"

class phonebook
{
	private:
		int index;

	public:
		contact	person[8];
		phonebook();
		~phonebook();
		void	ADD();
		void	SEARCH();
};
