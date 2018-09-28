//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <initializer_list>

//--------------------------------------------------------------------------------------------------
template <typename T>
T average_list(std::initializer_list<T> il)
{
	T sum = 0;
	for (auto pi = il.begin(); pi != il.end(); pi++)
	{
		sum += *pi;
	}
	T average = sum / il.size();
	return average;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	auto q = average_list({ 15.4,10.7,9.0 });
	std::cout << q << std::endl;

	std::cout << average_list({ 20,30,19,17,45,38 }) << std::endl;

	auto ad = average_list<double>({ 'A', 70,65.33 });
	std::cout << ad << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------