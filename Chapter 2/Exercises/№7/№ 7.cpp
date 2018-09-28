//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main() {
	
	std::cout << "Enter the number of hours: ";
	int hour = 0;
	std::cin >> hour;
	
	std::cout << "Enter the number of minutes: ";
	int minutes = 0;
	std::cin >> minutes;
	
	std::cout << "Time: " << hour << ":" << minutes << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
