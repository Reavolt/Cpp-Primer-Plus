//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>

const int SIZE_INT = 6;
const int SIZE_DOUBLE = 4;
const int SIZE_CHAR = 5;
//-------------------------------------------------------------------------------------------------
template <typename T>
T maxn(T* massiv, int size);
const char* maxn(const char* massiv[], int size);
//-------------------------------------------------------------------------------------------------
int main()
{
	int massiv_int[SIZE_INT] = { 1,2,2,4,52 };
	double massiv_double[SIZE_DOUBLE] = { 0.1,2.4,0.4,33.1 };
	const char *words[SIZE_CHAR] = { "Ham","Bread","Sandwich","Asparagus","Chocolate" };

	std::cout << "The maximum value of the array INT = ";
	std::cout << maxn(massiv_int, SIZE_INT) << std::endl;
	std::cout << "The maximum value of the array DOUBLE = ";
	std::cout << maxn(massiv_double, SIZE_DOUBLE) << std::endl;
	std::cout << "The maximum value of the array CHAR = ";
	std::cout << maxn(words, SIZE_CHAR) << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <typename T>
T maxn(T* massiv, int size) 
{
	T max = massiv[0];
	for (size_t i = 0; i < size; i++)
	{
		if (max < massiv[i])
		{
			max = massiv[i];
		}
	}
	return max;
}
//-------------------------------------------------------------------------------------------------
const char* maxn(const char* massiv[], int size) 
{
	const char* max_lenght_string = &massiv[0][0];
	int max_characters = strlen(massiv[0]);
	int next = 0;

	for (size_t i = 0; i < size; i++)
	{
		next = strlen(massiv[i]);
		if (next > max_characters)
		{
			max_characters = next;
			max_lenght_string = &massiv[i][0];
		}
	}
	return max_lenght_string;
}
//-------------------------------------------------------------------------------------------------