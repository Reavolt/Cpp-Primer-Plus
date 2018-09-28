//insrtl.срр -- чтение более одной строки 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "Enter your name:\n"; // запрос имени 
	cin >> name;
	cout << "Enter your favorite dessert:\n"; // запрос любимого десерта 
	cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << " .\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter your name:
Alistair Dreeb
Enter your favorite dessert:
I have some delicious Dreeb for you, Alistair.
*/