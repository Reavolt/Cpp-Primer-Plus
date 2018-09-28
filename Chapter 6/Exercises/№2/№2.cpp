//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cctype>

//------------------------------------------------------------------------------------------------
const int array_size = 10;
//------------------------------------------------------------------------------------------------
int main()
{
	double fond[array_size] = { 0.0 };
	double summ = 0;
	int count = 0;

	std::cout << "Enter 10 numbers of donations: " << std::endl;

	for (size_t i = 0; i < array_size; i++) 
	{
		if (!isdigit(fond[i])) 
		{
			std::cin >> fond[i];
			summ += fond[i];
		}
		else
		{
			return 0;
		}
	}

	double avg = summ / array_size;
	std::cout << "The average value of all donations: " << avg << std::endl;

	for (size_t i = 0; i < array_size; i++)
	{
		if (fond[i] > avg)
		{
			count++;
		}
	}
	std::cout << "Donations exceeding the average: " << count << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------