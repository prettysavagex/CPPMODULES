#include "Array.hpp"
#pragma once

template<typename T>
Array<T>::Array() : array(NULL), extent(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), extent(n)
{
	for (unsigned int i = 0; i < extent; i++) 
	{
		array[i] = 0;
	}
}

template<typename T>
Array<T>::Array(const Array& copy) : array(new T[copy.extent]), extent(copy.size())
{
	for (unsigned int i = 0; i < this->extent; i++)
		this->array[i] = copy.array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		if (array)
			delete[] array;
		this->array = new T[copy.size()];
		this->extent = copy.size();
		for (unsigned int i = 0; i < extent; i++)
			this->array[i] = copy.array[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	if (array)
		delete[] array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->extent);
}

template<typename T>
T& Array<T>::operator[](unsigned int indx) const
{
	if (indx >= this->extent)
		throw (TransgressException());
	return (this->array[indx]);
}

template<typename T>
const char* Array<T>::TransgressException::what() const throw()
{
	return ("The index number is not within the range!");
}