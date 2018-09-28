//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main() 
{
	std::string name;
	std::cout << "Enter your name: "; // запрос имени 
	std::cin >> name;

	std::string dessert;
	std::cout << "Enter your favorite dessert: "; // запрос любимого десерта 
	std::cin >> dessert;

	std::cout << "I have some delicious " << dessert;
	std::cout << " for you, " << name << " .\n";

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------