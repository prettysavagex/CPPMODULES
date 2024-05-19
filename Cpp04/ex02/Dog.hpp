#pragma once
#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		~Dog();

		void makeSound() const;
		Brain *brainin() const;

	private:
		Brain *brain;
};