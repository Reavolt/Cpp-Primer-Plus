//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	const int km_100 = 100;

	int kilometers = 0;
	std::cout << "Enter the distance in kilometers: ";
	std::cin >> kilometers;

	int kmh_gasoline = 0;
	std::cout << "Enter the amount of spent gasoline: ";
	std::cin >> kmh_gasoline;

	double Result = double(kmh_gasoline) / (kilometers / km_100);
	std::cout << "Fuel consumption: " << Result << "/100km" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------