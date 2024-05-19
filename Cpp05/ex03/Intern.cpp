#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern()
{

}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Intern: The Form Could Not Be Found";
}

AForm *Intern::makeShrubberyCreation(std::string target)
{
	std::cout << "Intern fills Shrubbery Creation Form" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequest(std::string target)
{
	std::cout << "Intern fills Robotomy Request Form" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardon(std::string target)
{
	std::cout << "Intern fills Presidential Pardon Form" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
	std::string names[3] = {
		"Shrubbery Creation"
		"Robotomy Request",
		"Presidential Pardon",
	};

	AForm* (Intern::*ptr[3])(std::string) =
	{
		&Intern::makeShrubberyCreation,
		&Intern::makeRobotomyRequest,
		&Intern::makePresidentialPardon,
	};
	
	for (size_t i = 0; i < 3; ++i)
	{
		if (names[i] == name)
			return (this->*ptr[i])(target);
	}
	throw Intern::FormNotFoundException();
}
