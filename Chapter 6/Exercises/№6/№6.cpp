//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//------------------------------------------------------------------------------------------------
struct ZVL 
{
	string name;
	double donate;
};
//------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter the number of patrons: ";
	unsigned int mecenat_count = 0;
	(std::cin >> mecenat_count).get();

	ZVL* zvl = new ZVL[mecenat_count];

	for (size_t i = 0; i < mecenat_count; i++) 
	{
		std::cout << "Enter the name of the patron: ";
		getline(std::cin, zvl[i].name);
		std::cout << "Enter amount of donation: ";
		(std::cin >> zvl[i].donate).get();
	}

	int grand_patrons_count = 0;
	std::cout << "Grand Patrons: " << std::endl;

	for (size_t i = 0; i < mecenat_count; i++) 
	{
		if (zvl[i].donate >= 10000) 
		{
			std::cout << zvl[i].name << " = " << zvl[i].donate << "$" << std::endl;
			grand_patrons_count++;
		}
	}
	if (grand_patrons_count == 0)
	{
		std::cout << "NONE!" << std::endl;
	}

	int patrons_count = 0;
	std::cout << "Patrons: " << std::endl;

	for (size_t i = 0; i < mecenat_count; i++) 
	{
		if (zvl[i].donate < 10000)
		{
			std::cout << zvl[i].name << " = " << zvl[i].donate << "$" << std::endl;
			patrons_count++;
		}
	}

	if (patrons_count == 0)
	{
		std::cout << "NONE!" << std::endl;
	}

	delete[] zvl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------