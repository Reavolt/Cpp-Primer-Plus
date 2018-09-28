//auto.срр -- иллюстрация области видимости автоматических переменных 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
void oil(int x);
//-------------------------------------------------------------------------------------------------
int main()
{
	int texas = 31;
	int year = 2011;
	cout << "In main(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In main(), year = " << year << ", &year = ";
	cout << &year << endl;
	oil(texas);
	cout << "In main(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In main(), year = " << year << ", &year = ";
	cout << &year << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void oil(int x)
{
	int texas = 5;
	cout << "In oil(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In oil(), x = " << x << ", &x = ";
	cout << &x << endl;
	{			// начало блока 
		int texas = 113;
		cout << "In block, texas = " << texas;
		cout << ", &texas = " << &texas << endl;
		cout << "In block, x = " << x << ", &x = ";
		cout << &x << endl;
	}			// конец блока 
	cout << "Post-block texas = " << texas;
	cout << ", &texas = " << &texas << endl;
}
//-------------------------------------------------------------------------------------------------
/*
In main(), texas = 31, &texas = 0135FC78
In main(), year = 2011, &year = 0135FC6C
In oil(), texas = 5, &texas = 0135FB88
In oil(), x = 31, &x = 0135FB98
In block, texas = 113, &texas = 0135FB7C
In block, x = 31, &x = 0135FB98
Post-block texas = 5, &texas = 0135FB88
In main(), texas = 31, &texas = 0135FC78
In main(), year = 2011, &year = 0135FC6C
*/