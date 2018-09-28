//floatnum.cpp -- типы с плавающей точкой
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	//Аргументы ios_base::fixed, ios_base::floatfield - это константы	
	//cout.setf() Устанавливает формат вывода с плавающей точкой 
	cout.setf(ios_base::fixed, ios_base::floatfield); // Фиксирвоанная точка
	float tub = 10.0 / 3.0;							  // подходит для 6 разрядов
	double mint = 10.0 / 3.0;						  // подходит для 15 разрядов
	const float million = 1.0e6;
	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ", \nand ten million tubs = ";
	cout << 10 * million * tub << endl;
	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
tub = 3.333333, a million tubs = 3333333.250000,
and ten million tubs = 33333332.000000
mint = 3.333333 and a million mints = 3333333.333333
*/