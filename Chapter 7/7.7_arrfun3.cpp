//arrfun3.cpp -- функция работы с массивами и применение const 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

const int Max = 5;
//------------------------------------------------------------------------------------------------
// Прототипы функций 
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n); // не изменять данные 
void revalue(double r, double ar[], int n);
//------------------------------------------------------------------------------------------------
int main() 
{
	double properties[Max];
	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "Enter revaluation factor: "; // ввод коэффициента переоценки 
		double factor;
		while (!(cin >> factor)) // неправильный ввод 
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: "; // повторный запрос на ввод числа 
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
int fill_array(double ar[], int limit)
{
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ": "; //Ввод значения
			cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n"; // процесс ввода прекращен 
			break;
		}
		else if (temp < 0) // сигнал завершения 
			break;
		ar[i] = temp;
	}
	return i;
}
//------------------------------------------------------------------------------------------------
// Следующая функция может использовать, но не изменять, массив по адресу аг 
void show_array(const double ar[], int n)
{
	using namespace std;
	// Вывод содержимого массива аг 
	for (int i = 0; i < n; i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	}
}
// Умножает на г каждый элемент аг[] 
void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
		 ar[i] *= r;
}
//------------------------------------------------------------------------------------------------
/*
Enter value #1: 100000
Enter value #2: 80000
Enter value #3: 222000
Enter value #4: 240000
Enter value #5: 118000
Property #1: $100000
Property #2: $80000
Property #3: $222000
Property #4: $240000
Property #5: $118000
Enter revaluation factor: 0.8
Property #1: $80000
Property #2: $64000
Property #3: $177600
Property #4: $192000
Property #5: $94400
Done.

Enter value #1: 200000
Enter value #2: 84000
Enter value #3: 160000
Enter value #4: -2
Property #1: $200000
Property #2: $84000
Property #3: $160000
Enter revaluation factor: 1.20
Property #1: $240000
Property #2: $100800
Property #3: $192000
Done.
*/