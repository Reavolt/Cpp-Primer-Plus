//hexoct2.cpp -- отображает значения в шестнадцатеричном и восьмеричном форматах 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "Monsieur cuts a striking figure!\n";
	cout << "Chest = " << chest << " (decimal for 42)\n";
	cout << hex; //Манипулятор для изменения основания системы счисления 
	cout << "Waist = " << waist << " (hexadecimal for 42)\n";
	cout << oct; //Манипулятор для изменения основания системы счисления 
	cout << "inseam = " << inseam << " (octal for 42)\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Monsieur cuts a striking figure!
chest = 42 (decimal for 42)
waist = 2a (hexadecimal for 42)
inseam = 52 (octal for 42)
*/