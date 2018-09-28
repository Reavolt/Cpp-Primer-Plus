//condit.срр -- использование условной операции 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int a, b;
	cout << "Enter two integers: "; // запрос на ввод двух целых чисел 
	cin >> a >> b;
	cout << "The larger of " << a << " and " << b;
	int c = a > b ? a : b;       // с = а, если а > b, иначе с = b 
	cout << " is " << c << endl; // вывод большего из указанных чисел 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter two integers: 25 28
The larger of 25 and 28 is 28
*/