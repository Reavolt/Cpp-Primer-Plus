//block.срр -- использование блока 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
int main() 
{
	cout << "The Amazing Accounto will sum and average ";
	cout << "five numbers for you.\n";
	cout << "Please enter five values:\n";
	double number = 0.0;
	double sum = 0.0;
	for (int i = 1; i <= 5; i++)
	{// начало блока 
		 cout << "Value " << i << " : ";// ввод числа 
		 cin >> number;
		 sum += number;
	}// конец блока 
	
	cout << "Five exquisite choices indeed! ";
	cout << "They sum to " << sum << endl; // вывод суммы 
	cout << "and average to " << sum / 5 << ".\n"; // вывод среднего значения 
	cout << "The Amazing Accounto bids you adieu! \n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
The Amazing Accounto will sum and average five numbers for you.
Please enter five values:
Value 1 : 3
Value 2 : 5
Value 3 : 7
Value 4 : 8
Value 5 : 3
Five exquisite choices indeed! They sum to 26
and average to 5.2.
The Amazing Accounto bids you adieu!
*/