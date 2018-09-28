//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>	

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter string: " << std::endl;
	std::cout << "Input will be read up until the first '$' character: ";
	
	char string;
	std::cin.get(string);
	
	int count = 0;
	while (string != '$')
	{
		count++;
		std::cin.get(string);
	}
	std::cin.putback(string);

	std::cout << "Number of characters per line: " << count << std::endl;
	std::cout << "The next character in the input buffer is ";
	std::cout << (char) std::cin.get() << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------