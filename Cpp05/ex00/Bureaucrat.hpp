#pragma once
#include <iostream>
#include <string>

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

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& one);