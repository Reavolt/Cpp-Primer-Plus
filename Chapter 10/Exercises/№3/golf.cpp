//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "golf_class.h"  

//-------------------------------------------------------------------------------------------------
int main()
{
	Golf ann;
	ann = Golf("Ann Birdfree", 24);
	ann.show_golf();

	std::cout << "Enter the number of players: ";
	int col_players = 0;
	(std::cin >> col_players).get();
	std::cout << std::endl;
	
	Golf* players = new Golf[col_players];

	for (size_t i = 0; i < col_players; i++)
	{
		if (players[i].set_golf() == 0)
		{
			break;
		}
	}

	for (size_t i = 0; i < col_players; i++)
	{
		players[i].show_golf();
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------