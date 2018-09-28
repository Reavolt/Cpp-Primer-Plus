// filel.срр -- пример программы, состоящей из трех файлов 
//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include "coordin.h" // шаблоны структур, прототипы функций 

//-------------------------------------------------------------------------------------------------
int main()
{
	rect rplace;
	polar pplace;
	std::cout << "Enter the x and у values: "; // ввод значений х и у 
	while (std::cin >> rplace.x >> rplace.y)   // ловкое использование сіп 
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		std::cout << "Next two numbers (q to quit): ";
		// ввод следующих двух чисел (q для завершения) 
	}
	std::cout << "Done.\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
/*
Enter the x and у values: 120 80
distance = 144.222, angle = 33.6901 degrees
Next two numbers (q to quit) : 120 50
distance = 130, angle = 22.6199 degrees
Next two numbers (q to quit) : q
Done.
*/