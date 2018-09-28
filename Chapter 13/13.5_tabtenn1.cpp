// tabtennl.cpp — методы простого базового класса 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "13.4_tabtenn1.h"

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
// Методы RatedPlayer 
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
	const string & In, bool ht) : TableTennisPlayer(fn, In, ht)
{
	rating = r;
}
//-------------------------------------------------------------------------------------------------
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
	: TableTennisPlayer(tp), rating(r)
{

}
//-------------------------------------------------------------------------------------------------