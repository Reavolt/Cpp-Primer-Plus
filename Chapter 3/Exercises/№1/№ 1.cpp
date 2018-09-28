//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	const int Foot_inch = 12;	 //1 фут = 12 дюймов
	const double Inch_sm = 2.54; //1 дюйм = 2.54 сантиметра

	int Growth = 0;
	std::cout << "Enter your height in centimeters: ___\b\b\b";
	std::cin >> Growth;

	//Рост в дюймах
	double Growth_inch = Growth / Inch_sm;
	std::cout << "Height in inches: " << Growth_inch << std::endl;

	//Преобразование в футы и дюймы
	int f = Growth_inch / Foot_inch;
	int d = (int)Growth_inch % Foot_inch;
	std::cout << "Your height: " << f << " foot " << d << " inch" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
