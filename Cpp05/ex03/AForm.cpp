#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : Name("Undefined"), Signed(false), signGrade(150), executeGrade(150)
{

}

AForm::AForm(std::string name) : Name(name), Signed(false), signGrade(150), executeGrade(150)
{

}

AForm::AForm(std::string name, int requiredsG, int requiredexG) : Name(name), Signed(false), signGrade(requiredsG), executeGrade(requiredexG)
{
	if (requiredsG < 1 || requiredexG < 1)
		throw GradeTooHighException();
	else if (requiredsG > 150 || requiredexG > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : Name(copy.getName()), signGrade(getSignGrade()), executeGrade(getExecuteGrade())
{
	*this = copy;
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		Signed = copy.Signed;
	return *this;
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
	return  Name;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecuteGrade() const
{
	return executeGrade;
}

std::string AForm::getSigned() const
{
	if (Signed == true)
		return "true";
	return "false";
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->Signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!Signed)
		throw FormNotSignedException();
	if (executor.getGrade() >= executeGrade)
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << Name << std::endl;
	Executor();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm -> Out Of Range : Too High Grade!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm -> Out Of Range : Too Low Grade!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm: Form not signed!";
};

std::ostream& operator<<(std::ostream &os, const AForm& Aform)
{
	os << Aform.getName() << ", required grade to sign " << Aform.getSignGrade() << ", required grade to execute " << Aform.getExecuteGrade() << ", is signed " << Aform.getSigned() << std::endl;
	return os;
}
