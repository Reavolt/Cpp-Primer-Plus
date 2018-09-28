//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "What is your first name? ";
	char first_name[128];
	std::cin >> first_name;

	std::cout << "What is your last name? ";
	char last_name[128];
	std::cin >> last_name;

	char result[256];
	strcpy(result, last_name);
	strcat(result, ", ");
	strcat(result, first_name);
	std::cout << "Here's the information in a single string: " << result << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------