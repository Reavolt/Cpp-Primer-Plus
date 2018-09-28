//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------------------------------------------------
struct ZVL 
{
	std::string name;
	double donate;
};
//------------------------------------------------------------------------------------------------
int main()
{
	std::ifstream fileinp;
	fileinp.open("№9.txt");

	if (!fileinp.is_open()) //если файл не открылся - завершение программы
	{
		std::cout << "File not found." << std::endl;
		std::cout << "The program will be closed." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Number of Patrons: ";
	
	unsigned int mecenat_count;
	(fileinp >> mecenat_count).get();

	std::cout << mecenat_count << std::endl;
	ZVL* zvl = new ZVL[mecenat_count];

	for (size_t i = 0; i < mecenat_count, fileinp.good(); i++)
	{
		std::cout << "The name of the patron has been entered: ";
		getline(fileinp, zvl[i].name);
		std::cout << zvl[i].name << std::endl;
		std::cout << "Donation amount entered: ";
		(fileinp >> zvl[i].donate).get();
		std::cout << zvl[i].donate << std::endl;
		std::cout << std::endl;
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
	fileinp.close();

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------