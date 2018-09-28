// usetime2.cpp — использование третьей черновой версии класса Time 
// Компилировать usetime2.срр и mytime2.cpp вместе 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "11.7_mytime2.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;
	cout << "weeding time = "; // время на подготовку 
	weeding.Show();
	cout << endl;
	cout << "waxing time = "; // полезное время 
	waxing.Show();
	cout << endl;
	cout << "total work time = "; // общее рабочее время
	total = weeding + waxing;	  // используется operator+() 
	total.Show();
	cout << endl;
	diff = weeding - waxing; // используется operator-() 
	cout << "weeding time - waxing time = ";
	diff.Show();
	cout << endl;
	adjusted = total * 1.5;	// используется operator*() 
	cout << "adjusted work time = ";
	adjusted.Show();
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
weeding time = 4 hours, 35 minutes
waxing time = 2 hours, 47 minutes
total work time = 7 hours, 22 minutes
weeding time - waxing time = 1 hours, 48 minutes
adjusted work time = 11 hours, 3 minutes
Для продолжения нажмите любую клавишу . . .
*/