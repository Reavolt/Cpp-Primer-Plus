// tempover.срр -- перегрузка шаблонов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
struct debts
{
	char name[50];
	double amount;
};
//-------------------------------------------------------------------------------------------------
template <typename T> // шаблон А 
void ShowArray(T arr[], int n);
template <typename T> // шаблон В 
void ShowArray(T * arr[], int n);
//-------------------------------------------------------------------------------------------------
int main()
{
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
		{ "Ima Wolfe", 2400.0 },
		{ "Ura Foxe", 1300.0 },
		{ "Iby Stout", 1800.0 }
	};

	double* pd[3];
	// Установка указателей на члены amount структур в mr_E 
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	cout << "Listing Mr. E's counts of things :\n";

	// things - массив значений int 
	ShowArray(things, 6); // использует шаблон А 
	cout << "Listing Mr. E's debts:\n";
	// pd - массив указателей на double 
	ShowArray(pd, 3); // использует шаблон В (более специализированный) 

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	for (int i = 0; i < n; i++)
	cout << arr[i] << ' ';
	cout << endl;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
void ShowArray(T* arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	for (int i = 0; i < n; i++)
	cout << *arr[i] << ' ';
	cout << endl;
}
//-------------------------------------------------------------------------------------------------
/*
Listing Mr. E's counts of things :
template A
13 31 103 301 310 130
Listing Mr. E's debts:
template B
2400 1300 1800
*/