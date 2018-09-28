//cinexcp.cpp -- cin, генерирующий исключения 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	// Установленный бит failbit вызовет генерацию исключения 
	cin.exceptions(ios_base::failbit);
	cout << "Enter numbers: ";	// запрос на ввод чисел 
	int sum = 0;
	int input;
	try {
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure & bf)
	{
		cout << bf.what() << endl;
		cout << "O! the horror!\n";
	}

	cout << "Last value entered = " << input << endl;	// вывод последнего введенного числа 
	cout << "Sum = " << sum << endl;	// вывод суммы введенных чисел 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter numbers: 20 30 40 pi 6
ios_base::failbit set: iostream stream error
O! the horror!
Last value entered = 40
Sum = 90
*/