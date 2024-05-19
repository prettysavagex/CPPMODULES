#include "phonebook.hpp"
#include <string>

int main()
{
	phonebook tmp;

	std::cout << std::endl;
    std::cout << "PhoneBook📞" << std::endl;
    std::cout << std::endl;
    std::cout << "|--------------USAGE---------------|" << std::endl;
    std::cout << "|ADD\t: To add a contact.        |" << std::endl;
    std::cout << "|SEARCH\t: To search for a contact. |" << std::endl;
    std::cout << "|EXIT\t: to quite the PhoneBook.  |" << std::endl;
    std::cout << "|----------------------------------|" << std::endl;
    std::cout  << std::endl;

	while(1)
	{
		std::string str;
		std::cout << "ENTER A COMMAND => ";
		std::getline(std::cin, str);

		if (str == "ADD")
			tmp.ADD();
		else if (str == "SEARCH")
			tmp.SEARCH();
		else if (str == "EXIT")
			break ;
	}
	return (0);
}