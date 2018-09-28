//manip.cpp -- использование манипуляторов формата 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	// Вывод приглашения к вводу целого числа 
	cout << "Enter an integer: ";
	int n;
	cin >> n;

	cout << "n     n*n\n";
	cout << n << "     " << n * n << " (decimal)\n";
	// Установка шестнадцатеричного режима вывода 
	cout << hex;
	cout << n << "     ";
	cout << n * n << " (hexadecimal)\n";

	// Установка восьмеричного режима 
	cout << oct << n << "     " << n * n << " (octal)\n";

	// Альтернативный способ вызова манипулятора 
	dec(cout);
	cout << n << "     " << n * n << " (decimal)\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter an integer: 13
n     n*n
13     169 (decimal)
d     a9 (hexadecimal)
15     251 (octal)
13     169 (decimal)
Для продолжения нажмите любую клавишу . . .
*/