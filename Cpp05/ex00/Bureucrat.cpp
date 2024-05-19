#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name("Undefined"), Grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name) : Name(name), Grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int Grade) : Name(name)
{
	this->Grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : Name(copy.getName())
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		this->Grade = copy.Grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->Name;
}

int Bureaucrat::getGrade() const
{
	return this->Grade;
}

Bureaucrat::~Bureaucrat()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Out Of Range : Too High Grade!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Out Of Range: Too Low Grade!";
}

void Bureaucrat::increaser()
{
	if (this->Grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	this->Grade--;
}

void Bureaucrat::decreaser()
{
	if (this->Grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->Grade++;
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return output;
}
