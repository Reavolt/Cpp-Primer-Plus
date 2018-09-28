//ifelseif.cpp -- использование оператора if else if else 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int Fave = 27;
//-------------------------------------------------------------------------------------------------
int main() 
{
	int n = 0;
	cout << "Enter a number in the range 1-100 to find ";
	cout << "my favorite number: "; // запрос на ввод числа из диапазона 1-100 
	do
	{
		cin >> n;
		if (n < Fave)
			cout << "Too low -- guess again: "; // число слишком мало 
		else if (n > Fave)
			cout << "Too high -- guess again: "; // число слишком велико 
		else
			cout << Fave << " is right! \n"; // число угадано 
	} while (n != Fave);
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter a number in the range 1-100 to find my favorite number: 50
Too high -- guess again: 25
Too low -- guess again: 37
Too high -- guess again: 31
Too high -- guess again: 28
Too high -- guess again: 27
27 is right!
*/