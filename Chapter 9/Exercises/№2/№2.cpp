//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

// Константы 
const int ArSize = 10;
//-------------------------------------------------------------------------------------------------
// Прототип функции 
void strcount(const std::string str);
//-------------------------------------------------------------------------------------------------
int main()
{
	std::string input;
	std::string next;

	std::cout << "Enter a line: ";
	getline(std::cin, input);

	do
	{
		strcount(input);
		std::cout << "Enter next line (empty line to quit): ";
		getline(std::cin, input);
	} 
	while (input != "");
	
	std::cout << "Bye" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void strcount(const std::string str)
{
	static int total = 0; // статическая локальная переменная 
	int count = 0; 		  // автоматическая локальная переменная 

	std::cout << "\"" << str << "\" contains ";

	for (size_t i = 0; i < str.size(); i++)
	{
		count++;
	}

	total += count;
	std::cout << count << " characters\n";
	std::cout << total << " characters total\n";
}
//-------------------------------------------------------------------------------------------------