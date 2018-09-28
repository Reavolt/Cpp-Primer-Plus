//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>

const int SIZE = 15;
//-------------------------------------------------------------------------------------------------
template <typename T>
int reduce(T ar[], int n);

template <>
int reduce<std::string>(std::string ar[], int n);

template <typename T>
int data_input(T ar[], int n);

template <>
int data_input<std::string>(std::string ar[], int n);

template <typename T>
void display(T ar[], int begin, int end);

bool string_compare(std::string s1, std::string s2);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Would you like to enter strings or integers? "
		<< "(s for strings, i for integers)" << std::endl;
	char ch;
	ch = std::cin.get();
	ch = tolower(ch);
	if (ch != 's' && ch != 'i')
	{
		std::cout << "Input should be \"s\" or \"i\" (case insensitive)";
		std::cout << std::endl;
		std::cout << "Program abort" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (ch == 's')
	{
		std::string sar[SIZE];
		int values = data_input(sar, SIZE);

		if (0 == values)
		{
			std::cout << "No values were entered" << std::endl;
			return 0;
		}

		std::cout << "You entered ";
		display(sar, 0, values);

		std::cout << "Here's your sorted array, without duplicates: \n";
		int j = reduce(sar, values);
		display(sar, 0, j);
	}
	else
	{
		long ar[SIZE];
		int values = data_input(ar, SIZE);

		if (0 == values)
		{
			std::cout << "No values were entered" << std::endl;
			return 0;
		}

		std::cout << "You entered ";
		display(ar, 0, values);

		std::cout << "Here's your sorted array, without duplicates: \n";
		int j = reduce(ar, values);
		display(ar, 0, j);
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
int reduce(T ar[], int n)
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
template <>
int reduce<std::string>(std::string ar[], int n)
{
	std::vector<std::string> var;
	for (int i = 0; i < n; i++)
	{
		var.push_back(ar[i]);
	}

	sort(var.begin(), var.end(), string_compare);
	std::vector<std::string>::iterator end = unique(var.begin(), var.end());
	var.erase(end, var.end());
	std::vector<std::string>::iterator iv = var.begin();
	
	for (int i = 0; iv != var.end(); iv++, i++)
	{
		ar[i] = *iv;
	}
	return var.size();
}
//-------------------------------------------------------------------------------------------------
template <typename T>
int data_input(T ar[], int n)
{
	std::cout << "Enter up to " << n << " values (quit to quit):";
	
	T value;
	int i = 0;
	
	while (std::cin >> value && i < n)
	{
		ar[i++] = value;
	}
	return i;
}
//-------------------------------------------------------------------------------------------------
template <>
int data_input<std::string>(std::string ar[], int n)
{
	std::cout << "Enter up to " << n << " strings (quit to quit):";
	
	std::string value;
	int i = 0;
	
	while (std::cin >> value && i < n && value != "quit")
	{
		ar[i++] = value;
	}
	return i;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void display(T ar[], int begin, int end)
{
	for (int k = begin; k < end; k++)
	{
		std::cout << ar[k] << " ";
	}
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
bool string_compare(std::string s1, std::string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}
//-------------------------------------------------------------------------------------------------