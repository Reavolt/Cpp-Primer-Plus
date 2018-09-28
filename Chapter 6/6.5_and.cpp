//and.cpp -- использование логической операции "И" 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int ArSize = 6;
//-------------------------------------------------------------------------------------------------
int main()
{
	float naaq[ArSize];
	cout << "Enter the NAAQs (New Age Awareness Quotients) "
		 << "of\nyour neighbors. Program terminates "
		 << "when you make\n" << ArSize << " entries "
		 << "or enter a negative value.\n";

	int i = 0;
	float temp;
	cout << "First value: ";		// ввод первого значения 
	cin >> temp;
	while (i < ArSize && temp >= 0) // два критерия завершения 
	{
		naaq[i] = temp;
		++i;
		if (i < ArSize)             // в массиве еще есть место 
		{
			cout << "Next value: ";
			cin >> temp;            // ввод следующего значения 
		}
	}
	if (i == 0)
		cout << "No data--bye\n";	// данные отсутствуют 
	else
	{
		cout << "Enter your NAAQ: ";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
			if (naaq[j] > you)
				++count;
		cout << count;
		cout << " of your neighbors have greater awareness of\n"
			<< "the New Age than you do.\n";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter the NAAQs (New Age Awareness Quotients) of
your neighbors. Program terminates when you make
6 entries or enter a negative value.
First value: 28
Next value: 72
Next value: 15
Next value: 6
Next value: 130
Next value: 145
Enter your NAAQ: 50
3 of your neighbors have greater awareness of
the New Age than you do.
*/