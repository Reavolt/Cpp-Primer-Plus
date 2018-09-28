//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <iomanip>

//--------------------------------------------------------------------------------------------------
template <typename T, typename... Args>
long double sum_values(const T & value, const Args&... args);
//--------------------------------------------------------------------------------------------------
int main()
{
	std::cout << sum_values(5, 5, 5) << std::endl;
	std::cout << std::setprecision(10) << sum_values(20.0, 1.0, 8.6578787879, 1) << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//--------------------------------------------------------------------------------------------------
long double sum_values()
{
	return 0.0;
}
//--------------------------------------------------------------------------------------------------
template <typename T, typename... Args>
long double sum_values(const T & value, const Args&... args)
{
	long double sum = 0;
	sum = value + sum_values(args...);
	return sum;
}
//--------------------------------------------------------------------------------------------------