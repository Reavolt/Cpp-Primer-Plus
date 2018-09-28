//cingolf.срр -- нечисловой ввод пропускается
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

const int Max = 5;
//-------------------------------------------------------------------------------------------------
int main()
{
	using namespace std;
	// Получение данных 
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << Max << " rounds.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i])) {
			cin.clear();     // сброс ввода 
			while (cin.get() != '\n')
				continue;    // отбрасывание некорректного ввода 
			cout << "Please enter a number: ";
		}
	}
	// Вычисление среднего 
	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];
	// Вывод результатов
	cout << total / Max << " = average score "
		<< Max << " rounds\n";
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Please enter your golf scores.
You must enter 5 rounds.
round #1: 88
round #2: 87
round #3: must i?
Please enter a number: 103
round #4 : 94
round #5: 86
91.6 = average score 5 rounds
*/