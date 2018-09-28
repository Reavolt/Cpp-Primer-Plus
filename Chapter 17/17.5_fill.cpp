//fill.срр -- изменение символа-заполнителя полей 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	cout.fill('*');
	const char * staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper" };
	long bonus[2] = { 900, 1350 };

	for (int i = 0; i < 2; i++)
	{
		cout << staff[i] << ": $";
		cout.width(7);
		cout << bonus[i] << "\n";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Waldo Whipsnade: $****900
Wilmarie Wooper: $***1350
*/