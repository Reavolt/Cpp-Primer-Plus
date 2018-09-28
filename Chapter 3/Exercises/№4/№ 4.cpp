//#include "stdafx.h" --- Visual Studio --- precompiled headers
#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	const int Day = 24;
	const int Hour = 60;
	const int Minute = 60;

	long long int enter_seconds = 0;
	std::cout << "Enter the number of seconds: ________\b\b\b\b\b\b\b\b";
	std::cin >> enter_seconds;

	int seconds = enter_seconds % Minute;
	int minutes = enter_seconds / Minute % Hour;
	int hours = enter_seconds / 3600 % Minute;
	int days = enter_seconds / Minute / Hour / Day;

	std::cout << "31600000 seconds = " << days << " days, ";
	std::cout << hours << " hours, " << minutes << " minutes, ";
	std::cout << seconds << " seconds" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
