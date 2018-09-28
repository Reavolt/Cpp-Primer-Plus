//if.срр -- использование оператора if 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	char ch;
	int spaces = 0;
	int total = 0;
	cin.get(ch);
	while (ch != '.')  // завершение по окончании предложения 
	{
		if (ch == ' ') // проверка ch на равенство пробелу 
			++spaces;
		++total;	   // выполняется на каждом шаге цикла 
		cin.get(ch);
	}
	cout << spaces << " spaces, " << total; // вывод количества пробелов 
										    // и символов в предложении 
	cout << " characters total in sentence\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
The balloonist was an airhead
with lofty goals.
6 spaces, 46 characters total in sentence
*/