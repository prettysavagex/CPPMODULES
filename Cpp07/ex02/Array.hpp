#pragma once
#include <iostream>

template<typename T>

class Array
{
	private:
		T* array;
		unsigned int extent;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		~Array();
		T& operator[](unsigned int indx) const;
		unsigned int size() const;

		class TransgressException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"