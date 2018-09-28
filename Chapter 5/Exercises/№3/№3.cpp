//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	long long int result = 0;
	int a = 0;

	do 
	{
		std::cout << "Enter chislo: ";
		std::cin >> a;
		result += a;
		std::cout << "A = " << result << std::endl;
	} 
	while (a != 0);
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------