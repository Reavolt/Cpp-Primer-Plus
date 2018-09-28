//write.срр — использование cout.write() 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>  // или string.h

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	const char * state1 = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Euphoria";
	int len = std::strlen(state2);
	cout << "Increasing loop index:\n";
	int i;
	for (i = 1; i <= len; i++)
	{
		cout.write(state2, i);
		cout << endl;
	}

	// Конкатенация вывода 
	cout << "Decreasing loop index:\n";
	for (i = len; i > 0; i--)
		cout.write(state2, i) << endl;

	// Превышение длины строки 
	cout << "Exceeding string length:\n";
	cout.write(state2, len + 5) << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Increasing loop index:
K
Ka
Kan
Kans
Kansa
Kansas
Decreasing loop index:
Kansas
Kansa
Kans
Kan
Ka
K
Exceeding string length:
Kansas  Eup
Для продолжения нажмите любую клавишу . . .
*/