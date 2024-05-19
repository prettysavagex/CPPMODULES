#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : Name("Undefined"), Signed(false), signGrade(150), executeGrade(150)
{

}

Form::Form(std::string name) : Name(name), Signed(false), signGrade(150), executeGrade(150)
{

}

Form::Form(std::string name, int requiredsG, int requiredexG) : Name(name), Signed(false), signGrade(requiredsG), executeGrade(requiredexG)
{
	if (requiredsG < 1 || requiredexG < 1)
		throw GradeTooHighException();
	else if (requiredsG > 150 || requiredexG > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy) : Name(copy.getName()), signGrade(copy.getSignGrade()), executeGrade(copy.getExecuteGrade())
{
	*this = copy;
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		Signed = copy.Signed;
	return *this;
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return  Name;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecuteGrade() const
{
	return executeGrade;
}

std::string Form::getSigned() const
{
	if (Signed == true)
		return "true";
	return "false";
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->Signed = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form -> Out Of Range : Too High Grade!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form -> Out Of Range : Too Low Grade!");
}

std::ostream& operator<<(std::ostream &os, const Form& form)
{
	os << form.getName() << ", required grade to sign " << form.getSignGrade() << ", required grade to execute " << form.getExecuteGrade() << ", is signed " << form.getSigned() << std::endl;
	return os;
}
