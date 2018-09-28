//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
void print_text(const string* pt, int flag = 0);
//-------------------------------------------------------------------------------------------------
int main()
{
	string word = "Long Live Rock-n-roll!";
	print_text(&word);
	word = "Let There Be Rock!";
	print_text(&word);
	print_text(&word);
	word = "Be Quick Or Be Dead!";
	print_text(&word, 1);
	
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void print_text(const string* pt, int flag) 
{
	static int count = 0;

	if (flag != 0) 
	{
		for (size_t i = 0; i < count; i++) 
		{
			std::cout << *pt << std::endl;
		}
	}
	else 
	{
		std::cout << *pt << std::endl;
	}
	++count;
}
//-------------------------------------------------------------------------------------------------