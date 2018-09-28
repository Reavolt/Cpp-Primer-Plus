//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include "class.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	{
		std::cout << "Cow №1:\n";
		Cow Cow1;
		
		std::cout << "Cow №2:\n";
		Cow Cow2("Cow2", "HOBBY", 89);
		
		std::cout << "Cow №3:\n";
		Cow Cow3 = Cow2;
		
		std::cout << "Cow №4:\n";
		Cow Cow4;
		Cow4 = Cow2;


		std::cout << "---------------------" << std::endl;
		
		std::cout << "Cow №1:\n";
		Cow1.ShowCow();
		
		std::cout << "Cow №2:\n";
		Cow2.ShowCow();
		
		std::cout << "Cow №3:\n";
		Cow3.ShowCow();
		
		std::cout << "Cow №4:\n";
		Cow4.ShowCow();
		
		std::cout << "---------------------" << std::endl;
		std::cout << "End!\n";
	}
	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------