//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "List.h"

//-------------------------------------------------------------------------------------------------
void some_func1(std::string& str);
void some_func2(std::string& str);
//-------------------------------------------------------------------------------------------------
int main()
{
	List Game = List();

	std::string games[MAX] = 
	{
		"Dota 2",
		"CS:GO",
		"PRAY",
		"ArcheAge",
		"Loong online"
	};

	if (Game.isempty())	
	{
		std::cout << "===================" << std::endl;

		for (size_t i = 0; i < MAX; i++)
		{
			Game.add_element(games[i]);
		}
	}
	else 
	if (Game.isfull())
	{
		std::cout << "The list is full" << std::endl;
	}

	Game.show_list();
	std::cout << "===================" << std::endl;
	Game.visit_element(some_func1);
	Game.show_list();
	std::cout << "===================" << std::endl;
	Game.visit_element(some_func2);
	Game.show_list();
	Game.reset_list();

	std::cout << "===================" << std::endl;
	Game.~List();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void some_func1(std::string& str)
{
	int size = str.size();
	for (int i = 0; i < size; ++i)
	{
		 str[i] = toupper(str[i]);
	}
}
//-------------------------------------------------------------------------------------------------
void some_func2(std::string& str)
{
	int size = str.size();
	for (int i = 0; i < size; ++i)
	{
		str[i] = tolower(str[i]);
	}
}
//-------------------------------------------------------------------------------------------------