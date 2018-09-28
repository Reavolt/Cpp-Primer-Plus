//protos.ерр -- использование прототипов и вызовы функций 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;
//------------------------------------------------------------------------------------------------
void cheers(int); // прототип: нет значения возврата 
double cube(double x); // прототип: возвращает double 
//------------------------------------------------------------------------------------------------
int main() 
{
	cheers(5); // вызов функции 
	cout << "Give me a number: ";
	double side;
	cin >> side;
	double volume = cube(side); // вызов функции 
	cout << "A " << side << "-foot cube has a volume of ";
	cout << volume << " cubic feet.\n";
	cheers(cube(2)); // защита прототипа в действии 

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
void cheers(int n)
{
	for (int i = 0; i < n; i++)
		cout << "Cheers! ";
	cout << endl;
}
//------------------------------------------------------------------------------------------------
double cube(double x)
{
	return x * x * x;
}
//------------------------------------------------------------------------------------------------
/*
Cheers! Cheers! Cheers! Cheers! Cheers!
Give me a number: 5
A 5-foot cube has a volume of 125 cubic feet.
Cheers! Cheers! Cheers! Cheers! Cheers! Cheers! Cheers! Cheers!
*/