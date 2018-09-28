//forloop.cpp -- представление цикла for 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int i; // создание счетчика 
		   // инициализация; проверка; обновление 
	for (i = 0; i < 5; i++) 
		cout << "C + + knows loops.\n";
	cout << "C++ knows when to stop.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
C + + knows loops.
C + + knows loops.
C + + knows loops.
C + + knows loops.
C + + knows loops.
C++ knows when to stop.
*/