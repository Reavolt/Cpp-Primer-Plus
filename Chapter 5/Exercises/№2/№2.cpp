//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <array>

//-------------------------------------------------------------------------------------------------
const int arr_size = 101;
//-------------------------------------------------------------------------------------------------
int main()
{
	std::array<long double, arr_size> factorials;

	factorials[1] = factorials[0] = 1LL;

	for (int i = 2; i < arr_size; i++)
	{
		factorials[i] = i * factorials[i - 1];
	}

	for (int i = 0; i < arr_size; i++)
	{
		std::cout << i << " ! = " << factorials[i] << std::endl;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------