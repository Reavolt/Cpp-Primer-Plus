//lotto.срр -- вероятность выигрыша 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------------------------
// Примечание: некоторые реализации требуют применения double вместо long double 
long double probability(unsigned numbers, unsigned picks);
//------------------------------------------------------------------------------------------------
int main() 
{
	double total, choices;
	// Ввод общего количества номеров и количества номеров, которые нужно угадать 
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices); // вычисление и вывод шансов 
		cout << " of winning. \n";
		cout << "Next two numbers (q to quit) : ";
		// Ввод следующих двух чисел (q для завершения) 
	}
	cout << "bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
// Следующая функция вычисляет вероятность правильного 
// угадывания picks чисел из numbers возможных 
long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0; // несколько локальных переменных 
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; n--, p--)
		 result = result * n / p;
	return result;
}
//------------------------------------------------------------------------------------------------
/*
Enter the total number of choices on the game card and
the number of picks allowed:
49 6
You have one chance in 1.39838e+07 of winning.
Next two numbers (q to quit) : 51 6
You have one chance in 1.80095e+07 of winning.
Next two numbers (q to quit) : 38 6
You have one chance in 2.76068e+06 of winning.
Next two numbers (q to quit) : q
bye
*/