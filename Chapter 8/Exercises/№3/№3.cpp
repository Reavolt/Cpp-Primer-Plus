//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

//-------------------------------------------------------------------------------------------------
void uppercase(std::string & text);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter a string (q to quit) : ";
	std::string text;

	while (getline(std::cin, text) && text != "q")
	{
		uppercase(text);
		std::cout << "Next string (q to quit) : ";
	}
	std::cout << "Bye." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void uppercase(std::string & text)
{
	std::transform(text.begin(), text.end(), text.begin(), std::toupper);
	std::cout << text << std::endl;
}
//-------------------------------------------------------------------------------------------------