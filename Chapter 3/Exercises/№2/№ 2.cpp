//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	const double Inch_sm = 2.54;	 //1 дюйм = 2.54 сантиметра
	const double Foot_inch = 12.0;	 //1 фут = 12 дюймов
	const double Inch_metr = 0.0254; // 1 дюйм = 0, 0254 метра

	int height_foot = 0;
	std::cout << "How many foot are in you: ___\b\b\b";
	std::cin >> height_foot;

	int height_inch = 0;
	std::cout << "How many inches are in you: __\b\b";
	std::cin >> height_inch;

	int weight_and_pounds = 0;
	std::cout << "Enter your weight in pounds: ___\b\b\b";
	std::cin >> weight_and_pounds;

	//Перевод из футов в дюймы
	height_inch += height_foot * Foot_inch;

	//Рост из дюймов в метры
	double height_meters = height_inch * Inch_metr;

	//Вес в фунтах в киллограммы
	double weight_in_kilograms = weight_and_pounds / 2.2;

	//Расчет BMI(body mass index)
	double bmi = weight_in_kilograms / pow(height_meters, 2);

	std::cout << "BMI = " << bmi << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
