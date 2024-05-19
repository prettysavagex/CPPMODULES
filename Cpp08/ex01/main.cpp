#include "Span.hpp"
#include <cstdlib>

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout <<  "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		std::vector<int> a(10000);

		for (int i = 0; i < 10000; ++i)
			a[i] = i;

		try
		{
			
			Span s(10000);
			s.add(a.begin(), a.end());
			std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
			std::cout << "Longest span : " << s.longestSpan() << std::endl;
		}
		
		catch (std::exception& e)
		{
			std::cerr << "EXCEPTION: " << e.what() << std::endl;
		}

		return 0;
	}
}
