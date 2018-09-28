//convert.срр -- преобразует стоуны в фунты 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath> // Библиотека математических функций

using namespace std;

//-------------------------------------------------------------------------------------------------
int stonetolb(int);
//-------------------------------------------------------------------------------------------------
int main() 
{
	int stone;
	cout << "Enter the weight in stone: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " stone = ";
	cout << pounds << " pounds." << endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
int stonetolb(int sts) 
{
	return 14 * sts;
}
//-------------------------------------------------------------------------------------------------
/*
Enter the weight in stone: 15
15 stone = 210 pounds.
*/
