//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "What is your first name? ";
	std::string first_name;
	std::cin >> first_name;

	std::cout << "What is your last name? ";
	std::string lasr_name;
	std::cin >> lasr_name;

	std::string result;
	result = lasr_name + ", " + first_name;
	std::cout << "Here's the information in a single string: " << result << std::endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------