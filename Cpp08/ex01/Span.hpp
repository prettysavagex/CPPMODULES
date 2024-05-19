#pragma once
#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int capacity;
		std::vector<int> arr;
		typedef std::vector<int>::iterator iter;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span& operator=(const Span &copy);
		~Span();
		void addNumber(int nbr);
		void add(iter begin, iter end);
		int shortestSpan();
		int longestSpan();
};