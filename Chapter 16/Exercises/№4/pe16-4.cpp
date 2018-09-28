//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <vector>
#include <algorithm>

const int SIZE = 15;
//-------------------------------------------------------------------------------------------------
int reduce(long ar[], int n);
//-------------------------------------------------------------------------------------------------
int main()
{

	std::cout << "Enter up to " << SIZE << " numbers (quit to quit):";
	
	long num = 0;
	long ar[SIZE];
	int i = 0;
	
	while (std::cin >> num && i < SIZE)
	{
		ar[i++] = num;
	}

	if (0 == i)
	{
		std::cout << "No values were entered" << std::endl;
		return 0;
	}

	std::cout << "You entered ";
	for (int j = 0; j < i; j++)
	{
		std::cout << ar[j] << " ";
	}
	std::cout << std::endl;

	std::cout << "Here's your sorted array, without duplicates: ";
	
	int j = reduce(ar, i);
	for (int k = 0; k < j; k++)
	{
		std::cout << ar[k] << " ";
	}
	std::cout << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
int reduce(long ar[], int n)
{
	std::vector<long> var;
	for (int i = 0; i < n; i++)
	{
		var.push_back(ar[i]);
	}

	sort(var.begin(), var.end());
	std::vector<long>::iterator end = unique(var.begin(), var.end());
	var.erase(end, var.end());
	std::vector<long>::iterator iv = var.begin();
	
	for (int i = 0; iv != var.end(); iv++, i++)
	{
		ar[i] = *iv;
	}
	return var.size();
}
//-------------------------------------------------------------------------------------------------