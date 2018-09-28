//funtemp.cpp -- использование шаблона функции 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// Прототип шаблона функции 
template <typename T> // или class Т 
void Swap(T & a, T & b);
//-------------------------------------------------------------------------------------------------
int main()
{
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << "\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j); // генерирует void Swap(int &, int &) 
	cout << "Now i, j = " << i << ", " << j << " .\n";
	double x = 24.5;
	double y = 81.7;
	cout << "x, у = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x, y); // генерирует void Swap(double &, double &) 
	cout << "Now x, y=" << x << ", " << y << ".\n"; 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
// Определение шаблона функции 
template <typename T> // или class T 
void Swap(T & a, T & b)
{
	T temp; // temp - переменная типа Т 
	temp = a;
	a = b;
	b = temp;
}
//-------------------------------------------------------------------------------------------------
/*
i, j = 10, 20
Using compiler-generated int swapper:
Now i, j = 20, 10 .
x, у = 24.5, 81.7.
Using compiler-generated double swapper:
Now x, y=81.7, 24.5.
*/