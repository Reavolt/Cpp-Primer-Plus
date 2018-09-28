//ilist.cpp --- Для использование initializer_list (средство С++11) 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <initializer_list>

//-------------------------------------------------------------------------------------------------
double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double> & ril);
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;

	cout << "List 1: sum = " << sum({ 2,3,4 })
		<< ", ave = " << average({ 2,3,4 }) << '\n';	// список 1, его сумма и среднее 
	std::initializer_list<double> dl = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	cout << "List 2: sum = " << sum(dl)
		<< ", ave = " << average(dl) << '\n';	// список 2, его сумма и среднее 
	dl = { 16.0, 25.0, 36.0, 40.0, 64.0 };
	cout << "List 3: sum = " << sum(dl)
		<< ", ave = " << average(dl) << '\n';	// список 3, его сумма и среднее 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
double sum(std::initializer_list<double> il)
{
	double tot = 0;
	for (auto p = il.begin(); p != il.end(); p++)
		tot += *p;
	return tot;
}
//-------------------------------------------------------------------------------------------------
double average(const std::initializer_list<double> & ril)
{
	double tot = 0;
	int n = ril.size();
	double ave = 0.0;

	if (n > 0)
	{
		for (auto p = ril.begin(); p != ril.end(); p++)
			tot += *p;
		ave = tot / n;
	}
	return ave;
}
//-------------------------------------------------------------------------------------------------
/*
List 1: sum = 9, ave = 3
List 2: sum = 16.5, ave = 3.3
List 3: sum = 181, ave = 36.2
Для продолжени¤ нажмите любую клавишу . . .
*/