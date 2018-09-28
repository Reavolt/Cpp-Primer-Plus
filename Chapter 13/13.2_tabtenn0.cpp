//tabtenn0.cpp -- методы простого базового класса 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "13.1_tabtenn0.h"

//-------------------------------------------------------------------------------------------------
TableTennisPlayer::TableTennisPlayer(const string & fn,
	const string & In, bool ht) : firstname(fn),
	lastname(In), hasTable(ht) 
{

}
//-------------------------------------------------------------------------------------------------
void TableTennisPlayer::Name() const
{
std::cout << lastname << ", " << firstname;
}
//-------------------------------------------------------------------------------------------------