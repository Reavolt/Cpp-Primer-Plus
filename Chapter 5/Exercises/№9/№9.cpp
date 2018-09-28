//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::string exit_word = "done";
	std::string word;
	int count = 0;

	std::cout << "Type in the words (to complete, enter the word done): " << std::endl;
	
	do
	{
		std::cin >> word;
		count++;
	} 
	while (word != exit_word);
	
	std::cout << "You entered " << count - 1 << " words." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------