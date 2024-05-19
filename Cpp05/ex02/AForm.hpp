#pragma once
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		std::string const Name;
		bool Signed;
		int const signGrade;
		int const executeGrade;

	public:
		AForm();
		AForm(std::string name);
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();
		std::string getName()const;
		int getSignGrade()const;
		int getExecuteGrade()const;
		std::string getSigned()const;
		void beSigned(Bureaucrat& bureaucrat);
		void execute(const Bureaucrat& executor) const;
		virtual void Executor() const = 0;
		class GradeTooHighException: public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			const char* what() const throw();
		};
		class FormNotSignedException: public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);