#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string Target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		void Executor() const;
};