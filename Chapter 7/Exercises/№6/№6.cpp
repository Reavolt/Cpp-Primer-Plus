//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

const int SIZE = 10;
//----------------------------------------------------------------------------------------------------
void fill_array(double* massiv, int size, double number);
void Show_array(double massiv[], int size, double number);
void Reverse_array(double massiv[], int size, double number);
//----------------------------------------------------------------------------------------------------
int main()
{
	double massiv[SIZE] = { 0 };
	double number = 0.0;

	fill_array(massiv, SIZE, number);
	Reverse_array(massiv, SIZE, number);
	Show_array(massiv, SIZE, number);

	std::cin.get();
	std::cin.get();
	return 0;
}
//----------------------------------------------------------------------------------------------------
void fill_array(double* massiv, int size, double number)
{
	 for (size_t i = 0; i < size; i++) 
	 {
		  std::cout << "№ " << i + 1 << " = ";
		  if (std::cin >> number) 
		  {
			  massiv[i] = number;
		  }
		  else 
		  {
			  break;
		  }
	 }
	 std::cout << std::endl;
}
//----------------------------------------------------------------------------------------------------
void Reverse_array(double massiv[], int size, double number) 
{
	for (size_t i = 0; i < size / 2; i++) 
	{
		 double revers = 0;

		 revers = massiv[i];
		 massiv[i] = massiv[size - 1 - i];
		 massiv[size - 1 - i] = revers;
	}
}
//----------------------------------------------------------------------------------------------------
void Show_array(double massiv[], int size, double number)
{
	for (size_t i = 0; i < size; i++) 
	{
		std::cout << "№ " << i + 1 << " = ";
		std::cout << massiv[i] << std::endl;
	}
}
//----------------------------------------------------------------------------------------------------