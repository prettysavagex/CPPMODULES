#include "Span.hpp"
#include <exception>
#include <algorithm>

Span::Span() {}

Span::Span(unsigned int N) : capacity(N) {}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span& Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->capacity = copy.capacity;
		this->arr = copy.arr;
	}
	return *this;
}

Span::~Span() {}

void Span::add(iter begin, iter end)
{
	iter i;
	for (i = begin; i != end; i++)
		this->addNumber(*i);
}

void Span::addNumber(int nbr)
{
	if (arr.size() < capacity)
		arr.push_back(nbr);
	else
		throw std::runtime_error("The Number Couldnt Be Added!");
}

int Span::shortestSpan()
{
	if (arr.size() <= 1)
		throw std::runtime_error("Unsufficient numbers to find span!");
	std::sort(arr.begin(), arr.end());
	int minExtent = arr[1] - arr[0];
	for (size_t i = 2; i < arr.size(); i++)
	{
		int extent = arr[i] - arr[i - 1];
		if (extent < minExtent)
			minExtent = extent;
	}
	return minExtent;
}

int Span::longestSpan()
{
	if (arr.size() <= 1)
		throw std::runtime_error("Insufficient numbers to find span!");
	int max = *std::max_element(arr.begin(), arr.end());
	int min = *std::min_element(arr.begin(), arr.end());
	return max - min;
}