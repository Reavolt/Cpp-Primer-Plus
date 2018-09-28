//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int light_years(double);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter the number of light years: ";
	
	double lightyears = 0;
	std::cin >> lightyears;

	std::cout << lightyears << " light year = " << light_years(lightyears) << " astronomical units" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
int light_years(double light_years)
{
	return light_years * 63240;
}
//-------------------------------------------------------------------------------------------------
