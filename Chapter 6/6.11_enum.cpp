//enum.cpp -- использование enum 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;
//-------------------------------------------------------------------------------------------------
// создание именованный констант для значений 0-6 
enum { red, orange, yellow, green, blue, violet, indigo };
//-------------------------------------------------------------------------------------------------
int main()
{

	cout << "Enter color code (0-6): "; // ввод кода цвета 
	int code = 0;
	cin >> code;
	while (code >= red && code <= indigo)
	{
		switch (code)
		{
		case red: cout << "Her lips were red.\n"; break;
		case orange: cout << "Her hair was orange.\n"; break;
		case yellow: cout << "Her shoes were yellow.\n"; break;
		case green: cout << "Her nails were green.\n"; break;
		case blue: cout << "Her sweatsuit was blue.\n"; break;
		case violet: cout << "Her eyes were violet.\n"; break;
		case indigo: cout << "Her mood was indigo.\n"; break;
		}
		cout << "Enter color code (0-6): ";
		cin >> code;
	}
	cout << "Bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter color code (0-6): 3
Her nails were green.
Enter color code (0-6): 5
Her eyes were violet.
Enter color code (0-6): 2
Her shoes were yellow.
Enter color code (0-6): 8
Bye
*/