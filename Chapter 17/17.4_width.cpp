//width.срр — использование метода width 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	int w = cout.width(30);
	cout << "default field width = " << w << ":\n";

	cout.width(5);
	cout << "N" << ':';
	cout.width(8);
	cout << "N * N" << ":\n";

	for (long i = 1; i <= 100; i *= 10)
	{
		cout.width(5);
		cout << i << ':';
		cout.width(8);
		cout << i * i << ":\n";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
		default field width = 0:
   N:   N * N:
   1:       1:
  10:     100:
 100:   10000:
Для продолжения нажмите любую клавишу . . .
*/