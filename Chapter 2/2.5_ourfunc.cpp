//ourfunc.cpp -- определение собственной функции 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath> // Библиотека математических функций

using namespace std;

//-------------------------------------------------------------------------------------------------
void simon(int);
//-------------------------------------------------------------------------------------------------
int main()
{
	simon(3);
	cout << "Pick an integer: ";
	int count;
	cin >> count;
	simon(count);
	cout << "Done!" << endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void simon(int n) {
	cout << "Simon says touch your toes " << n << " times." << endl;
	//return не требуется, так как функция ничего не возвращает.
}
//-------------------------------------------------------------------------------------------------
/*
Simon says touch your toes 3 times.
Pick an integer: 512
Simon says touch your toes 512 times.
Done!
*/
