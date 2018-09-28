//numstr.срр -- строковый ввод после числового 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	cout << "What year was your house built?\n"; // ввод года постройки дома 
	int year;
	cin >> year;
	cin.get();
	cout << "What is its street address?\n"; // ввод адреса 
	char address[80];
	cin.getline(address, 80);
	cout << "Year built: " << year << endl; // вывод года постройки 
	cout << "Address: " << address << endl; // вывод адреса 
	cout << "Done!\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
What year was your house built?
1966
What is its street address?
Year built: 1966
Address:
Done!
*/