#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("Robotomy Request", 72, 45), Target("Default")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("Robotomy Request", 72, 45), Target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm::AForm("Robotomy Request", 72, 45)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		Target = copy.Target;
	return *this; 
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::Executor() const
{
	std::srand(time(0));
	size_t t = std::rand();

	std::cout << "*DRILLING NOISES*" << std::endl;

	if (t % 2 == 0)
		std::cout << Target << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy " << Target << " failed!" << std::endl;
}