//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
struct debts
{
	char name[50];
	double amount;
};
//-------------------------------------------------------------------------------------------------
template <typename T> // шаблон А 
T ShowArray(T arr[], int n);
template <typename T> // шаблон В 
T ShowArray(T* arr[], int n);
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

	for (int i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}
	
	std::cout << "Listing Mr. E's counts of things :\n";
	std::cout << "Number of items = " << ShowArray(things, 6) << std::endl; 

	std::cout << "Listing Mr. E's debts:\n";
	std::cout << "Amount of arrears = " << ShowArray(pd, 3) << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
T ShowArray(T arr[], int n)
{
	std::cout << "template A\n";
	T count = 0;
	for (size_t i = 0; i < n; i++) 
	{
		count++;
	}
	return count;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
T ShowArray(T* arr[], int n)
{
	std::cout << "template B\n";
	T summ = 0;
	for (size_t i = 0; i < n; i++) 
	{
		summ += *arr[i];
	}
	return summ;
}
//-------------------------------------------------------------------------------------------------