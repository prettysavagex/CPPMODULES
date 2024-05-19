#pragma once
#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		~Cat();

		void makeSound() const;
		Brain *brainin() const;

	private:
		Brain* brain;
};