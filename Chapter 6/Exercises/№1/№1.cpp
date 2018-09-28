//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cctype>

//------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Type the text: (@ means the end of the line)" << std::endl;
	char ch;
	std::cin.get(ch);

	while (ch != '@')
	{
		if (isalpha(ch))
		{
			if (islower(ch))
			{
				std::cout << char(toupper(ch));
			}
			else
			{
				std::cout << char(tolower(ch));
			}
		}
		std::cin.get(ch);
	}
	std::cout << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------