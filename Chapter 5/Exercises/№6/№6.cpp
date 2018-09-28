//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::string months[12] =
	{
		"January","February","March",
		"April","May","June",
		"July","August","September",
		"October" ,"November" ,"December"
	};

	int value[3][12] = { 0 };
	int total_book = 0;

	for (size_t i = 0; i < 3; i++)
	{

		int total_book_year = 0;
		std::cout << i + 1 << " year" << std::endl;

		for (size_t j = 0; j < 12; j++)
		{
			std::cout << "Enter the number of books sold for: " << months[j] + " : ";
			std::cin >> value[i][j];
			total_book_year += value[i][j];
		}
		std::cout << "Total books sold year: " << total_book_year << std::endl;
		total_book += total_book_year;
	}
	std::cout << "Total books sold: " << total_book << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------