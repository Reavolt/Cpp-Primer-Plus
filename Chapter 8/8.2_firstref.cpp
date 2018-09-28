//firstref.cpp -- определение и использование ссылки 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	int rats = 101;
	int & rodents = rats; // rodents является ссылкой 

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	// Некоторые реализации требуют для следующих адресов 
	// выполнить приведение к типу unsigned 
	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
rats = 101, rodents = 101
rats = 102, rodents = 102
rats address = 008FFDFC, rodents address = 008FFDFC
*/