//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
void celsius_at_fahrenheit(int);
//-------------------------------------------------------------------------------------------------
int main() 
{
	std::cout << "Pleas enter a celsius value: ";
	
	int celsius = 0;
	std::cin >> celsius;
	
	celsius_at_fahrenheit(celsius);
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void celsius_at_fahrenheit(int celsius) 
{
	int fahrenheit = 1.8 * celsius + 32;
	std::cout << celsius << " degrees Celsius is " << fahrenheit << " degrees fahrenheit" << std::endl;
}
//-------------------------------------------------------------------------------------------------
