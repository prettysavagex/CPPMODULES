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
	std::cout << std::endl;
	try
	{
		Bureaucrat x("Thomas");
		Bureaucrat y("Grace", 15);
		AForm* rqf = new RobotomyRequestForm("Baymax");  //valgrind!!
		PresidentialPardonForm ppf("Michael");

		x.signAForm(*rqf);
		x.signAForm(ppf);
		x.executeForm(*rqf);
		x.executeForm(ppf);
		y.executeForm(ppf);
		
		delete rqf;
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << GREEN << "*******************************" << RESET << "\n""\n";

	Bureaucrat x("Oswald");
		ShrubberyCreationForm scf("Jason");
		x.executeForm(scf);
		x.signAForm(scf);
		for (size_t i = 0; i < 10; ++i) {
			x.increaseGrade();
		}
		x.signAForm(scf);
		x.executeForm(scf);
		for (size_t i = 0; i < 10; ++i) {
			x.increaseGrade();
		}
		x.executeForm(scf);
}