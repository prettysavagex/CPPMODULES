#include "Base.hpp"

int main()
{
	Base *ins;
	Base base;

	ins = base.generate();
	base.identify(ins);
	base.identify(*ins);

	delete ins;
	return 0;
}