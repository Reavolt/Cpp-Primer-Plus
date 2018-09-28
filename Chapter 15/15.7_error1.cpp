//error1.срр -- использование функции abort() 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstdlib> 

//-------------------------------------------------------------------------------------------------
double hmean(double a, double b);
//-------------------------------------------------------------------------------------------------
int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";	// запрос на ввод двух чисел 
	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;	// вывод среднего гармонического 
		std::cout << "Enter next set of numbers <q to quit>: ";
		// запрос следующих двух чисел 
	}
	std::cout << "Bye!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "untenable arguments to hmean()\n";	// неверные аргументы для hmean() 
		std::abort();
	}
	return 2.0 * a * b / (a + b);
}
//-------------------------------------------------------------------------------------------------
/*
Enter two numbers: 3 б
Harmonic mean of 3 and 6 is 4
Enter next set of numbers <q to quit>: 10 -10
untenable arguments to hmean()
abnormal program termination
*/