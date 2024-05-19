#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\n" << BLUE << "Type: " << j->getType() << RESET << std::endl;
    	std::cout << PINK << "Type: " << i->getType() << RESET << std::endl << "\n";
    	j->makeSound();
    	i->makeSound();
		std::cout << "\n";

		delete j;
		delete i;
	}

	Cat obj;
	std::cout << "\n" << YELLOW << *(obj.brainin()->ideas) << RESET << std::endl << std::endl;

	{
		int total = 4;
		Animal* animal[total];

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