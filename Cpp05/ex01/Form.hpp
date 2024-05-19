#pragma once
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		std::string const Name;
		bool Signed;
		int const signGrade;
		int const executeGrade;

	public:
		Form();
		Form(std::string name);
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();
		std::string getName()const;
		int getSignGrade()const;
		int getExecuteGrade()const;
		std::string getSigned()const;
		void beSigned(Bureaucrat& bureaucrat);
		class GradeTooHighException: public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);