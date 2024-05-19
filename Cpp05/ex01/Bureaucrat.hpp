#pragma once
#include "Form.hpp"
#define RED	"\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Bureaucrat
{
	private:
		std::string const Name;
		int Grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void increaser();
		void decreaser();
		void signForm(Form& form);
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);