//dowhile.срр -- цикл с проверкой на выходе 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	int n = 0;
	cout << "Enter numbers in the range 1-10 to find ";
	cout << "my favorite number\n"; // запрос на ввод любимого числа из диапазона 1-10 
	do
	{
	  cin >> n;		  // выполнить тело 
	} while (n != 7); // затем проверить 
	cout << "Yes, 7 is my favorite. \n"; // любимое число - 7 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter numbers in the range 1-10 to find my favorite number
9
4
7
Yes, 7 is my favorite.
*/