//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "golf_class.h"  

//-------------------------------------------------------------------------------------------------
Golf::Golf() 
{
	strcpy(fullname, "None");
	handicap = 0;
}
//-------------------------------------------------------------------------------------------------
Golf::Golf(const char* name, int hc) 
{
	strcpy(fullname, name);
	handicap = hc;
}
//-------------------------------------------------------------------------------------------------
Golf::~Golf() 
{
	//The body of the destructor
}
//-------------------------------------------------------------------------------------------------
int Golf::set_golf() 
{
	int name_valid = 0;

	std::cout << "Enter the player's name: ";
	std::cin.get(fullname, Len);

	if (strlen(fullname) > 0) 
	{
		name_valid = 1;
		std::cout << "Enter the player's handicap: " << std::endl;
		(std::cin >> handicap).get();
		Golf temp(fullname, handicap);
		*this = temp;
	}
	return name_valid;
}
//-------------------------------------------------------------------------------------------------
void Golf::show_golf()
{
	std::cout << "Player name: " << fullname << std::endl;
	std::cout << "Player Handicap: " << handicap << std::endl;
}
//-------------------------------------------------------------------------------------------------