// usetimel.срр — использование второй черновой версии класса Time 
// компилировать usetimel.срр и mytimel.cpp вместе 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "11.4_mytime1.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;
	cout << "planning time = ";	// время на планирование 
	planning.Show();
	cout << endl;
	cout << "coding time = ";	// время на кодирование 
	coding.Show();
	cout << endl;
	cout << "fixing time = "; // время на исправление 
	fixing.Show();
	cout << endl;
	total = coding + fixing;
	// Нотация с операцией 
	cout << "coding + fixing = "; // кодирование + исправление 
	total.Show();
	cout << endl;
	Time morefixing(3, 28);
	cout << "more fixing time = "; // дополнительное время на исправление 
	morefixing.Show();
	cout << endl;
	total = morefixing.operator+(total);
	// Нотация с функцией 
	cout << "morefixing.operator+(total) = ";
	total.Show();
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
planning time = 0 hours, 0 minutes
coding time = 2 hours, 40 minutes
fixing time = 5 hours, 55 minutes
coding + fixing = 8 hours, 35 minutes
more fixing time = 3 hours, 28 minutes
morefixing.operator+(total) = 12 hours, 3 minutes
Для продолжения нажмите любую клавишу . . .
*/