#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string Target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		void Executor() const;
};