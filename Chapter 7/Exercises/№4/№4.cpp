//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//----------------------------------------------------------------------------------------------------
long double probability(unsigned numbers, unsigned picks);
//----------------------------------------------------------------------------------------------------
int main()
{
	double total1 = 0;
	double total2 = 0; 
	double choices = 0;
	
	// Ввод общего количества номеров и количества номеров, которые нужно угадать 
	std::cout << "Enter the total number of choices on the game card,\n";
	std::cout << "the number of picks allowed \n";
	std::cout << "and the total number of choices on the second game field \n";

	while ((std::cin >> total1 >> choices >> total2) && choices <= total1)
	{
		std::cout << "You have one chance in ";
		std::cout << probability(total1, choices) * probability(total2, 1); // вычисление и вывод шансов
		std::cout << std::endl;
		std::cout << " of winning. \n";
		std::cout << "Next two numbers (q to quit) : ";
		// Ввод следующих двух чисел (q для завершения) 
	}
	std::cout << "bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//----------------------------------------------------------------------------------------------------
long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n = 0;
	unsigned p = 0;
	for (n = numbers, p = picks; p > 0; n--, p--)
	{
		result = result * n / p;
	}
	return result;
}
//----------------------------------------------------------------------------------------------------