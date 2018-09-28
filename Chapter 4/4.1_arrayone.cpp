//arrayone.срр -- небольшие массивы целых чисел 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int yams[3]; // создание массива из трех элементов 
	yams[0] = 7; // присваивание значения первому элементу 
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = { 20, 30, 5 }; // создание и инициализация массива 

	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents. \n";

	cout << "\nSize of yams array = " << sizeof yams;
	cout << " bytes. \n";
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes. \n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Total yams = 21
The package with 8 yams costs 30 cents per yam.
The total yam expense is 410 cents.

Size of yams array = 12 bytes.
Size of one element = 4 bytes.
*/