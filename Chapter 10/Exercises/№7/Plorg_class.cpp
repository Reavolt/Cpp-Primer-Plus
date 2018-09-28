//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cstring>
#include "Plorg_class.h"

//-------------------------------------------------------------------------------------------------
Plorg::Plorg(const char* name, int index) 
{
	strcpy(name_plorg, name);
	ci = index;
}
//-------------------------------------------------------------------------------------------------
void Plorg::change_ci(char action, int index) 
{
	switch (action)
	{
	case '+':
		ci += index;
		break;
	case '-':
		ci -= index;
		break;
	default:
		std::cout << "You can only use \"+\" or \"-\"" << std::endl;
		break;
	}
}
//-------------------------------------------------------------------------------------------------
void Plorg::show_data() const 
{
	std::cout << "Plorg name: " << name_plorg << std::endl;
	std::cout << "CI (contentment index): " << ci << std::endl;
}
//-------------------------------------------------------------------------------------------------