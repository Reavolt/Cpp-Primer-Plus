//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	unsigned long long int world_population = 0;
	std::cout << "Enter the world's population: ___________\b\b\b\b\b\b\b\b\b\b\b";
	std::cin >> world_population;

	unsigned long long int population_country = 0;
	std::cout << "Enter the population of the country: ___________\b\b\b\b\b\b\b\b\b\b\b";
	std::cin >> population_country;

	double Result = double(population_country) / world_population * 100;
	std::cout << "The population of the country is " << Result << "% of the world population." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------