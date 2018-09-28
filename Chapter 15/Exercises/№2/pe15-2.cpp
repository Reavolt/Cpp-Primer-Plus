//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <cmath> // или math.h, пользователям UNIX может потребоваться флаг -lm 
#include <iostream>
#include <stdexcept>

//-------------------------------------------------------------------------------------------------
// Прототипы функций 
double hmean(double a, double b);
double gmean(double a, double b);
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	std::cout << "Enter two numbers: ";	// запрос на ввод двух чисел 
	while (std::cin >> x >> y)
	{
		try 
		{// начало блока try 
			z = hmean(x, y);
			std::cout << "Harmonic mean of " << x << " and " << y;
			std::cout << " is " << z << std::endl;					// вывод среднего гармонического 
			std::cout << "Geometric mean of " << x << " and " << y;
			std::cout << " is " << gmean(x, y) << std::endl;		// вывод среднего геометрического 
			std::cout << "Enter next set of numbers <q to quit>: ";	// ввод следующей пары чисел
			std::cout << std::endl;				
		}// конец блока try 
		catch (std::invalid_argument & ia) 
		{// начало блока catch 
			std::cout << ia.what() << std::endl;
			std::cout << "Try again.\n";							// необходимо повторить попытку 
			continue;
		}// конец блока catch 
		catch (std::domain_error & de)
		{// начало блока catch 
			std::cout << de.what() << std::endl;
			std::cout << "Sorry, you don't get to play any more.\n";
			break;
		}// конец блока catch 
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
		throw std::invalid_argument("Error in hmean() : values are equal");
	}
	return 2.0 * a * b / (a + b);
}
//-------------------------------------------------------------------------------------------------
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw std::domain_error("Error in gmean(): both values must be positive");
	}
	return std::sqrt(a * b);
}
//-------------------------------------------------------------------------------------------------