#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << YELLOW << std::endl << "xxxxxxxxxxxxxxxxx NORMAL ONES xxxxxxxxxxxxxxxxx" << RESET << std::endl << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\n" << BLUE << "Type: " << j->getType() << RESET << std::endl;
	std::cout << PINK << "Type: " << i->getType() << RESET << std::endl;
	std::cout << GREEN << "Type: " << meta->getType() << RESET << std::endl << "\n";

	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	std::cout << "\n";
	
	delete meta;
    delete j;
    delete i;

	std::cout << RED << std::endl << "xxxxxxxxxxxxxxxxx WRONG ONES xxxxxxxxxxxxxxxxx" << RESET << std::endl << std::endl;

	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();

		std::cout << "\n" << PURPLE << "Type: " << cat->getType() << RESET << std::endl << "\n";
		cat->makeSound();
		meta->makeSound();
		std::cout << "\n";

		delete cat;
		delete meta;
	}

	return 0;
}