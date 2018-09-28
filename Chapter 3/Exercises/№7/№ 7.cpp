//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	const float mile_km = 1.609;
	const float gl_litr = 3.875;

	std::cout << "Enter the number of liters per 100 kilometers: ";
	float litr_100 = 0.0;
	std::cin >> litr_100;

	float km = 100 / litr_100;
	float mile = km / mile_km;
	float mile_gl = (mile * gl_litr);
	
	std::cout << "Answer " << mile_gl << " Miles per gallon" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
