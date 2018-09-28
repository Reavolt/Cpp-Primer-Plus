//fun_ptr.cpp -- указатели на функции
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------------------------
double betsy(int);
double pam(int);
// Второй аргумент — указатель на функцию double, 
// которая' принимает аргумент типа int 
void estimate(int lines, double(*pf) (int));
//------------------------------------------------------------------------------------------------
int main() 
{
	int code;
	cout << "How many lines of code do you need? "; // ввод количества строк кода 
	cin >> code;
	cout << "Here's Betsy's estimate:\n"; // вывод первой оценки 
	estimate(code, betsy);
	cout << "Here's Pam's estimate:\n"; // вывод второй оценки 
	estimate(code, pam);

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
double betsy(int Ins) 
{
	return 0.05 * Ins;
}
//------------------------------------------------------------------------------------------------
double pam(int Ins) 
{
	return 0.03 * Ins + 0.0004 * Ins * Ins;
}
//------------------------------------------------------------------------------------------------
void estimate(int lines, double(*pf)(int))
{
	using namespace std;
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n"; // вывод затрат времени 
}
//------------------------------------------------------------------------------------------------
/*
How many lines of code do you need? 30
Here's Betsy's estimate:
30 lines will take 1.5 hour(s)
Here's Pam's estimate:
30 lines will take 1.26 hour(s)

How many lines of code do you need? 100
Here's Betsy's estimate:
100 lines will take 5 hour(s)
Here's Pam's estimate:
100 lines will take 7 hour(s)
*/