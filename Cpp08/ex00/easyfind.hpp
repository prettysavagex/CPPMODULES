#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

class FailedToFindNumber : public std::exception
{
	const char* what() const throw()
	{
		return ("Failed To Find The Number!");
	}
};

template <typename T>
int easyfind(T t, int f)
{
	typename T::iterator iter;

	iter = std::find(t.begin(), t.end(), f);

	if (iter == t.end())
		throw FailedToFindNumber();

	int j = 0;
	for (typename T::iterator i = t.begin(); i != t.end(); ++i, j++)
	{
		if (*i == f)
			return j;
	}
	return -1;
}