//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

const int Max = 5;
//----------------------------------------------------------------------------------------------------
double* fill_array(double* arrBegin, double* arrEnd);
void show_array(double* arrBegin, double* arrEnd);
void revalue(double r, double* arrBegin, double* arrEnd);
//----------------------------------------------------------------------------------------------------
int main()
{
	double properties[Max];
	double *size = fill_array(properties, properties + Max);
	show_array(properties, size);

	if (size > 0)
	{
		std::cout << "Enter revaluation factor: ";
		double factor = 0.0;
		while (!(std::cin >> factor))
		{
			std::cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			std::cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	std::cout << "Done.\n";
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//----------------------------------------------------------------------------------------------------
double* fill_array(double* arrBegin, double* arrEnd)
{
	double temp = 0.0;
	int i = 0;
	double* pt = nullptr;

	for (pt = arrBegin; pt != arrEnd; pt++)
	{
		std::cout << "Enter value #" << (++i) << ": ";
		std::cin >> temp;
		
		if (!std::cin)
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
			{
				continue;
			}
			std::cout << "Bad input; input process terminated.\n";
			break;
		}
		else 
		if (temp < 0)
		{
			break;
		}
		*pt = temp;
	}
	return pt;
}
//----------------------------------------------------------------------------------------------------
void show_array(double* arrBegin, double* arrEnd)
{
	int i = 0;
	for (double *pt = arrBegin; pt != arrEnd; pt++)
	{
		std::cout << "Property #" << (++i) << ": $";
		std::cout << *pt << std::endl;
	}
}
//----------------------------------------------------------------------------------------------------
void revalue(double factor, double* arrBegin, double* arrEnd)
{
	for (double *pt = arrBegin; pt != arrEnd; pt++) 
	{
		 *pt *= factor;
	}
}
//----------------------------------------------------------------------------------------------------