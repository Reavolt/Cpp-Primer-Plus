//not.cpp -- использование логической операции "НЕ" 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
bool is_int(double x);
//-------------------------------------------------------------------------------------------------
int main() 
{
	double num;

	cout << "Yo, dude! Enter an integer value: "; // запрос на ввод целочисленного значения 
	cin >> num;
	while (!is_int(num))    // продолжать, пока num не является int 
	{
		cout << "Out of range -- please try again: "; // выход за пределы диапазона 
		cin >> num;
	}
	int val = int(num);    // приведение типа
	cout << "You've entered the integer " << val << "\nBye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
bool is_int(double x)
{
	if (x <= INT_MAX && x >= INT_MIN)   // проверка предельных значений climits 
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
/*
Yo, dude! Enter an integer value: 6234128679
Out of range -- please try again: -8000222333
Out of range -- please try again: 99999
You've entered the integer 99999
Bye
*/