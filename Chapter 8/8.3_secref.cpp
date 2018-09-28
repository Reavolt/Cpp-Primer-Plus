//secref.срр -- определение и использование ссылки 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	int rats = 101;
	int & rodents = rats; // rodents - это ссылка 
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl; // вывод адресов rats и rodents 

	int bunnies = 50;
	rodents = bunnies; // можно ли изменить ссылку? 
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	cout << "bunnies address = " << &bunnies;
	cout << ", rodents address = " << &rodents << endl; // вывод адресов bunnies и rodents 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
rats = 101, rodents = 101
rats address = 009CFB6C, rodents address = 009CFB6C
bunnies = 50, rats = 50, rodents = 50
bunnies address = 009CFB54, rodents address = 009CFB6C
*/