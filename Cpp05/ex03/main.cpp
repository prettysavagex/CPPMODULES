#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RESET "\033[0m"
#define PINK  "\033[38;5;206m"
#define GREEN  "\033[92m"
#define YELLOW "\033[93m"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
	try 
	{
		Bureaucrat a("V", 44);
		a.signAForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	AForm* zpf;
	try
	{
		zpf = someRandomIntern.makeForm("NOT FOUND FORM", "nothing");
		delete zpf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}