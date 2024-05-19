#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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