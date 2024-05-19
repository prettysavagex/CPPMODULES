#pragma once
#include <iostream>
//#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PINK	"\033[38;5;206m"
#define PURPLE	"\033[38;5;141m"
#define BROWN	"\033[38;5;130m"

#define LRED     "\033[91m" 
#define LGREEN   "\033[92m"
#define LYELLOW  "\033[93m" 
#define LBLUE    "\033[94m" 
#define LPURPLE	"\033[38;5;189m" 

class ClapTrap
{
	private:
		std::string name;
		int hitPoint;
		int energyPoint;
		int attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int checkStatus();
};