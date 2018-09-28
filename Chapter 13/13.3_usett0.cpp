//usettO.cpp — использование базового класса 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "13.1_tabtenn0.h" 

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << " : has a table.\n";
	else
		cout << " : hasn't a table.\n";
	player2.Name();
	if (player2.HasTable())
		cout << " : has a table";
	else
		cout << " : hasn't a table. \n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Blizzard, Chuck : has a table.
Boomdea, Tara : hasn't a table.
Для продолжения нажмите любую клавишу . . .
*/