//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "Plorg_class.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	Plorg Girl;
	Girl.show_data();

	Plorg Man = Plorg("Hann", 300);
	Man.show_data();

	Man.change_ci('-', 125);
	Man.show_data();

	Man.change_ci('+', 200);
	Man.show_data();

	Man.change_ci('|', 200);
	Man.show_data();

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------