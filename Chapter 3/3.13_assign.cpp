//assign.cpp -- изменение типа при инициализации
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	cout.setf(ios::fixed, ios::floatfield); //формат с фиксированной точкой
	float tree = 3; //Инт приобразован в float
	int guess = 3.9832; //float приобразован в int
	int debt = 7.2E12; //Результат не преобразован

	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
tree = 3.000000 
guess = 3
debt = 1634811904
*/