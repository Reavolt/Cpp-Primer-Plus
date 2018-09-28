//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "person.h"

const int SIZE = 4;
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::strchr;

	std::srand(std::time(nullptr));
	Person* pp[SIZE];

	for (int ct = 0; ct < SIZE; ct++)
	{
		std::cout << "Enter the person category:\n";
		std::cout << "p: person        g: gunslinger" << std::endl;
		std::cout << "k: poker player  b: bad dude" << std::endl;
		std::cout << "q: quit" << std::endl;
		std::cout << std::endl;
		
		char choice = 0;
		std::cin >> choice;
		std::cout << std::endl;
		
		while (std::strchr("pgkbq", choice) == NULL)
		{
			std::cout << "Please enter a p, g, k, b, or q: ";
			std::cin >> choice;
		}
		std::cin.get();
		
		if (choice == 'q')
		{
			break;
		}
		
		switch (choice)
		{
			case 'p':   pp[ct] = new Person;
				break;
			case 'g':   pp[ct] = new Gunslinger;
				break;
			case 'k':   pp[ct] = new PokerPlayer;
				break;
			case 'b': 	pp[ct] = new BadDude;
				break;
		}
		pp[ct]->Set();
		pp[ct]->Show();
		std::cout << "ct = " << ct << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Your selection:" << std::endl << std::endl;
	for (int i = 0; i < ct; i++)
	{
		pp[i]->Show();
		std::cout << std::endl;
		delete *(pp + i);
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------