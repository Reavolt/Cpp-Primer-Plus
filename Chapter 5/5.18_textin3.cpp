//textin3.cpp -- чтение символов до конца файла 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	char ch;
	int count = 0;
	cin.get(ch); // попытка чтения символа 
	while (cin.fail() == false) // проверка на EOF 
	{
		cout << ch; // отображение символа 
		++count;
		cin.get(ch); // попытка чтения следующего символа 
	}
	cout << endl << count << " characters read\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
The green bird sings in the winter.<Enter>
The green bird sings in the winter.
Yes, but the crow flies in the dawn.<Enter>
Yes, but the crow flies in the dawn.
<Ctrl+Z><Enter>
73 characters read
*/