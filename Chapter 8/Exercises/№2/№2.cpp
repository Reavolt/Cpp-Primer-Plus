//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
struct CandyBar
{
	std::string CandeName;
	double weight;
	double calories;
};
//-------------------------------------------------------------------------------------------------
void fill_struct(CandyBar & Munch, char* name = "Millennium Munch", 
				 double weight = 2.85, int calories = 350);
void Display_struct(const CandyBar & Munch);
//-------------------------------------------------------------------------------------------------
int main()
{
	CandyBar box_1;
	CandyBar box_2;
	CandyBar box_3;

	fill_struct(box_1);
	Display_struct(box_1);

	fill_struct(box_2, "KitKat", 11.5, 400);
	Display_struct(box_2);

	fill_struct(box_3, "Pocky", 7.3, 210);
	Display_struct(box_3);

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
void fill_struct(CandyBar & Munch, char* name, double weight, int calories)
{
	Munch.CandeName = name;
	Munch.weight = weight;
	Munch.calories = calories;
}
//-------------------------------------------------------------------------------------------------
void Display_struct(const CandyBar & Munch)
{
	std::cout << "Name: ";
	std::cout << Munch.CandeName << std::endl;
	std::cout << "Weight: ";
	std::cout << Munch.weight << std::endl;
	std::cout << "Calories: ";
	std::cout << Munch.calories << std::endl;
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------