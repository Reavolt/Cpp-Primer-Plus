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
	CandyBar snack[3] = {};

	snack[0].candy_name = "Mocha Munch";
	snack[0].weight = 1.1;
	snack[0].сalories = 350;

	snack[1].candy_name = "Mocha Munch1";
	snack[1].weight = 2.2;
	snack[1].сalories = 350;

	snack[2].candy_name = "Mocha Munch2";
	snack[2].weight = 3.3;
	snack[2].сalories = 350;

	std::cout << "Name: " << snack[0].candy_name << std::endl;
	std::cout << "Weight: " << snack[0].weight << std::endl;
	std::cout << "Calories: " << snack[0].сalories << std::endl;

	std::cout << std::endl;

	std::cout << "Name: " << snack[1].candy_name << std::endl;
	std::cout << "Weight: " << snack[1].weight << std::endl;
	std::cout << "Calories: " << snack[1].сalories << std::endl;

	std::cout << std::endl;

	std::cout << "Name: " << snack[2].candy_name << std::endl;
	std::cout << "Weight: " << snack[2].weight << std::endl;
	std::cout << "Calories: " << snack[2].сalories << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------