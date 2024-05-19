#pragma once
#include <iostream>

template<typename T>

void iter(T *addr, int length, void(*function)(T const &))
{
	for(int i = 0; i < length; i++)
		function(addr[i]);
}