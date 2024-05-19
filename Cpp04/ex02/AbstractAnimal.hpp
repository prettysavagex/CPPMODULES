#pragma once
#include <iostream>

#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define PINK		"\033[38;5;206m"
#define PURPLE		"\033[38;5;141m"

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& copy);
		virtual ~AAnimal();

		void setType(std::string);
		std::string getType()const;
		
		virtual void makeSound() const = 0;
};