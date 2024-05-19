#pragma once
#include <iostream>

#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define PINK		"\033[38;5;206m"
#define PURPLE		"\033[38;5;141m"

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& copy);
        virtual ~WrongAnimal();

        void setType(std::string name);
        std::string getType() const;

        void makeSound() const;
};