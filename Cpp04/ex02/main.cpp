#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << "\n" << BLUE << "Type: " << j->getType() << RESET << std::endl;
    	std::cout << PINK << "Type: " << i->getType() << RESET << std::endl << "\n";
    	j->makeSound();
    	i->makeSound();
		std::cout << "\n";

		delete j;
		delete i;
	}

	{
		int total = 4;
		AAnimal* animal[total];

		for(int i = 0; i < total/2; i++)
			animal[i] = new Cat();

		for(int i = total/2; i < total; i++)
			animal[i] = new Dog();

		for(int i = 0; i < total; i++)
			animal[i]->makeSound();

		for(int i = 0; i < total; i++)
			delete animal[i];
	}

	return 0;
}