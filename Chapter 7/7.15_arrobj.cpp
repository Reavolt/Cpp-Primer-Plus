//arrobj.cpp -- функции с объектами array (С++11) 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <array> 
#include <string> 

using namespace std;

// Константные данные 
const int Seasons = 4;
//------------------------------------------------------------------------------------------------
const array<string, Seasons> Snames =
{ 
	"Spring", "Summer", "Fall", "Winter" 
};
//------------------------------------------------------------------------------------------------
// Функция для изменения объекта array 
void fill(array<double, Seasons> * pa);
// Функция, использующая объект array, но не изменяющая его 
void show(array<double, Seasons> da);
//------------------------------------------------------------------------------------------------
int main()
{
	array<double, Seasons> expenses;
	fill(&expenses);
	show(expenses);

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
void fill(array<double, Seasons> * pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		 cout << "Enter " << Snames[i] << " expenses: "; // ввод расходов по временам года 
		 cin >> (*pa)[i];
	}
}
//------------------------------------------------------------------------------------------------
void show(array<double, Seasons> da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n"; // вывод расходов по временам года 
	for (int i = 0; i < Seasons; i++)
	{
		 cout << Snames[i] << ": $" << da[i] << endl;
		 total += da[i];
	}
	cout << "Total Expenses: $" << total << endl; // вывод общей суммы расходов 
}
//------------------------------------------------------------------------------------------------
/*
Enter Spring expenses: 212
Enter Summer expenses: 256
Enter Fall expenses: 208
Enter Winter expenses: 244

EXPENSES
Spring: $212
Summer: $256
Fall: $208
Winter: $244
Total Expenses: $920
*/