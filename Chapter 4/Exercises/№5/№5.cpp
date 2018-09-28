//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
struct CandyBar 
{
	std::string candy_name;
	float weight;
	int сalories;
};
//-------------------------------------------------------------------------------------------------
int main() 
{
	CandyBar snack;
	snack.candy_name = "Mocha Munch";
	snack.weight = 2.3;
	snack.сalories = 350;

	std::cout << "Name: " << snack.candy_name << std::endl;
	std::cout << "Weight: " << snack.weight << std::endl;
	std::cout << "Calories: " << snack.сalories << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------