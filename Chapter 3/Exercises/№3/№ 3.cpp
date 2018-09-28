//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	const int Minutes = 60;			  //В 1 минуте 60 угловых секунд
	const int Degrees = Minutes * 60; // В 1 градусе 60 угловых минут

	std::cout << "Enter a latitude in degrees, minutes, and seconds: " << std::endl;

	std::cout << "First, enter the degrees:__\b\b ";
	int degrees = 0;
	std::cin >> degrees;

	std::cout << "Next, enter the minutes of arc:__\b\b ";
	int minutes = 0;
	std::cin >> minutes;

	std::cout << "Finally, enter the seconds of arc:__\b\b ";
	int seconds = 0;
	std::cin >> seconds;

	double Result = degrees + (minutes / 60.0) + (seconds / 3600.0);
	std::cout << degrees << " degrees, " << minutes << " minutes, ";
	std::cout << seconds << " seconds = " << Result << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
