//insrt2.cpp -- чтение более одного слова с помощью getline()
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
	cin.getline(name, ArSize); 	  // читать до символа новой строки 
	cout << "Enter your favorite dessert:\n"; // запрос любимого десерта 
	cin.getline(dessert, ArSize);
	cout << "I have some delicious" << dessert;
	cout << " for you, " << name << " .\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter your name:
Dirk Hammernose
Enter your favorite dessert:
Radish Torte
I have some delicious Radish Torte'for you, Dirk Hammernose.
*/