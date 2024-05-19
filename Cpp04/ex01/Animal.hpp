#pragma once
#include <iostream>

#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define PINK		"\033[38;5;206m"
#define PURPLE		"\033[38;5;141m"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();

		void setType(std::string);
		std::string getType()const;
		
		virtual void makeSound() const;
};