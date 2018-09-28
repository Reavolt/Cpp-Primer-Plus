//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main() 
{
	std::cout << "Enter the number of frolongs " << std::endl;
	
	int frolong = 0;
	std::cin >> frolong;
	
	int yard = frolong * 220;
	std::cout << frolong << " Frolong, this " << yard;
	std::cout << " yard" << std::endl;
		 
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
