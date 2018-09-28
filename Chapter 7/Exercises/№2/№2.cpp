//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cctype>

//------------------------------------------------------------------------------------------------
void enter_result(int golf_result[], int array_size);
double avg_result(int golf_result[], int array_size);
void output_result(double avg, int golf_result[], int array_size);
//------------------------------------------------------------------------------------------------
int main()
{
	const int SIZE = 10;

	int golf_result[SIZE] = { 0 };

	enter_result(golf_result, SIZE);
	double avg = avg_result(golf_result, SIZE);
	output_result(avg, golf_result, SIZE);

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
void enter_result(int golf_result[], int array_size) {

	std::cout << "Enter the results of the game (1-10). Q / q (for Exit): " << std::endl;

	for (size_t i = 0; i < 10; i++) 
	{
		std::cout << "№  - " << i + 1 << " = ";
		int enter = 0;
		std::cin >> enter;

		if (!std::cin)
		{
			std::cin.clear();

			while (std::cin.get() != '\n')
			{
				continue;
			}
			std::cout << "Invalid Input. \n" << std::endl;
			break;
		}
		else 
		if (enter < 0) 
		{
			break;
		}
		golf_result[i] = enter;
	}
}
//------------------------------------------------------------------------------------------------
double avg_result(int golf_result[], int array_size) 
{
	double avg = 0;
	double summ = 0;

	for (size_t i = 0; i < 10; i++) 
	{
		summ += golf_result[i];
	}
	avg = summ / 10;

	return avg;
}
//------------------------------------------------------------------------------------------------
void output_result(double avg, int golf_result[], int array_size) 
{
	std::cout << "Result = ";

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << golf_result[i] << " ";
	}
	std::cout << "AVG = " << avg << std::endl;
}
//------------------------------------------------------------------------------------------------