//stack.срр -- функции-члены класса Stack 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "Sales_class.h"

//-------------------------------------------------------------------------------------------------
SALES::Sales::Sales()
{
	double sales[QUARTERS] = { 0,0,0,0 };
	double average = 0;
	double max = 0;
	double min = 0;
}
//-------------------------------------------------------------------------------------------------
SALES::Sales::Sales(const double arr[], const int n) 
{
	average = find_avg(arr, n);
	max = find_max(arr, n);
	min = find_min(arr, n);

	for (size_t i = 0; i < QUARTERS; i++) 
	{
		sales[i] = 0; // заполняем оставшиеся элементы нулями
	}
}
//-------------------------------------------------------------------------------------------------
SALES::Sales::~Sales()
{
	//The body of the destructor
}
//-------------------------------------------------------------------------------------------------
void SALES::Sales::setSales() 
{
	for (int i = 0; i < QUARTERS; ++i)
	{
		std::cout << "Enter total sales for ";
		std::cout << i + 1 << " quarter: ";
		std::cin >> sales[i];
	}
	std::cout << std::endl;

	average = find_avg(sales, QUARTERS);
	max = find_max(sales, QUARTERS);
	min = find_min(sales, QUARTERS);
}
//-------------------------------------------------------------------------------------------------
void SALES::Sales::showSales() 
{
	std::cout << "Average value: " << average << std::endl;
	std::cout << "Maximum value: " << max << std::endl;
	std::cout << "Minimum value: " << min << std::endl;
}
//-------------------------------------------------------------------------------------------------
double SALES::Sales::find_avg(const double arr[], int size) 
{
	double summ = 0;
	for (size_t i = 0; i < size; i++) 
	{
		summ += arr[i];
	}
	return summ / size;
}
//-------------------------------------------------------------------------------------------------
double SALES::Sales::find_max(const double arr[], int size) 
{
	double max = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
//-------------------------------------------------------------------------------------------------
double SALES::Sales::find_min(const double arr[], int size) 
{
	double min = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
//-------------------------------------------------------------------------------------------------