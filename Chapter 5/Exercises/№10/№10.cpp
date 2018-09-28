//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::string dot = ".";
	std::string star = "*";

	std::cout << "Enter the number of rows: ";
	size_t count = 0;
	std::cin >> count;

	for (size_t i = 0; i <= count; i++)
	{
		for (size_t j = 0; j < count - i; j++)
		{
			std::cout << dot;
		}
		for (size_t j = 0; j < i; j++)
		{
			std::cout << star;
		}
		std::cout << std::endl;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------