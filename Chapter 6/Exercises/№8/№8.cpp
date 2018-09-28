//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <fstream>

//------------------------------------------------------------------------------------------------
int main()
{
	std::ifstream finput;
	finput.open("№8.txt");

	char word;
	finput >> word;

	int word_count = 0;

	while (finput.good())
	{
		word_count++;
		finput >> word;
	}

	if (finput.eof())
	{
		// достигнут конец файла
		std::cout << "End of file reached.\n";
	}
	else
		if (finput.fail())
		{
			// ввод прекращен из-за несоответствия типа данных
			std::cout << "Input terminated by data mismatch.\n";
		}
		else
			if (word_count == 0)
			{
				// данные для обработки отсутствуют 
				std::cout << "No data processed.\n";
			}
			else
			{
				std::cout << "Number of characters in the file: " << word_count << std::endl;
			}

	finput.close();

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------