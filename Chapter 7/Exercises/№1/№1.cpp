//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//------------------------------------------------------------------------------------------------
void average_harmonic(int x, int y);
//------------------------------------------------------------------------------------------------
int main() 
{
	int x = 0;
	int y = 0;
	std::cout << "Enter x and y: " << std::endl;

	while (cin >> x >> y)
	{
		if ((x != 0) && (y != 0)) 
		{
			average_harmonic(x, y);
			std::cout << "Enter x and y: " << std::endl;
		}
		else 
		{
			return 0;
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------
void average_harmonic(int x, int y) 
{
	double result = 2.0 * x * y / (x + y);
	std::cout << "The average harmonic " << x << " and " << y << " = " << result << std::endl;
}
//------------------------------------------------------------------------------------------------
/*
Enter x and y:
1 1
The average harmonic 1 and 1 = 1
Enter x and y:
22 32
The average harmonic 22 and 32 = 26.0741
Enter x and y:
12 12
The average harmonic 12 and 12 = 12
Enter x and y:
0 1
*/