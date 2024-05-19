#include "Base.hpp"
#include <cstdlib>

Base::~Base() {}

Base * Base::generate(void)
{
	srand(time(0));
	int random = rand() % 3;
	switch (random)
	{
		case 2:
			std::cout << "Instantiated Class: A" << "\n";F
			return new A();
		case 1:
			std::cout << "Instantiated Class: B" << "\n";
			return new B();
		case 0:
			std::cout << "Instantiated Class: C" << "\n";
			return new C();
	}
		std::cout << "ERROR: Couldnt be instantiated any Class!" << std::endl;
		return NULL;
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The actual type of the object is (*): A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The actual type of the object is (*): B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The actual type of the object is (*): C" << std::endl;
	else
		std::cout << "ERROR: Types dont match!" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		Base a = dynamic_cast<A &>(p);
		std::cout << "The actual type of the object is (&): A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {}

	try
	{
		Base b = dynamic_cast<B &>(p);
		std::cout << "The actual type of the object is (&): B" << std::endl;
		(void)b;
	}
	catch (std::exception &e) {}

	try
	{
		Base c = dynamic_cast<C &>(p);
		std::cout << "The actual type of the object is (&): C" << std::endl;
		(void)c;
	}
	catch (std::exception &e) {}
}