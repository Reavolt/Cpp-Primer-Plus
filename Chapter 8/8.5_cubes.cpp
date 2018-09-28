//cubes.срр -- обычные и ссылочные аргументы 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
double cube(double a);
double refcube(double &ra);
//-------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Rus");

	double x = 3.0;
	cout << cube(x);
	cout << " = cube of " << x << endl; // вывод значения в кубе 
	cout << refcube(x);
	cout << " = cube of " << x << endl; // вывод значения в кубе 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
double cube(double a)
{
	a *= a * a;
	return a;
}
//-------------------------------------------------------------------------------------------------
double refcube(double &ra)
{
	ra *= ra * ra;
	return ra;
}
//-------------------------------------------------------------------------------------------------
/*
27 = cube of 3
27 = cube of 27
*/