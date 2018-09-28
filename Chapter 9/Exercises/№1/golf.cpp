//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "golf.h"

//-------------------------------------------------------------------------------------------------
void setgolf(golf & g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}
//-------------------------------------------------------------------------------------------------
int setgolf(golf & g)
{
	int name_valid = 0;

	std::cout << "Enter the name of the player: " << std::endl;
	std::cin.get(g.fullname, Len);

	if (strlen(g.fullname) > 0) 
	{
		name_valid = 1;

		std::cout << "Enter the player's handicap: " << std::endl;
		(std::cin >> g.handicap).get();
	}
	return name_valid;
}
//-------------------------------------------------------------------------------------------------
void handicap(golf & g, int hc)
{
	std::cout << "Enter a new player's handicap: ";
	(std::cin >> g.handicap).get();
}
//-------------------------------------------------------------------------------------------------
void showgolf(const golf & g)
{
	std::cout << "Player name: " << g.fullname << std::endl;
	std::cout << "Handicap player: " << g.handicap << std::endl;
}
//-------------------------------------------------------------------------------------------------