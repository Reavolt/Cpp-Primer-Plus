//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cctype>

//------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Please enter one of the following choices: " << std::endl;
	std::cout << "c) carnivore p) pianist" << std::endl << "t) tree g) game" << std::endl;
	char enter;

	while (std::cin >> enter)
	{
		switch (enter)
		{
		case 'c':
		case 'C':
			std::cout << "Your choise с, this is a lenth of your word: " << strlen("carnivore") << std::endl;
			break;
		case 'p':
		case 'P':
			std::cout << "Your choise p, this is a lenth of your word: " << strlen("pianist") << std::endl;
			break;
		case 'T':
		case 't':
			std::cout << "Your choise t, this is a lenth of your word: " << strlen("tree") << std::endl;
			break;
		case 'g':
		case 'G':
			std::cout << "Your choise g, this is a lenth of your word: " << strlen("game") << std::endl;
			break;
		default:
			std::cout << "Please enter a c, p, t, or g: ";
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//------------------------------------------------------------------------------------------------