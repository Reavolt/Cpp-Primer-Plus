//еrrоrЗ.срр — использование исключения 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cfloat>  // (или float.h) для DBL_MAX 

//-------------------------------------------------------------------------------------------------
double hmean(double a, double b);
//-------------------------------------------------------------------------------------------------
int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";	// запрос на ввод двух чисел 
	while (std::cin >> x >> y)
	{
		try {                  // начало блока try 
			z = hmean(x, y);
		}                       // конец блока try 
		catch (const char * s)  // начало обработчика исключений 
		{
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of numbers: ";	//запрос на ввод новой пары чисел 
			continue;
		}                     // конец обработчика исключений 
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;					// вывод среднего гармонического 
		std::cout << "Enter next set of numbers <q to quit>: ";		// запрос следующих двух чисел
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
		throw "bad hmean() arguments: a = -b not allowed";
	return 2.0 * a * b / (a + b);
}
//-------------------------------------------------------------------------------------------------
/*
Enter two numbers: 3 6
Harmonic mean of 3 and 6 is 4
Enter next set of numbers <q to quit>: 10 -10
bad hmean() arguments: a = -b not allowed
Enter a new pair of numbers: 1 19
Harmonic mean of 1 and 19 is 1.9
Enter next set of numbers <q to quit>: q
Bye!
Для продолжения нажмите любую клавишу . . .
*/