#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string Target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		void Executor() const;
};