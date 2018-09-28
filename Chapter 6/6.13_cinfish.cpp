//cinfish.cpp -- нечисловой ввод прекращает выполнение цикла 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

const int Max = 5;
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	// получение данных 
	double fish[Max];
	cout << "Please enter the weights of your fish.\n";
	cout << "You may enter up to " << Max
		 << " fish <q to terminate>.\n"; // ввод веса пойманных рыб 
	cout << "fish #1: ";
	int i = 0;
	while (i < Max && cin >> fish[i]) {
		if (++i < Max)
			cout << "fish #" << i + 1 << ": ";
	}
	// вычисление среднего значения 
	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[j];
	// вывод результатов 
	if (i == 0)
		cout << "No fish\n"; // рыбы нет 
	else
		cout << total / i << " = average weight of "
		<< i << " fish\n"; // средний вес рыбы 
	cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Please enter the weights of your fish.
You may enter up to 5 fish <q to terminated
fish #1: 30
fish #2: 35
fish #3: 25
fish #4: 40
fish #5: q
32.5 = average weight of 4 fish
Done.
*/