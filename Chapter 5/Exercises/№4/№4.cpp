//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	double dafna = 100;
	double kleo = 100;
	int age = 0;

	do
	{
		dafna += 0.10 * 100;
		std::cout << "Balance Dafna: " << dafna << std::endl;

		kleo += 0.05 * kleo;
		std::cout << "Balance Kleo: " << kleo << std::endl;

		age++;
		std::cout << "Years passed: " << age << std::endl;

		std::cout << std::endl;
	}
	while (kleo <= dafna);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------