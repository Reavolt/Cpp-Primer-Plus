//check_it.cpp -- проверка допустимости ввода 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	cout << "Enter numbers: ";

	int sum = 0;
	int input;
	while (cin >> input)
	{
		sum += input;
	}

	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter numbers: 200
10 -50 -123z 60
Last value entered = -123
Sum = 37
*/