//textin1.cpp -- чтение символов в цикле while 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	char ch;
	int count = 0; // использование базового ввода 
	cout << "Enter characters; enter # to quit:\n";
	cin >> ch; // получение символа 
	while (ch != '#') // проверка символа 
	{
		cout << ch; // отображение символа 
		++count; // подсчет символа 
		cin >> ch; // получение следующего символа 
	}
	cout << endl << count << " characters read\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter characters; enter # to quit:
see ken run#really fast
seekenrun
9 characters read
*/