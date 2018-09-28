//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter a and b: ";
	int a = 0; 
	int b = 0;
	std::cin >> a >> b;

	int result = 0;
	for (int i = a; i <= b; i++) 
	{
		result += i;
	}
	std::cout << "Result: " << result << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
