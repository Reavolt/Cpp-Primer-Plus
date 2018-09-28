//typecast.cpp -- изменение типа при инициализации
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int auks, bats, coots;

	//Следующий оператор суммирует значение типа double
	//а полученный результат преобразуется в тип int
	auks = 19.99 + 11.99;

	//Эти операторы суммируют целочисленные значения
	bats = (int) 19.99 + (int) 11.99; //Cтарый синтаксис С
	coots = int(19.99) + int(11.99); //Новый синтаксис С++
	cout << "auks = " << auks << ", bats = " << bats;
	cout << ", coots = " << coots << endl;

	char ch = 'Z';
	cout << "The code for " << ch << " is ";
	cout << int(ch) << endl;
	cout << "Yes, the code is ";
	cout << static_cast<int> (ch) << endl; //Приведение типа 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
auks = 31, bats = 30, coots = 30
The code for Z is 90
Yes, the code is 90
*/