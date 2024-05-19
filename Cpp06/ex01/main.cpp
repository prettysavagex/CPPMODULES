#include "serializer.hpp"

int main()
{
	Serializer serializer;
	Data* obj = new Data;
	uintptr_t raw;
	Data *ptr;

	std::cout << "The address of the Data object: " << obj << std::endl;
	raw = serializer.serialize(obj);
	std::cout << "The address converted into unsigned integer value: " << raw << std::endl;
	ptr = serializer.deserialize(raw);
	std::cout << "The unsigned int value converted into a pointer to Data: " << ptr << std::endl;
	
	delete obj;
	return 0;
}