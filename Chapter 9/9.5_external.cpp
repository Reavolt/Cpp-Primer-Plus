//external.cрр -- внешние переменные 
//Компилировать вместе с support.cрр 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

// Внешняя переменная 
double warming = 0.3; // переменная warming определена 
//-------------------------------------------------------------------------------------------------
// Прототипы функций 
void update(double dt);
void local();
//-------------------------------------------------------------------------------------------------
int main() // использует глобальную переменную 
{
	cout << "Global warming is " << warming << " degrees. \n";
	update(0.1); // вызов функции, изменяющей warming 
	cout << "Global warming is " << warming << " degrees. \n";
	local(); // вызов функции с локальной переменной warming 
	cout << "Global warming is " << warming << " degrees. \n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------