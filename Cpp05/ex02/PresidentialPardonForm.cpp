#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("Presidential Pardon", 25, 5), Target("Default")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("Presidential Pardon", 25, 5), Target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm::AForm("Presidential Pardon", 25, 5)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
		Target = copy.Target;
	return *this; 
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}


void PresidentialPardonForm::Executor() const
{
	std::cout << this->Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}