#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;

	vec.push_back(12);
	vec.push_back(56);
	vec.push_back(7);
	vec.push_back(19);
	vec.push_back(34);
	
	try
	{
		int res = easyfind(vec, 56);

		std::cout << "Found: " << vec[res] << " at index: " << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	/* for (int i = 0; i < (int)vec.size(); i++)
		std::cout << vec[i] << std::endl; */
}